#include <iostream>

using namespace std;

int main(){
	int n, cnt = 1;
	int number = 0;
	cin >> n;

	while(cnt <= n){
		number++;
		int check = 0;
		int temp = number;
		while(temp != 0){
			if(temp % 10 == 6) check++;
			else check = 0;
			temp /= 10;
			if(check == 3){
				cnt++;
				break;
			}
		}
	}

	cout << number;
}