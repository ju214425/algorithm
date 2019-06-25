number_of_testcase = input()
number_of_testcase = int(number_of_testcase)
list_testcase = []
count = 0
soom = 0


for i in range(number_of_testcase):
	temp = input()
	list_testcase.append(temp)

for quiz in list_testcase:
	for i in quiz:
		if i == 'O':
			count += 1
			soom += count
		else:
			count = 0
	
	print(soom)
	count = 0
	soom = 0
