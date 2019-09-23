#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visit[1001];
int dist[1001];

struct Building{
	vector<int> following;
	int time;
};

void clear(){
	fill(visit, visit+1000, 0);
	fill(dist, dist+1000, 0);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, n, k, w, f;

	cin >> t;
	while(t--){
		int  cur_time = 0;
		cin >> n >> k;
		vector<Building> b(n+1);
		queue<int> q;
		clear();
		for(int i = 1 ; i <= n ; i++){
			cin >> b[i].time;
		}

		for(int i = 0 ; i < k ; i++){
			int front, back;
			cin >> front >> back;
			b[back].following.push_back(front);
		}
		cin >> w;

		q.push(w);
		visit[w] = 1;

		while(!q.empty()){
			f = q.front();
			q.pop();
			cur_time = b[f].time;
			for(int i = 0 ; i < b[f].following.size() ; i++){
				if(visit[b[f].following[i]] == 0){
					q.push(b[f].following[i]);
					visit[b[f].following[i]] = 1;
				}
				dist[b[f].following[i]] = max(cur_time + b[b[f].following[i]].time, dist[b[f].following[i]]);
			}
		}
		cout << cur_time << endl;
	}
}