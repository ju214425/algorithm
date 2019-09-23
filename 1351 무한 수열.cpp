#include <cstdio>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;


ll func(map<ll, ll> &m, ll n, ll p, ll q){
	if(m.find(n) != m.end()) return m[n];
	ll l1 = n/p;
	ll l2 = n/q;
	m[n] = func(m, l1, p, q) + func(m, l2, p, q);
	return m[n];
}

int main(){
	ll n, p, q;
	scanf("%lli%lli%lli", &n, &p, &q);
	map<ll, ll> m;
	m[0] = 1;
	func(m, n, p, q);
	printf("%lli", m[n]);

	return 0;
}