lista_de_codigo = []
lista_de_posi = []
while True:
    entrada = input().split()
    if entrada == ["0", "0"]:
        break
    codigo = ""
    codigo += entrada[0]
    posi = ""
    posi += entrada[1]

# CODIGO PARA CALCULAR O PR?XIMO PRIMO
    count = 0
    primos = 0
    rodada = 0
    primo = 0
    numero = int(entrada[0])

    while True:
        rodada += 1

        for i in range(1, numero + 1):
            if numero % i == 0:
                count += 1
        if count == 2 and rodada != 1:
            primos += numero
            primo += primos
            break
        else:
            numero += 1
            count = 0

# CALCULO DO NOVO CODIGO

    soma = 0
    for i in codigo:
        soma += int(i)
    novo_codigo = (int(entrada[0]) + primos) // soma


# CALCULO DA POSI??O

    soma_dos_divisores = 0

    for i in range(1, int(entrada[0])):
        if i % 6 == 0:
            soma_dos_divisores += i
    if soma_dos_divisores > int(entrada[1]):
        nova_posi = soma_dos_divisores - int(entrada[1])
    else:
        nova_posi = int(entrada[1]) - soma_dos_divisores

    while True:
        for b in lista_de_codigo:
            if b == novo_codigo:
                novo_codigo += 1
        if novo_codigo not in lista_de_codigo:
            break

    while True:
        for d in lista_de_posi:
            if d == nova_posi:
                nova_posi += 1
        if nova_posi not in lista_de_posi:
            break

    lista_de_codigo.append(novo_codigo)
    lista_de_posi.append(nova_posi)

lista_de_posi.reverse()
lista_de_codigo.reverse()

for y in range(len(lista_de_posi)):
    print("{} - {}".format(lista_de_codigo[y], lista_de_posi[y]))