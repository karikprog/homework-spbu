from priority_queue import BinomialHeapPriorityQueue


class TestHeap:
    def test_empty_heap(self):
        pq = BinomialHeapPriorityQueue()
        assert pq.is_empty()

    def test_size(self):
        pq = BinomialHeapPriorityQueue()

        pq.insert(5, "пять")
        pq.insert(3, "три")
        pq.insert(7, "семь")
        pq.insert(1, "один")
        pq.insert(9, "девять")
        pq.insert(4, "четыре")
        pq.insert(2, "два")
        assert pq.get_size() == 7

    def test_get_min(self):
        pq = BinomialHeapPriorityQueue()

        pq.insert(5, "пять")
        pq.insert(3, "три")
        pq.insert(7, "семь")
        pq.insert(1, "один")
        pq.insert(9, "девять")
        pq.insert(4, "четыре")
        pq.insert(2, "два")
        assert pq.get_min() == (1, "один")

    def test_extract_min(self):
        pq = BinomialHeapPriorityQueue()

        pq.insert(5, "пять")
        pq.insert(3, "три")
        pq.insert(7, "семь")
        pq.insert(1, "один")
        pq.insert(9, "девять")
        pq.insert(4, "четыре")
        pq.insert(2, "два")

        result = []
        agree_result = [
            (1, "один"),
            (2, "два"),
            (3, "три"),
            (4, "четыре"),
            (5, "пять"),
            (7, "семь"),
            (9, "девять"),
        ]
        while not pq.is_empty():
            result.append(pq.extract_min())
        assert result == agree_result
