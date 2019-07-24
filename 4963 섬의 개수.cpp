#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int map[55][55];

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

void search(int x, int y){
	map[x][y] = 0;
	for(int i = 0 ; i < 8 ; i++){
		if(map[x+dx[i]][y+dy[i]] != 0) {
			search(x + dx[i], y + dy[i]);
		}
	}
}

void clean(){
	for(int i = 0 ; i < 55; i++){
		for(int j = 0 ; j < 55 ; j++){
			map[i][j] = 0;
		}
	}
}


int main(){
	int w, h;
	int ans = 0;
	while(true){
		scanf("%d%d", &w, &h);
		if(w == 0 and h == 0) break;
		for(int i = 1 ; i <= h ; i++){
			for(int j = 1 ; j <= w ; j++){
				scanf("%d", &map[i][j]);
			}
		}
		for(int i = 1 ; i <= h ; i++){
			for(int j = 1 ; j <= w ; j++){
				if(map[i][j] == 1){
					search(i, j);
					ans++;
				}
			}
		}
		clean();
		printf("%d\n", ans);
		ans = 0;
	}
}