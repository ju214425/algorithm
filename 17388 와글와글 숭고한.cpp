#include <iostream>

using namespace std;

int main(){
	int s, k, h;

	cin >> s >> k >> h;

	if(s + k + h >= 100){
		cout << "OK" << "\n";
	}
	else{
		int mini = min(min(s, k), h);
		if(mini == s) cout << "Soongsil" << "\n";
		else if(mini == k) cout << "Korea" << "\n";
		else cout << "Hanyang" << "\n";
	}
}