#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll func(ll n){
	ll ans;
	ll twos = 2;
	for(ll i = 0 ; i < 50000 ; i++){
		if(twos * (i+1) - 1 >= n){
			ans = i;
			break;
		}
		twos *= 2;
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n;
	cin >> n;

	cout << func(n) << "\n";

}