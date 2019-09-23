#include <cstdio>
#include <stack>

using namespace std;

int map[16][16];

int main(){
	int n;
	scanf("%d", &n);
	stack<pair<int, int> > s;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			s.push(pair<int, int> (i, j));
		}
	}

}