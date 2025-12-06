def get_permutation_queen(n):
    cols = set()
    diag1 = set()
    diag2 = set()
    count = 0

    def place(row):
        nonlocal count
        if row == n:
            count += 1
            return

        for col in range(n):
            if col in cols or (row - col) in diag1 or (row + col) in diag2:
                continue
            cols.add(col)
            diag1.add(row - col)
            diag2.add(row + col)
            place(row + 1)
            cols.remove(col)
            diag1.remove(row - col)
            diag2.remove(row + col)

    place(0)
    return count


print(get_permutation_queen(8))
