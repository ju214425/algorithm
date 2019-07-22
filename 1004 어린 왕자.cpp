#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool comprise(int cx, int cy, int r, int x, int y){
	float d = sqrt((cx - x) * (cx - x) + (cy - y) * (cy - y));
	
	return d < r ? true : false;
}

int main(){
	int t;
	int x1,x2,y1,y2;
	int n;
	int cx, cy, r;
	int ans = 0;
	scanf("%d", &t);
	for(int i = 1 ; i <= t ; i++){
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		scanf("%d", &n);
		for(int j = 1 ; j <= n ; j++){
			scanf("%d%d%d", &cx, &cy, &r);
			if (comprise(cx, cy, r, x1, y1) ^ comprise(cx, cy, r, x2, y2))
				ans++;
		}
		printf("%d\n", ans);
		ans = 0;
	}
}