#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2){
	return p1.first < p2.first;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int c1, c2, p1, p2;
	int num_pairs = 0;
	int min_val = 0x7fffffff;
	cin >> n >> m;
	cin >> c1 >> c2;

	int dist = abs(c1 - c2);

	vector<int> p(n), q(m);
	vector<pair<int, int> > all(n+m);

	for(int i = 0 ; i < n ; i++){
		int temp;
		cin >> temp;
		all[i] = {temp, 1};
	}

	for(int i = 0 ; i < m ; i++){
		int temp;
		cin >> temp;
		all[n+i] = {temp, -1};
	}

	sort(all.begin(), all.end(), cmp);	

	for(int i = 0 ; i < n + m - 1 ; i++){
		if(all[i+1].second != all[i].second){
			int diff = all[i+1].first - all[i].first;
			if(min_val > diff){
				min_val = diff;
				num_pairs = 1;
			}
			else if(min_val == diff){
				num_pairs++;
			}
		}
	}
	cout << min_val + dist << " " << num_pairs;

}