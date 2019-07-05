#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, min, max;
	scanf("%d", &n);
	vector<int> v;
	v.resize(n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());
	min = v[0];
	max = v[n-1];
	printf("%d %d", min, max);

	return 0;
}