#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

int cnt[501];
int visit[501];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, f, n, m, ans = 0;
	cin >> n >> m;
	vector<vector<int> > v(n+1);
	queue<int> q;
	for(int i = 0 ; i < m ; i++){
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	q.push(1);
	visit[1] = 1;
	while(!q.empty()){
		f = q.front();
		q.pop();
		if(cnt[f] == 3) break;
		ans++;
		for(int i = 0 ; i < v[f].size() ; i++){
			if(visit[v[f][i]] == 0){
				visit[v[f][i]] = 1;
				cnt[v[f][i]] = cnt[f] + 1;
				q.push(v[f][i]);
			}
		}
	}

	cout << ans - 1;

}