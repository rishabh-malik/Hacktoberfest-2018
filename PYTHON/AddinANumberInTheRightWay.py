valores = []

for cont in range(0, 5):
    novo_valor = int(input('Digite um valor: '))
    if cont == 0 or novo_valor > valores[-1]:
        valores.append(novo_valor)
        print('Adicionando ao final da lista...')
    else:
        for c, v in enumerate(valores):
            if novo_valor <= v:
                valores.insert(c, novo_valor)
                print(f'Adicionando na posição {c}...')
                break

print('-'*10)
print(f'Os valores digitados, em ordem são {valores}')
