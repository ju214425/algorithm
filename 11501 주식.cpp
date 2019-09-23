#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

struct stock{
	int idx, val;
};

bool cmp(stock s1, stock s2){
	return s1.val > s2.val;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		ll sum = 0;
		cin >> n;
		vector<stock> v(n), srt(n);
		vector<int> check;
		for(int i = 0 ; i < n ; i++){
			int a;
			cin >> a;
			v[i] = {i, a};
			srt[i] = {i, a};
		}

		sort(srt.begin(), srt.end(), cmp);

		int max_idx = srt[0].idx;
		check.push_back(srt[0].idx);

		for(int i = 1 ; i < n ; i++){
			if(srt[i].idx > max_idx){
				check.push_back(srt[i].idx);
				max_idx = srt[i].idx;
			}
		}
		
		int p = 0;
		for(int i = 0 ; i < check.size() ; i++){
			for(int j = p ; j < check[i] ; j++){
				sum += (v[check[i]].val - v[j].val);
			}
			p = check[i]+1;
		}

		cout << sum << "\n";
	}
}