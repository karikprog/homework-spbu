
def extended_gcd(num1, num2):
    s0, t0 = 0, 0
    s1, t1 = 1, 1
    while num2 != 0:
        q = num1 // num2
        num1, num2, = num2, num1 % num2
        s1, s0 = s0, s1 - q * s0
        t0, t1 = t1, t0 - q * t1

    return (abs(num1), s0, t1)

print(extended_gcd(240, 46))



