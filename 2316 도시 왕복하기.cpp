#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 0xfffffff
#define MAX 805

int c[MAX][MAX];
int f[MAX][MAX];
int adj[MAX][MAX];

int main(){
    int n, p;
    
    scanf("%d%d", &n, &p);

    for(int i = 1 ; i <= n ; i++){
        c[i+n][i] = 1;
        adj[i+n][i] = 1;
        adj[i][i+n] = 1;
    }

    for(int i = 0 ; i < p ; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        int u_in = u + n, u_out = u, v_in = v + n, v_out = v;

        c[u_out][v_in] = 1;
        c[v_out][u_in] = 1;

        adj[u_in][v_out] = 1;
        adj[v_in][u_out] = 1;
        adj[u_out][v_in] = 1;
        adj[v_out][u_in] = 1;
    }
    
    int cnt = 0, S = 1, E = 2+n;

    while(1){
        int prev[MAX];
        fill(prev, prev+MAX, -1);
        queue<int> Q;
        Q.push(S);
        while(!Q.empty()){
            int curr = Q.front();
            Q.pop();
            for(int next = 1 ; next < MAX ; next++){
                if(adj[curr][next] == 1){
                    if(c[curr][next]-f[curr][next] > 0 and prev[next] == -1){
                        Q.push(next);
                        prev[next] = curr; // 경로를 기억하기 위해 prev 배열 사용
                        if(next == E) break; // 싱크에 도달하면 나옴
                    }
                }
            }
        }

        if(prev[E] == -1) break;

        for(int i=E; i!=S; i=prev[i]){
            f[prev[i]][i] += 1;
            f[i][prev[i]] -= 1;
        }

        cnt += 1;
    }

    printf("%d\n", cnt);
}