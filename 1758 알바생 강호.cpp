#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(){
	int n;
	ll sum = 0;
	scanf("%d", &n);
	vector<int> v(n+1);
	for(int i = 1 ; i <= n ; i++){
		scanf("%d", &v[i]);
	}
	
	sort(v.begin()+1, v.end());
	reverse(v.begin()+1, v.end());

	for(int i = 1 ; i <= n ; i++){
		if(v[i] - (i-1) < 0) break;
		sum += (v[i] - (i - 1));
	}

	printf("%lli", sum);
}