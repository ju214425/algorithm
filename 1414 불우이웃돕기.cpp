#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int par[105];
int level[105];

#define INF 987654321


struct Connect{
	int a, b, c;
};

void init(){
	for(int i = 0 ; i < 105 ; i++){
		par[i] = i;
		level[i] = 1;
	}
}

int find(int x){
	if(x == par[x])
		return x;
	return par[x] = find(par[x]);
}

void join(int x, int y){
	x = find(x);
	y = find(y);

	if(x == y)
		return;
	
	if(level[x] > level[y])
		swap(x, y);

	par[x] = y;

	if(level[x] == level[y])
		level[y]++;
}

int ctoi(char s){
	if('a' <= s and s <= 'z')
		return int(s) - 96;
	else if('A' <= s and s <= 'Z')
		return int(s) - 38;
	else
		return INF;
}

bool cmp(Connect c1, Connect c2){
	return c1.c < c2.c;
}

int main(){
	int n, temp, value;
	int cnt = 0, sum = 0, idx = 0, total = 0, time = 0;
	char c;


	scanf("%d", &n);
	vector<Connect> v;
	init();
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			scanf(" %1c", &c);
			value = ctoi(c);
			if(value != INF){
				v.push_back({i, j, value});
				total += value;
			}
		}
	}


	sort(v.begin(), v.end(), cmp);

	while(time < v.size()){
		time++;
		if(find(v[idx].a) != find(v[idx].b)){
			join(v[idx].a, v[idx].b);
			sum += v[idx].c;
			cnt++;
		}
		idx++;
		if(cnt == n-1) break;
	}

	if(cnt < n-1){
		printf("-1\n");
	}
	else{
		printf("%d\n", total - sum);
	}
}