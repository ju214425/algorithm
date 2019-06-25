#include <iostream>

using namespace std;

int main(){
	int numberOfCoins;
	int SummationOfCoins;
	cin >> numberOfCoins >> SummationOfCoins;
	int coinArr[numberOfCoins + 1];
	for(int i = 1 ; i <= numberOfCoins ; i++){
		cin >> coinArr[i];
	}
	int checkIndex = numberOfCoins;
	int result = 0;
	while(SummationOfCoins != 0){
		if(coinArr[checkIndex] > SummationOfCoins){
			checkIndex--;
		}
		else{
			SummationOfCoins -= coinArr[checkIndex];
			result++;
		}
	}

	cout << result;

	return 0;
}