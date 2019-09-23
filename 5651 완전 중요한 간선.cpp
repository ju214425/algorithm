#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
 
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
 
using namespace std;

const int MAX_V = 301;
const int INF = 987654321;
 
int cap[MAX_V][MAX_V];
int fl[MAX_V][MAX_V];
int floyd[MAX_V][MAX_V];
int work[MAX_V];
int level[MAX_V];

vector<int> adj[MAX_V];
 
int S, T;
 
void clear(){
    for(int i = 0 ; i < MAX_V ; i++){
        for(int j = 0 ; j < MAX_V ; j++){
            cap[i][j] = fl[i][j] = floyd[i][j] = 0;
        }
        adj[i].clear();
    }
}

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
 
            if (level[next] == -1 && cap[here][next] - fl[here][next] > 0)
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
        if (level[next] == level[here] + 1 && cap[here][next] - fl[here][next] > 0)
        {
            int ret = dfs(next, min(cap[here][next] - fl[here][next], flow));
            if (ret > 0)
            {
                fl[here][next] += ret;
                fl[next][here] -= ret;
                return ret;
            }
        }
    }
 
    return 0;
}
 
int main()
{
    int k, n, m, f, t, b;
    vector<pair<int, int> > v;
    cin >> k;
    while(k--){
        cin >> n >> m;
        S = 1; T = n;
        v.clear();
        clear();
        for(int i = 1 ; i <= m ; i++)
        {
            cin >> f >> t >> b;
            adj[f].push_back(t);
            adj[t].push_back(f);
            cap[f][t] = b;
            v.push_back({f, t});
        }
        
        while (bfs())
        {
            fill(work, work + MAX_V, 0);
            while (true)
            {
                int flow = dfs(S, INF);
                if (flow == 0)
                    break;
            }
        }
        
        int cnt = 0;
        for(int i = 1 ; i <= n ; i++){
            for(auto j : adj[i]){
                if(cap[i][j] > fl[i][j]){
                    floyd[i][j] = 1;
                }
            }
        }

        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                for(int k = 1 ; k <= n ; k++){
                    if(floyd[j][i] and floyd[i][k]){
                        floyd[j][k] = 1;
                    }
                }
            }
        }

        for(int i = 0 ; i < v.size() ; i++){
            if(!floyd[v[i].first][v[i].second]){
                cnt++;
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}