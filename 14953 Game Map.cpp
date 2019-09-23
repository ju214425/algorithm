#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[100005];

struct node{
	int idx;
	int number;
};	

bool cmp(node n1, node n2){
	return n1.number < n2.number;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int a, b;
	int maximum = 0;
	cin >> n >> m;

	vector<vector<int> > graph(n);
	vector<node> v(n);

	for(int i = 0 ; i < n ; i++){
		dp[i] = 1;
		v[i].idx = i;
	}

	for(int i = 0 ; i < m ; i++){
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0; i < n; ++i) {
		v[i].number = graph[i].size();
	}


	sort(v.begin(), v.end(), cmp);

	for(int i = 0 ; i < v.size() ; i++){
		for(auto next : graph[v[i].idx]){
			if(graph[v[i].idx].size() < graph[next].size()){
				dp[next] = max(dp[v[i].idx]+1, dp[next]);
			}
		}
	}

	for(int i = 0 ; i < n ; i++){
		maximum = max(maximum, dp[i]);
	}

	cout << maximum << "\n";
}	
