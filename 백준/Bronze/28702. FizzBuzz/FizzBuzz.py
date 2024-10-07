a = input()
b = input()
c = input()

if a.isnumeric():
    answer = int(a) + 3
elif b.isnumeric():
    answer = int(b) + 2
else:
    answer = int(c) + 1

if answer % 3 == 0:
    if answer % 5 == 0:
        print('FizzBuzz')
    else:
        print('Fizz')
else:
    if answer % 5 == 0:
        print('Buzz')
    else:
        print(answer)
    
    