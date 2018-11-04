# Love_Formula

def question(i):
  questions = ["The number of years you have known each other before starting a relationship:",
                "The number of previous partners that both of you had:",
                "On a five-point scale (from 1 'it does not matter at all' to 5 'very important') the importance that a man attaches to honesty in a relationship:",
                "On a five-point scale, what value does money give a woman in a relationship:",
                "On a five-point scale, what importance do both partners give to humor (enter the total amount):",
                "On a five-point scale, what importance do both partners (in total) give to external attractiveness:",
                "On a five-point scale, what importance do men attach to sex:",
                "On a five-point scale, what importance does a woman give to sex:",
                "On a five-point scale, what importance is attached to good relations with relatives (in total):",
                "On a five-point scale, what importance is attached to children (in total):"]
  for ask in questions:
    ask = (questions[i])
    i += 1
    return (ask)

def main():
  Y, P, Hm, Mf, J, G, Sm, Sf, I, C = [int(input(question(i))) for i in range (10)]
  L = 8 + 5 * Y - 2 * P + 9 * Hm + 3 * Mf + J - 3 * G - 5 * (Sm - Sf) * 2 + I + 1.5 * C
  print (f"Possible duration of relationship in years: {int(L)}")
  
  
main()  

# Origin: https://www.adme.ru/zhizn-semya/prostoj-sposob-uznat-kak-dolgo-prodlyatsya-vashi-otnosheniya-1560915/ © AdMe.ru))
# Powered by Alex Nash & PROTO-TECH. Thx for using ^^
