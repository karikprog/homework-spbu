def heapify(values: list, n: int, i: int):
    parent = i
    right = i * 2 + 1
    left = i * 2 + 2

    if right < n and values[parent] < values[right]:
        parent = right

    if left < n and values[parent] < values[left]:
        parent = left

    if parent != i:
        values[i], values[parent] = values[parent], values[i]
        heapify(values, n, parent)


def heap_sort(values: int):
    n = len(values)
    for i in range(n, -1, -1):
        heapify(values, n, i)

    for i in range(n - 1, 0, -1):
        values[i], values[0] = values[0], values[i]
        heapify(values, i, 0)

    return values
