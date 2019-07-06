#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, set = 0;
	scanf("%d", &n);
	vector<int> v, a;
	a.resize(10);

	if(n == 0){
		printf("1");
		return 0;
	}
	
	while(n != 0) {
		v.push_back(n%10);
		n/=10;
	}

	for(int i = 0 ; i < v.size() ; ++i) {
		if(v[i] == 9)
			a[6]++;
		else
			a[v[i]] ++;
	}

	a[6] = (a[6] +1) /2;

	for(int i = 0 ; i < a.size() ; ++i) {
		set = max(set, a[i]);
	}
	printf("%d", set);

	return 0;
}