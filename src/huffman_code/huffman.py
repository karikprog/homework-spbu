import heapq
from collections import Counter
import struct


class HuffmanNode:
    """Node for Huffman tree"""

    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq


def build_huffman_tree(data: str) -> HuffmanNode:
    if not data:
        return None

    value_count = Counter(data)
    priority_queue = [HuffmanNode(char, freq) for char, freq in value_count.items()]
    heapq.heapify(priority_queue)

    while len(priority_queue) > 1:
        node1 = heapq.heappop(priority_queue)
        node2 = heapq.heappop(priority_queue)

        merged_freq = node1.freq + node2.freq
        merged_node = HuffmanNode(None, merged_freq)
        merged_node.left = node1
        merged_node.right = node2

        heapq.heappush(priority_queue, merged_node)

    return priority_queue[0]


def generate_huffman_codes(root: HuffmanNode):
    codes = {}

    def traverse(node, current_code):
        if node is None:
            return

        if node.char is not None:
            codes[node.char] = current_code
            return

        traverse(node.left, current_code + "0")

        traverse(node.right, current_code + "1")

    traverse(root, "")
    return codes


def encode(msg: str) -> tuple[str, dict[str, str]]:
    if not msg:
        return ("", None)

    root = build_huffman_tree(msg)
    codes = generate_huffman_codes(root)
    result = ""
    for v in msg:
        result += codes[v]
    return (result, codes)


def decode(encoded: str, table: dict[str, str]) -> str:
    result = ""
    char = ""
    encoded_dict = {table[k]: k for k in table.keys()}
    for v in encoded:
        char += v
        if char in encoded_dict:
            result += encoded_dict[char]
            char = ""

    return result


def huffman_compress(input_filepath, output_filepath):
    with open(input_filepath, "rb") as f_in:
        data = f_in.read()

    if not data:
        print("Input file is empty")
        return

    root = build_huffman_tree(data)
    codes = generate_huffman_codes(root)
    frequency = Counter(data)

    bit_string = "".join(codes[byte] for byte in data)

    padding_bits = 8 - (len(bit_string) % 8)
    if padding_bits == 8:
        padding_bits = 0

    bit_string += "0" * padding_bits

    with open(output_filepath, "wb") as f_out:
        f_out.write(struct.pack("<I", len(frequency)))

        f_out.write(struct.pack("<B", padding_bits))

        for byte, freq in frequency.items():
            f_out.write(struct.pack("<B", byte))
            f_out.write(struct.pack("<I", freq))

        byte_array = bytearray()
        for i in range(0, len(bit_string), 8):
            byte_segment = bit_string[i : i + 8]

            byte_array.append(int(byte_segment, 2))

        f_out.write(byte_array)

    print(
        f"File successfully compressed. Original size: {len(data)} bytes, Compressed size: {len(byte_array) + len(frequency) * 5 + 5} bytes."
    )


def huffman_decompress(input_filepath, output_filepath):
    with open(input_filepath, "rb") as f_in:
        num_unique_chars_packed = f_in.read(4)
        num_unique_chars = struct.unpack("<I", num_unique_chars_packed)[0]

        padding_packed = f_in.read(1)
        padding_bits = struct.unpack("<B", padding_packed)[0]

        frequency = {}
        for _ in range(num_unique_chars):
            byte = struct.unpack("<B", f_in.read(1))[0]
            freq = struct.unpack("<I", f_in.read(4))[0]
            frequency[byte] = freq

        priority_queue = [HuffmanNode(char, freq) for char, freq in frequency.items()]
        heapq.heapify(priority_queue)

        while len(priority_queue) > 1:
            node1 = heapq.heappop(priority_queue)
            node2 = heapq.heappop(priority_queue)
            merged_node = HuffmanNode(None, node1.freq + node2.freq)
            merged_node.left = node1
            merged_node.right = node2
            heapq.heappush(priority_queue, merged_node)

        root = priority_queue[0]

        encoded_data_bytes = f_in.read()

        bit_string = ""
        for i, byte in enumerate(encoded_data_bytes):
            bit_segment = format(byte, "08b")
            bit_string += bit_segment

        if padding_bits > 0:
            bit_string = bit_string[:-padding_bits]

        decoded_bytes = bytearray()
        current_node = root

        for bit in bit_string:
            if bit == "0":
                current_node = current_node.left
            else:
                current_node = current_node.right

            if current_node.char is not None:
                decoded_bytes.append(current_node.char)
                current_node = root

        with open(output_filepath, "wb") as f_out:
            f_out.write(decoded_bytes)

        print(f"File successfully decrypted. Decoded size: {len(decoded_bytes)} bytes.")


huffman_compress("src/huffman_code/inp_data.txt", "src/huffman_code/out.txt")
huffman_decompress("src/huffman_code/out.txt", "src/huffman_code/decoded.txt")
