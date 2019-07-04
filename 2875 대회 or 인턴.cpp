#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, m, k, cnt = 0;
	scanf("%d%d%d", &n, &m, &k);
	while(true) {
		if(n + m < k){
			cnt--;
			break;
		}
		if(n >= 2 and m >= 1) {
			n -= 2;
			m--;
			cnt++;
		}
		else{
			break;
		}
	}
	printf("%d", cnt);

	return 0;
}