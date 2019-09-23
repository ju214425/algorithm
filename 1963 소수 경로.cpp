#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> sieve() {
    vector<int> v;
    vector<int> ret;
    v.resize(10000);
    for (int i = 2; i < 10000; i++) {
        v[i] = i;
    }
    for (int i = 2; i < 10000; i++) {  // 나누는 값 : i
        for (int j = 2; j < 10000; j++) {
            if (v[j] != i && v[j] % i == 0) {  // 자신과 같지않고 0으로 떨어지면 소수아님
                v[j] = 0; // 소수가 아닌 경우 0을 넣어둔다
            }
        }
    }

    for (int i = 2; i < 10000; i++) {
        if (v[i] != 0)   
            ret.push_back(v[i]);
    }

    return ret;
}

int visit[10000];

int main(){
	int t;
	cin << t;
	vector<int> v = sieve();
	while(t--){
		queue<int> q;
		int a, b;
		cin << a << b;
		q.push(a);
		while(!q.empty()){
			int num = q.front();
			for(int i = 0 ; i < 10 ; i++){
				
			}
		}
	}
}