from itertools import combinations


def get_permutation_queen(n: int) -> int:
    """Функция определяет количество способов расставить n ферзей на поле n*n"""

    board_points = [(x, y) for x in range(1, n + 1) for y in range(1, n + 1)]
    count_comb = 0

    for points in combinations(board_points, r=n):
        used_x = set()
        used_y = set()
        main_diagonal = False
        row_column = set()
        post_diag = set()
        fl = True

        for x, y in points:
            if (
                (x not in used_x)
                and (y not in used_y)
                and ((x + y) not in row_column)
                and (x - y) not in post_diag
            ):
                if x == y and not (main_diagonal):
                    main_diagonal = True
                elif x == y and main_diagonal:
                    fl = False
                    break

                used_x.add(x)
                used_y.add(y)
                row_column.add(x + y)
                post_diag.add(x - y)
            else:
                fl = False
                break
        if fl:
            count_comb += 1
    return count_comb


print(get_permutation_queen(5))
