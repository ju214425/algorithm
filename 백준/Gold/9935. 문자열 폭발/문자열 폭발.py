s = input()
b = input()

stack = []

for c in s:
    stack.append(c)
    if len(stack) >= len(b):
        if ''.join(stack[-len(b):]) == b:
            for i in range(len(b)):
                stack.pop() 

print('FRULA' if len(stack) == 0 else ''.join(stack))