#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visit[505];

int main(){
	int n, m;
	int a, b;
	int cnt = -1;
	cin >> n >> m;

	vector<vector<int> > adj(n+1);
	for(int i = 0 ; i < m ; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	queue<pair<int, int> > q;
	pair<int, int> f;
	q.push({1, 0});
	visit[1] = 1;

	while(!q.empty()){
		f = q.front();
		q.pop();
		if(f.second == 3) break;
		cnt++;
		for(int i = 0 ; i < adj[f.first].size() ; i++){
			int p = adj[f.first][i];
			if(visit[p] == 0){
				q.push({p, f.second + 1});
				visit[p] = 1;
			}
		}
	}

	cout << cnt;
}