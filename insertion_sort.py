list = [5,2,4,6,1,3]

for x in range(1, len(list)):
    chave = list[x]
    i = x - 1
    while i >= 0 and list[i] > chave:
        list[i + 1] = list[i]
        i -= 1
    list[i + 1] = chave

print(list)
