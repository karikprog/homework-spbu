from itertools import permutations


def get_permutation_queen(n: int) -> int:
    c = 0
    for perm in permutations(range(n)):
        fl = True
        for i in range(n):
            for j in range(i):
                if not (abs(perm[i] - perm[j]) != abs(i - j)):
                    fl = False
                    break
        if fl:
            c += 1

    return c


print(get_permutation_queen(5))
