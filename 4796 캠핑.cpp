#include <cstdio>

int main(){
	int l, p, v;
	int test_case = 1;
	int ans;
	while(true){
		scanf("%d%d%d", &l, &p, &v);
		if(l == 0 and l == p and p == v) break;
		ans = (v/p)*l;
		v -= (v/p)*p;
		if(v > l) ans += l;
		else ans += v;
		printf("Case %d: %d\n", test_case, ans);
		test_case++;
	}
}