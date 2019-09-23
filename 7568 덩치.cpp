#include <cstdio>
#include <vector>

using namespace std;

struct Body{
	int weight;
	int height;
};

int main(){
	int n;
	scanf("%d", &n);
	vector<Body> v(n+1);
	vector<int> ans(n+1, 1);
	for(int i = 1 ; i <= n ; i++){
		scanf("%d%d", &v[i].weight, &v[i].height);
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(v[i].weight > v[j].weight and v[i].height > v[j].height){
				ans[j]++;
			}
		}
	}
	for(int i = 1 ; i <= n ; i++){
		printf("%d ", ans[i]);
	}
}