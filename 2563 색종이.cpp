#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[105][105];

int main(){
	int n;
	int sum = 0;
	cin >> n;

	for(int k = 0 ; k < n ; k++){
		int a, b;
		cin >> a >> b;

		for(int i = 0 ; i < 10 ; i++){
			for(int j = 0 ; j < 10 ; j++){
				map[a+i][b+j] = 1;
			}
		}
	}

	for(int i = 0 ; i < 100 ; i++){
		for(int j = 0 ; j < 100 ; j++){
			sum += map[i][j];
		}
	}

	cout << sum;



}