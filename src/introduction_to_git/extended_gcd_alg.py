def extended_gcd(a, b):
    s0, s1 = 1, 0
    t0, t1 = 0, 1

    while b != 0:
        q = a // b
        a, b = b, a % b
        s0, s1 = s1, s0 - q * s1
        t0, t1 = t1, t0 - q * t1

    return a, s0, t0


print(extended_gcd(240, 46))
