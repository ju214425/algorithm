number_of_subject = input()
number_of_subject = int(number_of_subject)
maximum = summation = 0
subject_list = []
for i in range(number_of_subject):
	number = input()
	number = int(number)
	subject_list.append(number)
	if maximum < number:
		maximum = number

for value in subject_list:
	value = (value / maximum) * 100
	summation = summation + value

print(summation / len(subject_list))
