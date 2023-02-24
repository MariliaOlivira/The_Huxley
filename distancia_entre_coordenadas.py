def calculo():
    d = ((entrada[0]-entrada[2])**2 + (entrada[1]-entrada[3])**2)**0.5
    return d


repet = int(input())

for i in range(repet):
    entrada = list(map(int, input().split()))
    resultado = calculo()
    print("{:.2f}".format(resultado))
