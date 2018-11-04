import math

def getS(e,L):
    i = 0
    S = 0
    while i < L:
        if e[i] == 0:
            S -= 1
        else:
            S += 1
        i += 1
    return S

def getS_abs(S,L):
    return abs(S)/math.sqrt(L)

def getErfc(S_abs):
    return math.erfc( S_abs / math.sqrt(2) )

def run(e,L):
    S = getS(e,L)
    S_abs = getS_abs(S,L)
    P_value = getErfc(S_abs)

    if P_value < 0.01:
        print "Reprovado"
    else:
        print "Aprovado"

    return P_value
    
e = [0,1,1,1,1,0,0,1,1,0,1,0,0,0,1,0]
L = len(e)

run(e,L)
