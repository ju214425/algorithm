#include <cstdio>
#include <vector>

int q1(int n){
	int cnt = 0;
	int *sieve = new int[n+1];
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n; j += i) {
			cnt += 1;
		}
	}
	return cnt;
}

int main(){
	int n, cnt = 0;
	vector<int> v1, v2;
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; i++){
		printf("%d ", q1(i));
	}
	

	while()
		int a = (n-1) / i + 1 ;
		int b =(n-1) / a;
		v1.push_back(a);
		v2.push_back(b);

	}
}