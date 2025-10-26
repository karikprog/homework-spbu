def curry(func, n: int):
    def _carried(*args):
        if len(args) > n:
            raise TypeError("invalid amount argument")
        elif len(args) == n:
            return func(*args)
        return lambda *x: _carried(*args, *x)

    return _carried


def uncurry(func, n: int):
    def _uncurried(*args):
        if len(args) != n:
            raise TypeError("invalid amount argument")
        result = func
        for arg in args:
            result = result(arg)
        return result

    return _uncurried


def sum_nums(x, y, z):
    return x * y * z


carry_sum = curry(sum_nums, 3)
uncurry_sum = uncurry(carry_sum, 3)
print(carry_sum(1)(3)(9))
print(uncurry_sum(10, 3, 4))
