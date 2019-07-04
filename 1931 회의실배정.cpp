#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
	return a.second == b.second ? a.first < b.first : a.second < b.second;
}

int main() {
	int n, cnt = 0, last = 0;
	scanf("%d", &n);
	vector<pair<int, int> > v;
	v.resize(n);
	for(int i = 0 ; i < n ; ++i) {
		scanf("%d%d", &v[i].first, &v[i].second);
	}

	sort(v.begin(), v.end(), cmp);

	for(int i = 0 ; i < v.size() ; ++i) {
		if(last <= v[i].first) {
			last = v[i].second;
			cnt++;
		}
	}

	printf("%d", cnt);

	return 0;
}
