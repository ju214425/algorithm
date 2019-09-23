#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 400; // 최대 N, M
const int MAX_V = 2*(MAX_N+1); // 최대 정점 개수
const int S = MAX_V-2; // 소스 정점 번호
const int E = MAX_V-1; // 싱크 정점 번호
const int INF = 1000000000;
const int WORK=400;

struct MCMF{
    int N, M;
    int result = 0; // 최소 비용
    int work=0; // 할 수 있는 일의 갯수 
    int c[MAX_V][MAX_V] = {0}; // 각 간선의 용량
    int d[MAX_V][MAX_V] = {0}; // 각 간선의 비용
    int f[MAX_V][MAX_V] = {0}; // 각 간선에 흐르는 중인 유량
    vector<int> adj[MAX_V]; // 각 정점의 인접 리스트
    
    MCMF(){
        cin >> N >> M;
        // 각 사람 정점과 소스 정점 사이 간선 추가 (비용 0)
        for(int i=1;i<=N;i++){
            c[S][i]=1;
            adj[S].push_back(i);
            adj[i].push_back(S);
        }
        
				// 각 일 정점과 싱크 정점 사이 간선 추가 (비용 0)
        for(int i=1;i<=M;i++){
            c[i+WORK][E]=1;
            adj[i+WORK].push_back(E);
            adj[E].push_back(i+WORK);
        }
        
        for(int i=1;i<=N;i++){
            int num;// i번 직원이 할 수 있는 일의 개수 
            cin >> num;
            
            for(int j=1;j<=num;j++){
                int worknum,cost;
								// 할 수 있는 일의 번호, 지급해야 하는 월급
                cin >> worknum >> cost;
                
								// 간선 추가
                adj[i].push_back(worknum+WORK);
                adj[worknum+WORK].push_back(i);
                
								// 비용 갱신
                d[i][worknum+WORK]=cost;
                d[worknum+WORK][i]=-cost;
                
								//각 일을 담당하는 사람은 1명이므로 
                c[i][worknum+WORK]=1;
            }
        }
    }
    void solve(){
        // MCMF 시작
        while(1){
						// prev는 경로 저장에 쓰이며, dist는 최단 거리 구할 때 쓰인다. 
            int prev[MAX_V], dist[MAX_V];
            bool inQ[MAX_V] = {0}; // 해당 정점이 큐 안에 있는지 bool 배열로 관리
            queue<int> Q;
            fill(prev, prev+MAX_V, -1); // 이전 정점을 모두 -1로 초기화 
            fill(dist, dist+MAX_V, INF); // 거리를 모두 INF로 초기화 
            dist[S] = 0; 
            inQ[S] = true;
            Q.push(S);
            
            while(!Q.empty()){
                int curr = Q.front();
                Q.pop();
                inQ[curr] = false; // 큐에서 꺼냄
                for(int next: adj[curr]){
                    // 여유 용량이 있고 경로 갱신이 일어나는 경우에 
                    if(c[curr][next]-f[curr][next] > 0 && dist[next] > dist[curr]+d[curr][next]){
                        dist[next] = dist[curr] + d[curr][next];
                        prev[next] = curr;
                        // 큐에 들어있지 않다면 큐에 넣음
                        if(!inQ[next]){
                            Q.push(next);
                            inQ[next] = true;
                        }
                    }
                }
            }
            // 더 이상 경로가 없다면 루프 탈출
            if(prev[E] == -1) break;
            
            // 경로상에서 가장 residual이 작은 간선을 찾아 최대 흘릴 수 있는 flow 찾음
            int flow = INF;
            for(int i=E; i!=S; i=prev[i])
                flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
            
            // 경로상의 모든 간선에 flow만큼의 유량을 흘림
            for(int i=E; i!=S; i=prev[i]){
                result += flow * d[prev[i]][i]; // 총 비용이 각 간선 비용만큼 증가
                f[prev[i]][i] += flow;
                f[i][prev[i]] -= flow;
            }
            work++;
        }
        // 정답 출력
        cout << work << "\n" << result << "\n";
    }
    
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    MCMF mcmf;
    mcmf.solve();
    return 0;
}