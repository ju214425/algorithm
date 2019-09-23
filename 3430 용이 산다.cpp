#include <iostream>

using namespace std;

#define MAX 10000

int par[MAX];
int level[MAX];

int init(){
	for(int i = 0 ; i < MAX ; i++){
		par[i] = i;
		level[i] = 1;
	}
}

int find(int x){
	if(x == par[x]) return x;
	return par[x] = find(par[x]);
}

void join(int x, int y){
	x = find(x);
	y = find(y);
	
	if(x == y) return;

	if(level[x] < level[y])
		swap(x, y);

	par[y] = x;

	if(level[x] == level[y])
		level[x]++;
}

int main(){

}