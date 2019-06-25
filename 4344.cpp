#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	int number_of_testcase = 0, arr[1005], good_student[1005] = {0,}, sum = 0, number_of_people[1005] = {0, };
	double avg = 0.0, percentage[1005] = {0.0, };
	cin >> number_of_testcase;
	for(int i = 0 ; i < number_of_testcase ; i++){
		avg = 0.0, sum = 0;
		cin >> number_of_people[i];
		for(int j = 0 ; j < number_of_people[i] ; j++){
			cin >> arr[j];
			sum += arr[j];
		}
		avg = sum / number_of_people[i];
		for(int j = 0 ; j < number_of_people[i] ; j++){
			if(arr[j] > avg) good_student[i]++;
		}
		percentage[i] = (double)good_student[i] / (double)number_of_people[i];
	}
	for(int i = 0 ; i < number_of_testcase; i++){
		printf("%.3f%%\n", percentage[i] * 100);
	
	}

	return 0;
}