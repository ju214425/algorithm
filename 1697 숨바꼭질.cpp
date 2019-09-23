#include <iostream>
#include <queue>

using namespace std;

int cnt[100002];

int main(){
	int n, k, ans, cur;
	cin >> n >> k;
	queue<int> q;
	q.push(n);
	while(!q.empty()){
		cur = q.front();
		q.pop();
		if(cur == k){
			ans = cnt[cur];
			break;
		}
		if(cur - 1 >= 0 and cnt[cur-1] == 0){
			q.push(cur-1);
			cnt[cur-1] = cnt[cur]+1;
 		}
 		if(cur + 1 <= 100000 and cnt[cur+1] == 0){
			q.push(cur+1);
			cnt[cur+1] = cnt[cur]+1;
 		}
 		if(cur * 2 <= 100000 and cnt[cur*2] == 0){
			q.push(cur*2);
			cnt[cur*2] = cnt[cur]+1;
 		}
	}

	cout << ans << endl;
}