ㅃㅂ#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int visit[1001];
int arr[1001];

void clear(){
	for(int i = 1 ; i <= 1000 ; i++){
		visit[i] = 0;
		arr[i] = 0;
	}
}

void dfs(int number){
	if(visit[number] == 1){
		return;
	}
	visit[number] = 1;
	dfs(arr[number]);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, n, cnt;
	cin >> t;
	while(t--){
		cin >> n;
		cnt = 0;
		clear();
		for(int i = 1 ; i <= n ; i++){
			cin >> arr[i];
		}

		for(int i = 1 ; i <= n ; i++){
			if(visit[i] == 0){
				dfs(i);
				cnt++;
			}
		}

		cout << cnt << "\n";
	}
}