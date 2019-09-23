#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visit[1005];

int main(){
	int n, m, f;
	cin >> n >> m;
	vector<vector<int> > v(n+1);

	queue<int> q;
	for(int i = 0 ; i < m ; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	q.push(1);
	visit[1] = 1;
	int cnt = 0, ans = 0, idx = 1;
	while(cnt < n){
		while(!q.empty()){
			f = q.front();
			q.pop();
			cnt++;
			for(int i = 0 ; i < v[f].size() ; i++){
				if(visit[v[f][i]] == 0){
					visit[v[f][i]] = 1;
					q.push(v[f][i]);
				}
			}
		}
		ans++;

		for(int i = idx ; i <= n ; i++){
			if(visit[i] == 0){
				idx = i+1;
				q.push(i);
				visit[i] = 1;
				break;
			}
		}
	}
	cout << ans;
}