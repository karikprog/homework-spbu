from itertools import combinations


def get_permutation_queen(n: int) -> int:
    board_points = [(x, y) for x in range(1, n + 1) for y in range(1, n + 1)]
    count_comb = 0

    for points in combinations(board_points, r=n):
        ox = set()
        oy = set()
        main_diagonal = False
        row_column = set()
        post_diag = set()
        fl = True
        for x, y in points:
            if (
                (x not in ox)
                and (y not in oy)
                and ((x + y) not in row_column)
                and (x - y) not in post_diag
            ):
                # если главная диагональ не занята
                if x == y and not (main_diagonal):
                    main_diagonal = True
                elif x == y and main_diagonal:
                    fl = False
                    break

                ox.add(x)
                oy.add(y)
                row_column.add(x + y)
                post_diag.add(x - y)
            else:
                fl = False
                break
        if fl:
            count_comb += 1
    return count_comb


print(get_permutation_queen(5))
