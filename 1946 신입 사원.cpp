#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for(int i = 0 ; i < t ; ++i) {
		int n, cnt = 0, min = 123456;
		scanf("%d", &n);
		vector<pair<int, int> > v;
		v.resize(n);
		for(int j = 0 ; j < n ; ++j) {
			scanf("%d%d", &v[j].first, &v[j].second);
		}
		
		sort(v.begin(), v.end());
		
		for(int j = 0 ; j < n ; ++j) {
			if(min > v[j].second){
				min = v[j].second;
				cnt++;
			}
		}
		printf("%d\n", cnt);

	}

	return 0;
}