#include <iostream>

using namespace std;

int main(){
	double number_of_subject, max = 0, sum = 0;
	double arr[1005], brr[1005];

	cin >> number_of_subject;
	for(int i = 0 ; i < number_of_subject ; i++){
		cin >> arr[i];
		if(arr[i] > max) max = arr[i];
	}

	for(int i = 0 ; i < number_of_subject ; i++){
		brr[i] = (arr[i]/max)*100;		
		sum += brr[i];
	}
	cout << (sum / number_of_subject);

	return 0;
}