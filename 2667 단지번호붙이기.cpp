#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int map[27][27];
bool visit[27][27];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main(){
	int n;
	scanf("%d", &n);
	int cnt = 0;
	queue<pair<int, int> > q;
	vector<int> v;

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			scanf("%1d", &map[i][j]);
		}
	}


	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(map[i][j] != 0 and visit[i][j] == false){
				visit[i][j] = true;
				q.push(pair<int, int>(i, j));
				cnt++;
				while(!q.empty()){
					pair<int, int> p = q.front();
					q.pop();
					for(int i = 0 ; i < 4 ; i++){
						int x = dx[i] + p.first;
						int y = dy[i] + p.second;
						if(map[x][y] != 0 and visit[x][y] == false){
							visit[x][y] = true;
							q.push(pair<int, int>(x, y));
							cnt++;
						}
					}
				}
				v.push_back(cnt);
				cnt = 0;
			}
		}
	}

	sort(v.begin(), v.end());
	printf("%d\n", (int)v.size());
	for(int i = 0 ; i < v.size() ; i++){
		printf("%d\n", v[i]);
	}
}