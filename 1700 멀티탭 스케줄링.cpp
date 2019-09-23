#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

#define INF 0x7fffffff
#define MOD 1000000000

using namespace std;

typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, K; cin >> N >> K;
    vector<int> arr(K);
    for (int i = 0; i < K; ++i) {
        cin >> arr[i];
    }
    
    vector<int> nextof(K);
    for (int i = 1; i <= K; ++i) {
        int next = INF;
        for (int k = K-1; k >= 0; --k) {
            if (arr[k] == i) {
                nextof[k] = next;
                next = k;
            }
        }
    }
    //        for (int i = 0; i < K; ++i) {
    //            printf("nextof[%d] : %d\n", i, nextof[i]);
    //        }
    int answer = 0;
    vector<bool> inq(K+1);
    int cnt = 0;
    vector<int> f(K+1);
    for (int i = 0; i < K; ++i) {
        if (cnt < N) {
            if (inq[arr[i]]) {
                printf("%d is already in q\n", arr[i]);
            } else {
                inq[arr[i]] = 1;
                cnt++;
                printf("push %d\n", arr[i]);
            }
        } else {
            if (inq[arr[i]]) {
                printf("%d is already in q\n", arr[i]);
            } else {
                int idx = 1;
                for (int j = 1; j <= K; ++j) {
                    if (inq[j] && f[j] > f[idx])
                        idx = j;
                }
                
                inq[idx] = 0;
                inq[arr[i]] = 1;
                answer++;
                //                    printf("f[%d] : %d, f[%d] : %d\n", idx, f[idx], arr[i], f[arr[i]]);
                printf("replace %d -> %d\n", idx, arr[i]);
            }
        }
        f[arr[i]] = nextof[i];
    }
    cout << answer << endl;
    
}