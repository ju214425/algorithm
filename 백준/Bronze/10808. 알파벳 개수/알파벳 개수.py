from collections import Counter as C

a = input()

d = 'abcdefghijklmnopqrstuvwxyz'

for c in d:
    if C(a)[c] != 0:
        print(C(a)[c], end = ' ')
    else:
        print('0', end = ' ')