#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct medal{
	int idx;
	int gold, silver, bronze;
};

bool cmp(medal m1, medal m2){
	return m1.gold == m2.gold ? 
	(m1.silver == m2.silver ?
	 m1.bronze > m2.bronze : 
	 m1.silver > m2.silver)
	 : m1.gold > m2.gold;
}

int main(){
	int n, k;
	int p;
	cin >> n >> k;

	vector<medal> v(n);
	for(int i = 0 ; i < n ; i++){
		int idx, a, b, c;
		cin >> idx >> a >> b >> c;
		v[i] = {idx, a, b, c};
	}

	sort(v.begin(), v.end(), cmp);
	for(int i = 0 ; i < n ; i++){
		if(v[i].idx == k){
			p = i;
			break;
		}
	}

	for(int i = 0 ; i < n ; i++){
		if(v[i].gold == v[p].gold and
			v[i].silver == v[p].silver and
			v[i].bronze == v[p].bronze){
			cout << i+1;
			break;
		}
	}


}