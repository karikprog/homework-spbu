class BinomialNode:
    def __init__(self, key, value=None):
        self.key = key
        self.value = value
        self.degree = 0
        self.parent = None
        self.child = None
        self.sibling = None


class BinomialHeapPriorityQueue:
    def __init__(self):
        self.head = None
        self.size = 0

    def is_empty(self):
        return self.head is None

    def get_size(self):
        return self.size

    def _merge_trees(self, tree1, tree2):
        if tree1.key > tree2.key:
            tree1, tree2 = tree2, tree1

        tree2.parent = tree1
        tree2.sibling = tree1.child
        tree1.child = tree2
        tree1.degree += 1

        return tree1

    def _merge_heaps(self, heap1, heap2):
        if heap1 is None:
            return heap2
        if heap2 is None:
            return heap1

        if heap1.degree <= heap2.degree:
            head = heap1
            heap1 = heap1.sibling
        else:
            head = heap2
            heap2 = heap2.sibling

        current = head

        while heap1 is not None and heap2 is not None:
            if heap1.degree <= heap2.degree:
                current.sibling = heap1
                heap1 = heap1.sibling
            else:
                current.sibling = heap2
                heap2 = heap2.sibling
            current = current.sibling

        if heap1 is not None:
            current.sibling = heap1
        else:
            current.sibling = heap2

        return head

    def _union(self, other_head):
        self.head = self._merge_heaps(self.head, other_head)

        if self.head is None:
            return

        prev = None
        current = self.head
        next_node = current.sibling

        while next_node is not None:
            if current.degree != next_node.degree or (
                next_node.sibling is not None
                and next_node.sibling.degree == current.degree
            ):
                prev = current
                current = next_node
            else:
                if current.key <= next_node.key:
                    current.sibling = next_node.sibling
                    current = self._merge_trees(current, next_node)
                else:
                    if prev is None:
                        self.head = next_node
                    else:
                        prev.sibling = next_node
                    current = self._merge_trees(next_node, current)

            next_node = current.sibling

    def insert(self, key, value=None):
        new_node = BinomialNode(key, value)
        self._union(new_node)
        self.size += 1

    def get_min(self):
        if self.is_empty():
            raise IndexError("Очередь пуста")

        min_node = self.head
        current = self.head.sibling

        while current is not None:
            if current.key < min_node.key:
                min_node = current
            current = current.sibling

        return (min_node.key, min_node.value)

    def extract_min(self):
        if self.is_empty():
            raise IndexError("Очередь пуста")

        min_node = self.head
        min_node_prev = None

        current = self.head

        while current.sibling is not None:
            if current.sibling.key < min_node.key:
                min_node = current.sibling
                min_node_prev = current
            current = current.sibling

        if min_node == self.head:
            self.head = min_node.sibling
        else:
            min_node_prev.sibling = min_node.sibling

        new_head = None
        child = min_node.child

        while child is not None:
            next_child = child.sibling
            child.sibling = new_head
            child.parent = None
            new_head = child
            child = next_child

        self._union(new_head)
        self.size -= 1

        return (min_node.key, min_node.value)

    def decrease_key(self, node, new_key):
        if new_key > node.key:
            raise ValueError("Новый ключ больше текущего")

        node.key = new_key
        current = node
        parent = current.parent

        while parent is not None and current.key < parent.key:
            current.key, parent.key = parent.key, current.key
            current.value, parent.value = parent.value, current.value

            current = parent
            parent = current.parent

    def __str__(self):
        if self.is_empty():
            return "BinomialHeapPriorityQueue(empty)"

        trees = []
        current = self.head
        while current is not None:
            trees.append(f"B{current.degree}(key={current.key})")
            current = current.sibling

        return (
            f"BinomialHeapPriorityQueue(size={self.size}, trees=[{', '.join(trees)}])"
        )


if __name__ == "__main__":
    pq = BinomialHeapPriorityQueue()

    pq.insert(5, "пять")
    pq.insert(3, "три")
    pq.insert(7, "семь")
    pq.insert(1, "один")
    pq.insert(9, "девять")
    pq.insert(4, "четыре")
    pq.insert(2, "два")

    print(pq)
    print("Размер:", pq.get_size())

    print("\nМинимальный элемент:", pq.get_min())

    print("\nИзвлечение элементов в порядке приоритета:")
    while not pq.is_empty():
        key, value = pq.extract_min()
        print(f"  Извлечен: key={key}, value={value}")

    print("\nОчередь после извлечения всех элементов:", pq)
