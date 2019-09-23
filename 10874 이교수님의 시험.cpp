#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n, number;
	bool ans;
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		ans = false;
		for(int j = 1 ; j <= 10 ; j++){
			cin >> number;
			if(((number-1) % 5 + 1) != ((j-1) % 5 + 1)){
				ans = true;
			}
		}
		if(!ans){
			cout << i << endl;
		}
	}
}