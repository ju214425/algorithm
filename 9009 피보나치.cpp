#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(){
	int t, next = 1;
	scanf("%d", &t);
	int number;
	vector<ll> fibo(50), v;
	fibo[1] = 1;
	fibo[2] = 1;
	for(int i = 3 ; i < 50 ; i++){	
		fibo[i] = fibo[i-1] + fibo[i-2];
	}

	for(int i = 1 ; i <= t ; i++){
		scanf("%d", &number);
		int j = 1;
		while(number != 0){
			if(number < fibo[j]){
				number -= fibo[j-1];
				v.push_back(fibo[j-1]);
				j = 0;
			}
			j++;
		}
		reverse(v.begin(), v.end());
		for(int j = 0 ; j < v.size() ; j++){
			printf("%lli ", v[j]);
		}
		printf("\n");
		v.clear();
	}
}