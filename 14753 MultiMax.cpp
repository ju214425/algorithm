#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
	return abs(a) > abs(b);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n1, ans = 0;
	cin >> n1;

	vector<int> pos, neg;
	pos.push_back(1);
	for(int i = 0 ; i < n1 ; i++){
		int number;
		cin >> number;
		if(number < 0) neg.push_back(number);
		else pos.push_back(number);
	}

	
	sort(neg.begin(), neg.end());
	sort(pos.begin(), pos.end());
	reverse(pos.begin(), pos.end());

	vector<int> v;

	for(int i = 0 ; i < pos.size() ; i++){
		v.push_back(pos[i]);
		if(i == 2) break;
	}

	for(int i = 0 ; i < neg.size() ; i++){
		v.push_back(neg[i]);
		if(i == 1) break;
	}
	
	for(int i = 0 ; i < v.size() ; i++){
		for(int j = i+1 ; j < v.size() ; j++){
			for(int k = j+1 ; k < v.size() ; k++){
				ans = max(ans, v[i] * v[j] * v[k]);
			}
		}
	}


	cout << ans;
}