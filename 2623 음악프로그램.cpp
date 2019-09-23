#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int indegree[1001];
int answer[1001];
vector<int> v[1001];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;	
	
	for(int i = 0 ; i < m ; i++){
		int num, prev, cur;
		cin >> num;
		cin >> prev;

		for(int j = 0 ; j < num-1 ; j++){
			cin >> cur;
			v[prev].push_back(cur);
			indegree[cur]++;
			prev = cur;
		}
	}
	queue<int> q;

	for(int i = 1 ; i <= n ; i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}

	for(int i = 0 ; i < n ; i++){
		if(q.empty()){
			cout << "0\n";
			return 0;
		}
		int front = q.front();
		q.pop();
		answer[i] = front;
		for(int j = 0 ; j < v[front].size() ; j++){
			int next = v[front][j];
			if(--indegree[next] == 0)
				q.push(next);
		}
	}

	for(int i = 0 ; i < n ; i++){
		cout << answer[i] << "\n";
	}

	return 0;
}