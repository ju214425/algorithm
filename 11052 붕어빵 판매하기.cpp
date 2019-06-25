#include <iostream>

using namespace std;

int main(){
	int numberOfBread;
	cin >> numberOfBread;
	int PriceArr[numberOfBread + 1];
	int AnswerArr[numberOfBread + 1];
	PriceArr[0] = 0;
	AnswerArr[0] = 0;
	for(int i = 1 ; i <= numberOfBread ; i++){
		cin >> PriceArr[i];
	}
	for(int i = 1 ; i <= numberOfBread ; i++){
		int maximum = 0;
		for(int j = 0 ; j < i ; j++){
			if(maximum < PriceArr[i-j] + AnswerArr[j]) 
				maximum = PriceArr[i-j] + AnswerArr[j];
		}
		AnswerArr[i] = maximum;
	}
	cout << AnswerArr[numberOfBread];

	return 0;
}