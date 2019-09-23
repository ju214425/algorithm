#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
 
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
 
using namespace std;

const int MAX_P = 1000;
const int MAX_V = MAX_P*2+2;
const int INF = 987654321;
 
int c[MAX_V][MAX_V];
int f[MAX_V][MAX_V];
int work[MAX_V];
int level[MAX_V];

vector<int> adj[MAX_V];
 
int S = 0, T = MAX_V-1;
 
 
// 디닉 bfs
bool bfs()
{
    fill(level, level + MAX_V, -1);
    level[S] = 0;
 
    queue<int> q;
 
    q.push(S);
 
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
 
        for(int i = 0; i < adj[here].size(); i++)
        {
            int next = adj[here][i];
 
            if (level[next] == -1 && c[here][next] - f[here][next] > 0)
            {
                level[next] = level[here] + 1;
                q.push(next);
            }
        }
    }
 
    return level[T] != -1;
}
 
// 디닉 dfs
int dfs(int here, int flow)
{
    if (here == T)
        return flow;
 
    for(int &i = work[here] ; i < adj[here].size() ; i++)
    {
        int next = adj[here][i];
        if (level[next] == level[here] + 1 && c[here][next] - f[here][next] > 0)
        {
            int ret = dfs(next, min(c[here][next] - f[here][next], flow));
            if (ret > 0)
            {
                f[here][next] += ret;
                f[next][here] -= ret;
                return ret;
            }
        }
    }
 
    return 0;
}
 
int main()
{
    int n, m, s, task;
    cin >> n >> m;
 
    for(int i = 1 ; i <= n ; i++)
    {
        adj[S].push_back(i);
        adj[i].push_back(S);
        c[S][i] = 1;

        cin >> s;
        for(int j = 1 ; j <= s ; j++){
        	cin >> task;
        	adj[i].push_back(MAX_P+task);
        	adj[MAX_P+task].push_back(i);
        	c[i][MAX_P+task] = 1;
        }
    }

    for(int i = 1 ; i <= m ; i++){
    	adj[i+MAX_P].push_back(T);
    	adj[T].push_back(i+MAX_P);
    	c[i+MAX_P][T] = 1;
    } 
 
    int totalFlow = 0;

    while (bfs())
    {
        fill(work, work + MAX_V, 0);
        while (true)
        {
            int flow = dfs(S, INF);
            if (flow == 0)
                break;
            totalFlow += flow;
        }
    }
    cout << totalFlow;
    return 0;
}