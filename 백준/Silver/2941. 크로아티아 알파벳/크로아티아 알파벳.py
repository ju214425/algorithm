n = input()

l = 'c= c- dz= d- lj nj s= z='.split()
m = n
for item in l:
    m = m.replace(item, '0')

print(len(m))