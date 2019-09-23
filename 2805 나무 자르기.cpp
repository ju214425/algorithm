#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;


ll cut(vector<ll> v, ll val){
	ll sum  = 0;
	for(ll i = 1; i <= v.size() ; i++){
		if(v[i] > val){
			sum += (v[i] - val);
		}
		else break;
	}

	return sum;
}

vector<ll> t;

int main(){
	ll n, m;
	ll mid;
	ll start, end;
	scanf("%lli%lli", &n, &m);
	vector<ll> t(n+1);
	for(ll i = 1 ; i <= n ; i++){
		scanf("%lli", &t[i]);
	}

	sort(t.begin()+1, t.end());
	reverse(t.begin()+1,t.end());

	start = 0;
	end = t[1];

	while(start+2< end){
		mid = (start + end) / 2;
		ll val = cut(t, mid);
		if(val >= m) {
			start = mid;
		}

		else if(val < m){
			end = mid;
		}
	}

	for(; end >= start ; end--){
		if(m <= cut(t, end)){
			break;
		}
	}

	printf("%lli", end);
}