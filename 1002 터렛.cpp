#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	int t;
	float x1, y1, t1, x2, y2, r1, r2;
	scanf("%d", &t);
	for(int i = 1 ; i <= t ; i++){
		scanf("%f%f%f%f%f%f", &x1, &y1, &r1, &x2, &y2, &r2);
		float d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
		
		if(d == 0 and r1 == r2){
			printf("-1\n");
		}

		else if((r1 + r2 == d) or (abs(r1-r2) == d)){
			printf("1\n");
		}

		else if((d > r1 + r2) or (abs(r1-r2) > d)){
			printf("0\n");
		}

		else{
			printf("2\n");
		}
	}

	return 0;
}