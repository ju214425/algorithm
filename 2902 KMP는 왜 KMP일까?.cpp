#include <iostream>

using namespace std;

int main(){
	string str, ans;
	cin >> str;
	for(int i = 0 ; i < str.size() ; i++){
		if(65 <= int(str[i]) and int(str[i]) <= 90){
			ans += str[i];
		}
	}
	cout << ans;
}