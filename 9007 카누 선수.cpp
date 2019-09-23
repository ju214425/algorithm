#include <cstdio>
#include <vector>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, k;
		scanf("%d%d", &k, &n);
		vector<int> v1(n), v2(n), v3(n), v4(n);		
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &v1[i]);
		}
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &v2[i]);
		}
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &v3[i]);
		}
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &v4[i]);
		}
		
	}
}