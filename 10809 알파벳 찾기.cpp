#include <iostream>
#include <vector>
using namespace std;



int main(){
	string str;
	cin >> str;
	vector<int> arr(26, -1);
	for(int i = 0 ; i < str.size() ; i++){
		if(arr[str[i] - 97] == -1)
			arr[str[i] - 97] = i;
	}
	for(int i = 0 ; i < 26; i++){
		cout << arr[i] << " ";
	}

}