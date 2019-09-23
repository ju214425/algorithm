#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(){
	int n;
	ll ans = 0x7fffffffffffffff;
	ll s, b;
	scanf("%d", &n);
	int bitmask = 0;


	vector<pair<ll, ll> > v(n+1);
	for(int i = 1 ; i <= n ; i++){
		scanf("%lli%lli", &v[i].first, &v[i].second);
	}

	for(int i = 1 ; i < (1<<n) ; i++){
		bitmask = i;
		s = 1;
		b = 0;
		for(int j = 1 ; j <= n ; j++){
			if(bitmask % 2 == 1) {
				s *= v[j].first;
				b += v[j].second;
			}
			bitmask /= 2;
		}
		ans = min(ans, abs(s-b));
	}

	printf("%lli", ans);
}