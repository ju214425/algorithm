#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, m;
	int val = 0;
	int ans = 0;
	scanf("%d%d", &n, &m);
	vector<int> v(n+1);
	for(int i = 1 ; i <= n ; i++){
		scanf("%d", &v[i]);
	}
	sort(v.begin()+1, v.end());
	for(int i = 1 ; i <= n ; i++){
		for(int j = i+1 ; j <= n ; j++){
			for(int k = j+1 ; k <= n ; k++){
				val = v[i] + v[j] + v[k];
				if(val <= m){
					ans = max(ans, val);
				}
				if(ans == m){
					printf("%d\n", m);
					
					return 0;
				}
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}