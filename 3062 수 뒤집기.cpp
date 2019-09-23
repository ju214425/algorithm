#include <iostream>
#include <string>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string a, b;
		cin >> a;
		
		for(int i = a.size() -1 ; i >= 0 ; i--){
			b += a[i];
		}
		
		string number = to_string(stoi(a) + stoi(b));
		string temp;
		for(int i = number.size() - 1 ; i >= 0 ; i--){
			temp += number[i];
		}
		if(number == temp){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}