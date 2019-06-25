#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int numberOfPeople;
	cin >> numberOfPeople;
	int arr[numberOfPeople + 1];
	int ans[numberOfPeople + 1];
	arr[0] = 0;
	int sum = 0;
	for(int i = 1 ; i <= numberOfPeople ; i++){
		cin >> arr[i];
		ans[i] = 0;
	}
	sort(arr,arr + numberOfPeople + 1);
	for(int i = 1 ; i <= numberOfPeople ; i++){
		for(int j = 1 ; j <= i ; j++){
			ans[i] += arr[j];
		}
	}
	for(int i = 1 ; i <= numberOfPeople ; i++){
		sum += ans[i];
	}

	cout << sum << endl;

	return 0;
}