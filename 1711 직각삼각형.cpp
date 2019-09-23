#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

struct Coord{
	ll x, y;
};


bool product(Coord c1, Coord c2, Coord c3){
	pair<ll, ll> v1 = make_pair(c1.x - c2.x, c1.y - c2.y);
	pair<ll, ll> v2 = make_pair(c2.x - c3.x, c2.y - c3.y);
	pair<ll, ll> v3 = make_pair(c3.x - c1.x, c3.y - c1.y);

	if(v1.first * v2.first + v1.second * v2.second == 0) return true;
	if(v2.first * v3.first + v2.second * v3.second == 0) return true;
	if(v3.first * v1.first + v3.second * v1.second == 0) return true;
	return false;
}

int main(){
	ll n, cnt = 0;
	scanf("%lli", &n);
	vector<Coord> v(n+1);
	for(ll i = 1 ; i <= n ; i++){
		scanf("%lli%lli", &v[i].x, &v[i].y);
	}

	for(ll i = 1 ; i <= n-2 ; i++){
		for(ll j = i + 1 ; j <= n-1 ; j++){
			for(ll k = j + 1 ; k <= n ; k++){
				if(product(v[i], v[j], v[k])) cnt++;
			}
		}
	}
	printf("%lli", cnt);
	return 0;
}