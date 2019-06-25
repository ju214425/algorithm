string = input()
length = len(string)
while length > 0:
	length = length - 10
	print(string[0:10])
	string = string[10:]