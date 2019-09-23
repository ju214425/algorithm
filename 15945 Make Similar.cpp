#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<int> v(n+1);
	for(int i = 1 ; i <= n ; i++){
		scanf("%d", &v[i]);
	}

	sort(v.begin()+1, v.end());

	printf("%d", v[1]);
}