#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	string str;
	int sum = 0;
	cin >> str;
	sort(str.begin(), str.end());
	reverse(str.begin(), str.end());
	for(int i = 0 ; i < str.size() ; i++){
		sum += int(str[i]) - 48;
	}

	if(sum % 3 != 0 or str[str.size()-1] != '0'){
		cout << -1;
	}
	else{
		cout << str;
	}

	return 0;
}