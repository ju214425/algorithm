#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll arr[100005][2];

int main(){
	int n, l;
	ll result = 0;
	scanf("%d%d", &n, &l);
	vector<pair<ll, ll> > v(n), t(n);
	vector<int> xpos(n), ypos(n); 
	for(int i = 0 ; i < n ; i++){
		int up, down;
		scanf("%d%d", &up, &down);
		v[i].first = up;
		v[i].second = down;
		xpos[i] = up;
		ypos[i] = down;
	}	

	sort(xpos.begin(), xpos.end());
	sort(ypos.begin(), ypos.end());
	
	xpos.erase(unique(xpos.begin(), xpos.end()), xpos.end());
	ypos.erase(unique(ypos.begin(), ypos.end()), ypos.end());
	sort(v.begin(), v.end());
	for(int i = 0 ; i < v.size() ; i++){
		t[i].first = (int)(lower_bound(xpos.begin(), xpos.end(), v[i].first) - xpos.begin());
		t[i].second = (int)(lower_bound(ypos.begin(), ypos.end(), v[i].second) - ypos.begin());
	}
	for(int i = 0 ; i < n ; i++){
		ll up = t[i].first;
		ll down = t[i].second;
		ll val = abs(v[i].first-v[i].second) + l;
		ll temp1 = arr[up][0];
		ll temp2 = arr[down][1];
		arr[up][0] = max(val + temp2, temp1);
		arr[down][1] = max(val + temp1, temp2);
	}

	for(int i = 0 ; i < n ; i++){
		result = max(result, arr[t[i].first][0]);
		result = max(result, arr[t[i].second][1]);
	}
	
	printf("%lli\n", result);
}