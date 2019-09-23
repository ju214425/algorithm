#include <cstdio>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int ans = 0;
	for(int i = 1 ; i <= n ; i++){
		int sum = i;
		int temp = i;
		while(temp != 0){
			sum += temp % 10;
			temp /= 10;
		}
		if(sum == n){
			ans = i;
			break;
		}
	}

	printf("%d", ans);
}