#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int arr[10];
	int cnt = 1;
	for(int i = 0 ; i < 10 ; i++){
		cin >> arr[i];
		arr[i] %= 42;
	}
	sort(arr, arr + 10);
	for(int i = 1 ; i < 10 ; i++){
		if(arr[i] != arr[i-1]) cnt++;
	}

	cout << cnt;

	return 0;
}