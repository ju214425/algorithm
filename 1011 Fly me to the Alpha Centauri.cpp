#include <iostream>

using namespace std;

typedef long long ll;

ll func(ll n){
	ll ans = 0;
	for(ll i = 0 ; i < 100000 ; i++){
		ll a = i*i;
		ll b = i * (i+1);
		ll c = (i+1)*(i+1);
		if(a < n and n <= b){
			ans = 2*i;
			break;
		}
		if(b < n and n <= c){
			ans = 2*i+1;
			break;
		}
	}
	return ans;
}

int main(){
	int t;
	ll x, y;
	cin >> t;
	while(t--){
		cin >> x >> y;
		ll dist = y - x;
		cout << func(dist) << endl;
	}
}