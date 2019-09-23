#include <iostream>

using namespace std;

int main(){
	int n;
	string s;
	cin >> n;
	cin >> s;

	int score = 0, bonus = 0, total = 0;
	for(int i = 1 ; i <= s.size() ; i++){
		if(s[i-1] == 'O'){
			score = i; 
			total += (bonus + score);
			bonus++;
		}
		else{
			bonus = 0;
			score = 0;
		}
	}

	cout << total << "\n";
}