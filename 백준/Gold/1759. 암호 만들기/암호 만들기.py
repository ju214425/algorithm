from itertools import combinations as C

l, c = map(int, input().split())
arr = list(input().split())

vowel = ['a', 'e', 'i', 'o', 'u']
consonant = ['b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm'\
            'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z']

arr.sort()

for password in C(arr, l):
    vCount = 0
    cCount = 0
    
    for c in password:
        if c in vowel:
            vCount += 1
        else:
            cCount += 1
    
    if vCount >= 1 and cCount >= 2:
        print(''.join(password))