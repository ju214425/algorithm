#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;

ll get(ll number){
	ll ret = 0;
	while(number != 0){
		if(number % 2 == 0){
			number /= 2;
			ret++;
		}
		else{
			break;
		}
	}

	return pow(2, ret);
}

int main(){
	ll a, b, sum = 0;
	scanf("%lli%lli", &a, &b);
	for(int i = a ; i <= b; ++i)
		sum += get(i);
	printf("%lli", sum);

	return 0;
}