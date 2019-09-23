#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, l;
	double start = -10, end = -10;
	int cnt = 0;
	scanf("%d%d", &n, &l);
	vector<int> v(n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());

	for(int i = 0 ; i < n ; i++){
		if(end >= v[i] + 0.5) continue;
		start = max(v[i] - 0.5, end);
		end = start + l;
		cnt++;
	}

	printf("%d", cnt);
}