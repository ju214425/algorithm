#include <iostream>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int r;
		string s;
		cin >> r >> s;
		for(int i = 0 ; i < s.size() ; i++){
			for(int j = 0 ; j < r ; j++){
				cout << s[i];
			}
		}
		cout << endl;
	}
