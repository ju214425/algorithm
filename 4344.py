number_of_testcase = input()
number_of_testcase = int(number_of_testcase)
people_list = []
percentage_list = []
for i in range(number_of_testcase):
	summation = 0
	good_student = 0
	number_of_people = input()
	number_of_people = int(number_of_people)
	for j in range(number_of_people):
		score = input()
		score = int(score)
		summation = summation + score
		people_list.append(score)
	avg = summation / number_of_people
	for j in range(number_of_people):
		if people_list[j] > avg:
			good_student = good_student + 1

	percentage_list.append(good_student/number_of_people*100)

for value in percentage_list:
	print(str(value) + "%")