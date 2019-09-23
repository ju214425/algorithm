#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int func(int number){
	int i = 0;
	int ans;
	while(true){
		if((i*(i-1)/2) <= number and number <= i*(i+1)/2){
			ans = i;
			break;
		}
		i++;
	}

	return ans;
}

int main(){
	int n;
	scanf("%d", &n);
	int number = ceil((float(n-1))/float(6));
	printf("%d",func(number)+1);

}