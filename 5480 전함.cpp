#include <cstdio>
#include <vector>
#include <algorithm>

#define l_node (node<<1)
#define r_node (l_node+1)
#define mid ((begin+end)>>1)

#define MOD 1000000007

#define INF 987654321

using namespace std;

typedef int ll;

struct Battleship {
    int x1, y1, x2, y2, w;
};

struct Lazer {
    int a, b;
};

struct SegmentTree {
    vector<ll> tree;
    
    SegmentTree(int size) {
        tree.resize(size<<2, INF);
    }
    
    ll update(int node, int begin, int end, int pos, ll val) {
        if (pos < begin || end < pos) return tree[node];
        if (pos <= begin && end <= pos) return tree[node] = val;
        ll l = update(l_node, begin, mid, pos, val);
        ll r = update(r_node, mid+1, end, pos, val);
        return tree[node] = min(l, r);
    }
    
    ll query(int node, int begin, int end, int l_pos, int r_pos) {
        if (r_pos < begin || end < l_pos) return INF;
        if (l_pos <= begin && end <= r_pos) return tree[node];
        ll l = query(l_node, begin, mid, l_pos, r_pos);
        ll r = query(r_node, mid+1, end, l_pos, r_pos);
        return min(l, r);
    }
};

void print(vector<ll> &a){
    for(int i = 1 ; i <= a.size() ; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(){
    int t, n, k, l;
    int x1, x2, y1, y2, w;
    int a, b;
    scanf("%d", &t);
    for(int i = 0 ; i < t ; i++) {
        scanf("%d%d%d", &n, &k, &l);

        vector<Battleship> bs(k+1);
        vector<Lazer> lz(l+1);
        vector<int> ans(l+1);
        vector<int> cox, coy;

        for(int j = 1 ; j <= k ; j++) {
            scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &w);
            if(x1 > x2) swap(x1, x2);
            if(y1 > y2) swap(y1, y2);
            bs[j].x1 = x1; bs[j].x2 = x2;
            bs[j].y1 = y1; bs[j].y2 = y2; bs[j].w = w;
            cox.push_back(x1); cox.push_back(x2);
            coy.push_back(y1); coy.push_back(y2);
        }
        
        for(int j = 1 ; j <= l ; j++) {
            scanf("%d%d", &a, &b);
            lz[j].a = a; lz[j].b = b;
            if(b == 0)
                coy.push_back(a);
            else
                cox.push_back(a);
        }

        sort(cox.begin(), cox.end());
        sort(coy.begin(), coy.end());
        
        cox.erase(unique(cox.begin(), cox.end()), cox.end());
        coy.erase(unique(coy.begin(), coy.end()), coy.end());

        SegmentTree segX(cox.size()+1);
        SegmentTree segY(coy.size()+1);
        
        for(int j = 1 ; j <= k ; j++) {
            bs[j].x1 = (int)(lower_bound(cox.begin(), cox.end(), bs[j].x1) - cox.begin());
            bs[j].x2 = (int)(lower_bound(cox.begin(), cox.end(), bs[j].x2) - cox.begin());
            bs[j].y1 = (int)(lower_bound(coy.begin(), coy.end(), bs[j].y1) - coy.begin());
            bs[j].y2 = (int)(lower_bound(coy.begin(), coy.end(), bs[j].y2) - coy.begin());
        }
        
        for(int j = 1 ; j <= l ; j++){
            if(lz[j].b == 0)
                lz[j].a = (int)(lower_bound(coy.begin(), coy.end(), lz[j].a) - coy.begin());
            else
                lz[j].a = (int)(lower_bound(cox.begin(), cox.end(), lz[j].a) - cox.begin());
        }

        for(int j = l ; j >= 1 ; j--) {
            if(lz[j].b == 0){ // 수평 발사
                segY.update(1, 0, coy.size(), lz[j].a, j);
            }
            else { // 수직 발사
                segX.update(1, 0, cox.size(), lz[j].a, j);
            }
        }

        for(int j = 1 ; j <= k ; j++) {
            int xVal = segX.query(1, 0, cox.size(), bs[j].x1, bs[j].x2);
            int yVal = segY.query(1, 0, coy.size(), bs[j].y1, bs[j].y2);
            int val = min(xVal, yVal);
            if(val != INF)
                ans[val] = max(ans[val], bs[j].w);
        }

        for(int j = 1 ; j <= l ; j++) {
            printf("%d\n", ans[j]);
        }
    }

    return 0;
}
