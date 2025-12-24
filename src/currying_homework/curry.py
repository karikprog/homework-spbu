def curry(func, n: int):
    if not (isinstance(n, int)):
        raise TypeError("Number not int")
    if n < 0:
        raise ValueError("Value must be non-negative")
    if n > func.__code__.co_argcount:
        raise ValueError("Arity exceeds functions argument")

    def _carried(*args):
        if len(args) > n:
            raise TypeError("invalid amount argument")
        elif len(args) == n:
            return func(*args)
        return lambda *x: _carried(*args, *x)

    return _carried


def uncurry(func, n: int):
    if not isinstance(n, int):
        raise TypeError("arity is't integer")
    if n < 0:
        raise ValueError("arity must be non-negative")

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


if __name__ == "__main__":
    carry_sum = curry(sum_nums, 3)
    uncurry_sum = uncurry(carry_sum, 3)
    print(carry_sum(1)(3)(9))
    print(uncurry_sum(10, 3, 4))
