#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
	string str;
	cin >> str;
	vector<pair<int, char> > v(26);
	for(int i = 0 ; i < str.size() ; i++){
		if(str[i] - 97 >= 0){
			str[i] -= 32;
		} 
		v[str[i]-65].first++;
		v[str[i]-65].second = str[i];
	}

	sort(v.begin(), v.end());
	if(v[24].first == v[25].first) cout << "?";
	else{
		cout << v[25].second;
	}
}