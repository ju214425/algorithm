#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct lecture{
	int money;
	int day;
};

bool cmp(lecture l1, lecture l2){
	return l1.money == l2.money ? l1.day > l2.day : l1.money > l2.money;
}


bool check[10001];

int main(){
	int n;
	ll sum = 0;
	scanf("%d", &n);
	vector<lecture> v(n+1);
	for(int i = 1 ; i <= n ; i++){
		scanf("%d%d", &v[i].money, &v[i].day);
	}

	sort(v.begin()+1, v.end(), cmp);
	
	int p;
	for(int i = 1 ; i <= n ; i++){
		p = v[i].day;
		while(check[p]){
			p--;
		}
		if(p == 0) continue;
		check[p] = true;
		sum += v[i].money;
	}

	printf("%lli", sum);
}