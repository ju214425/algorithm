#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		int p;
		cin >> n;
		vector<string> str(n);
		vector<pair<string, string> > key(n);
		for(int i = 0 ; i < n ; i++){
			cin >> str[i];
		}
		for(int i = 0 ; i < n ; i++){
			cin >> key[i].first;
		}
		for(int i = 0 ; i < n ; i++){
			cin >> key[i].second;
		}
		sort(key.begin(), key.end());
		
		for(int i = 0 ; i < n ; i++){
			p = 0;
			while(p < n){
				if(str[i] != key[p].first)
					p++;
				else{
					cout << key[p].second << " ";
					break;
				}
			}
		}
		cout << endl;

	}
}