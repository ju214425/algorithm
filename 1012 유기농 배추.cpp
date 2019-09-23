#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int map[55][55];
int visit[55][55];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1 ,0};

void clear(){
	for(int i = 0 ; i < 55 ; i++){
		for(int j = 0 ; j < 55 ; j++){
			map[i][j] = 0;
			visit[i][j] = 0;
		}
	}
}

int main(){
	int t;
	int m, n, k;
	int x, y;
	cin >> t;
	while(t--){
		int cnt = 0;
		cin >> m >> n >> k;
		queue<pair<int, int> > q; 
		clear();
		for(int i = 0 ; i < k ; i++){
			cin >> x >> y;
			map[x][y] = 1;
		}
		for(int i = 0 ; i < m ; i++){
			for(int j = 0 ; j < n ; j++){
				if(visit[i][j] == 0 and map[i][j] == 1){
				 	q.push({i, j});
				 	visit[i][j] = 1;
				 	map[i][j] = 0;
				 	while(!q.empty()){
				 		int f = q.front().first;
				 		int s = q.front().second;
				 		q.pop();
				 		for(int cnt = 0 ; cnt < 4 ; cnt++){
				 			if(0 <= f+dx[cnt] and f+dx[cnt] < m and 0 <= s+dy[cnt] and s+dy[cnt] < n){
					 			if(map[f+dx[cnt]][s+dy[cnt]] == 1 and visit[f+dx[cnt]][s+dy[cnt]] == 0){
					 				q.push({f+dx[cnt], s+dy[cnt]});
					 				map[f+dx[cnt]][s+dy[cnt]] = 0;
					 				visit[f+dx[cnt]][s+dy[cnt]] = 1;
					 			}
					 		}
				 		}
				 	}
				 	cnt++;
				}
			}
		}
		cout << cnt << endl;
	}	
}