#include <iostream>

using namespace std;

#define MAX 300005

int par[MAX];
int filled[MAX];

void init(){
	for(int i = 1 ; i <= MAX ; i++){
		par[i] = i;
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
	par[x] = y;
	cout << "LADICA\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, l, a, b;
	cin >> n >> l;
	init();

	for(int i = 1 ; i <= n ; i++){
		cin >> a >> b;
		if(!filled[a]){
			filled[a] = 1;
			join(a, b);
		}
		else if(!filled[b]){
			filled[b] = 1;
			join(b, a);
		}
		else if(!filled[find(a)]){
			filled[find(a)] = 1;
			join(a, b);
		}
		else if(!filled[find(b)]){
			filled[find(b)] = 1;
			join(b, a);
		}
		else{
			cout << "SMECE\n";
		}
	}
}