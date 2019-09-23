#include <cstdio>
#include <vector>

using namespace std;

char board[51][51];

int check(int x, int y){
	int cnt = 0;

	for(int i = x ; i < x + 8 ; i++){
		for(int j = y ; j < y + 8 ; j++){
			if((i+j)%2 == 0){
				if(board[i][j] == 'W') cnt++;
			}
			else{
				if(board[i][j] == 'B') cnt++;
			}
		}
	}

	return min(cnt, 64-cnt);
}

int main(){
	int n, m;
	int ans = 64;
	scanf("%d%d", &n, &m);
	for(int x = 0 ; x < n ; x++){
		for(int y = 0 ; y < m ; y++){
			scanf(" %c", &board[x][y]);
		}
	}
	
	for(int x = 0 ; x <= n-8 ; x++){
		for(int y = 0 ; y <= m-8 ; y++){
			ans = min(ans,check(x, y));
		}
	}

	printf("%d", ans);


}