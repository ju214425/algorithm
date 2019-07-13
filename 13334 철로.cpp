#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


void print(vector<int> &a) {
	printf("\n");
	for(int i = 0 ; i < a.size() ; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void print(vector<pair<int, int> > &a) {
	printf("\n");
	for(int i = 0 ; i < a.size() ; ++i) {
		printf("%d %d\n", a[i].first, a[i].second);
	}
}

bool cmp(pair<int, int> &a, pair<int, int> &b) {
	return a.second < b.second;
}

// struct Cmp{
// 	bool operator() (pair<int, int> &a, pair<int, int> &b) {
// 		return a.second < b.second;
// 	}
// };

int main(){
	int n, d, a, b, max_val = -1;
	scanf("%d", &n);

	priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	vector<pair<int, int> > v;

	for(int i = 0 ; i < n ; ++i) {
		scanf("%d%d", &a, &b);
		if(a > b) swap(a, b);
		v.push_back(pair<int, int> (a, b));
	}

	scanf("%d", &d);

	sort(v.begin(), v.end(), cmp);

	for(int i = 0 ; i < n ; ++i) {
		pq.push(v[i]);
		while(!pq.empty()){
			if(v[i].second - d > pq.top().first) 
				pq.pop();
			else{
				break;
			}
		}
		max_val = max(int(pq.size()), max_val);
	}

	printf("%d", max_val);

	return 0;
}