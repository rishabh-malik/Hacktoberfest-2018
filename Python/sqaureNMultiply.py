def squareNMultiply(base,exp,mod):
    f = 1
    while exp > 0:
        i = exp%2
        f = (f*f) % mod
        if i == 1:
            f = (f*base) % mod
        exp = exp/2
    return f
