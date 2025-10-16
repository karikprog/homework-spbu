from heap_sort import heap_sort
from other_sort import merge_sort, quick_sort


class TestUnitSort:
    def test_heap_sort_algorithm(self):
        data = [3, 4, 1, 2]
        assert heap_sort(data) == [1, 2, 3, 4]

    def test_heap_sort_empty(self):
        assert heap_sort([]) == []

    def test_heap_sort_reverse(self):
        data = [99, 88, 77, 66, 44, 33, 2, 1]
        assert heap_sort(data) == [1, 2, 33, 44, 66, 77, 88, 99]

    def test_heap_sort_singl_value(self):
        assert heap_sort([6]) == [6]

    def test_heap_sort_already_sorted(self):
        data = [3, 5, 6, 7, 8, 13, 55]
        assert heap_sort(data) == [3, 5, 6, 7, 8, 13, 55]

    def test_heap_sort_duplicate_elements(self):
        data = [77, 50, 50, 4, 4, 5, 5, 8, 9]
        assert heap_sort(data) == [4, 4, 5, 5, 8, 9, 50, 50, 77]

    def test_heap_sort_negative(self):
        data = [-1, -5, -7, -9, -4]
        assert heap_sort(data) == [-9, -7, -5, -4, -1]


class TestProperty:
    def test_heap_sort_result_length(self):
        values = [3, 4, 5, 6, 2, 1, -1]
        lenght = len(values)
        assert len(heap_sort(values)) == lenght

    def test_heap_sort_ordered_output(self):
        result = heap_sort([6, 5, 4, 3, 2, 1, 8, 9, 7, 345, 55])
        for i in range(1, len(result) - 1):
            assert result[i - 1] < result[i]

    def test_heap_sort_other_sort(self):
        values = [9, 8, 7, 6, 5, 4, 3, 2, 1]
        assert heap_sort(values) == quick_sort(values)
        assert heap_sort(values) == merge_sort(values)

    def test_heap_sort_elements(self):
        values = [9, 8, 7, 6, 5, 4, 3, 2, 1]
        assert set(heap_sort(values)) == set(values)
