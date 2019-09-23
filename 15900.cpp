#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int ans = 0;

void dfs(int start, vector<int> graph[], bool check[], int cnt){
	check[start]= true;
	for(int i=0; i < graph[start].size(); i++){
		if(graph[start].size() == 1) ans += cnt;
		int next = graph[start][i];
		if(check[next]==false){	
			dfs(next, graph, check, cnt+1);
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	vector<int> graph[n+1];
	bool check[n+1];
	for(int i = 1 ; i <= n ; i++) {
		check[i] = false;
	}
	for(int i = 1 ; i < n ; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1, graph, check, 0);

	if (ans % 2 != 0) printf("Yes");
	else printf("No");

	return 0;
}