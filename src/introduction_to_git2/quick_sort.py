def quick_sort(values: list) -> list:
    if len(values) < 2:
        return values
    p = values[len(values) // 2]
    more_v = [el for el in values if el > p]
    middle = [el for el in values if el == p]
    less_v = [el for el in values if el < p]
    return quick_sort(less_v) + middle + quick_sort(more_v)


print(quick_sort([1, 123, 63, 4535353, 555, 345, 7, 7, 7, 7, 7, 5]))