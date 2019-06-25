#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int numberOfIntegers;
	cin >> numberOfIntegers;
	int arr[numberOfIntegers];
	for(int i = 0 ; i < numberOfIntegers ; i++){
		cin >> arr[i];
	}
	sort(arr,arr + numberOfIntegers + 1);
	for(int i = 0 ; i < numberOfIntegers ; i++){
		cout << arr[i] << endl;
	}

	return 0;
}