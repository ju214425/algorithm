#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int map[1005][1005];
int visit[1005][1005];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m, n;
	cin >> m >> n;

	for(int i = 1 ; i <= m ; i++){
		string temp;
		cin >> temp;
		for(int j = 0 ; j < n ; j++){
			map[i][j+1] = temp[j] - 48;
		}
	}

	// for(int i = 1 ; i <= m ; i++){
	// 	for(int j = 1 ; j <= n ; j++){
	// 		cout << map[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }


	queue<pair<int, int> > q;
	bool check = false;

	for(int i = 1 ; i <= n ; i++){
		if(map[1][i] == 0){
			q.push({1, i});
			visit[1][i] = 1;
		}
	}

	while(!q.empty()){
		pair<int, int> f = q.front();
		q.pop();
		// cout << f.first << " " << f.second << "\n";
		for(int i = 0 ; i < 4 ; i++){
			int y = f.first + dx[i];
			int x = f.second + dy[i];

			if(0 < y and y <= m and 0 < x and x <= n){
				if(visit[y][x] == 0 and map[y][x] == 0){
					visit[y][x] = 1;
					q.push({y,x});

					// cout << "X : " << x << " Y : " << y << "\n"; 
					if(y == m){
						check = true;
						break;
					}
				}
			}
		}
		if(check)
			break;
	}

	if(check) cout << "YES" << "\n";
	else cout << "NO" << "\n";
}