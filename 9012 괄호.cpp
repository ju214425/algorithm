#include <iostream>

using namespace std;

int main(){
	int t;
	string str;
	cin >> t;

	for(int i = 1 ; i <= t ; i++){
		cin >> str;
		int cnt = 0;

		for(int j = 0 ; j < str.size() ; j++){
			if(str[j] == '(') cnt++;
			else if(str[j] == ')') cnt--;
			if(cnt < 0){
				break;
			}
		}
		if(cnt != 0) cout << "NO" << endl;
		else cout << "YES" << endl;
	}

}