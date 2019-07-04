#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, m, min_val = 0x7fffffff, min_f = 2000, min_s = 2000;
	scanf("%d%d", &n, &m);
	vector<pair<int, int> > v;
	v.resize(m);
	for(int i = 0 ; i < m ; ++i) {
		scanf("%d%d", &v[i].first, &v[i].second);
		min_f = min(min_f, v[i].first);
		min_s = min(min_s, v[i].second);
	}
	int div = n / 6;
	int mod = n % 6;
	
	min_val = min(min_f * (div+1), min(min_s * n, min_f * div + min_s * mod));
	
	printf("%d", min_val);

	return 0;
}