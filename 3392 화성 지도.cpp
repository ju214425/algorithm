#include <cstdio>
#include <vector>

#define mid ((begin+end)>>1)
#define l_node (node<<1)
#define r_node (l_node+1)

#define DIV 1000000007

using namespace std;

typedef long long ll;

struct line {
    int x1, x2, y, diff;
}

struct SegmentTree {
    vector<long long> arr, tree, lazy;
    int MEANINGLESS;
    SegmentTree(int size) {
        arr.resize(size+1);
        lazy.resize(size<<2, 0);
        tree.resize(size<<2);
    }

    ll init(int node, int begin, int end) {
        if (begin == end) return tree[node] = arr[begin];
        ll l_init = init(l_node, begin, mid);
        ll r_init = init(r_node, mid+1, end);
        return tree[node] = whichof(l_init, r_init);
    }

    ll update_range(int node, int begin, int end, int l_pos, int r_pos, ll diff) {
        propagate(node, begin, end, lazy[node]);
        lazy[node] = MEANINGLESS;
        if(end < l_pos || r_pos < begin) return tree[node];
        if(l_pos <= begin && end <= r_pos) {
            propagate(node, begin, end, diff);
            return tree[node];
        }
        ll l_update = update_range(l_node, begin, mid, l_pos, r_pos, diff);
        ll r_update = update_range(r_node, mid+1, end, l_pos, r_pos, diff);
        return tree[node] = whichof(l_update, r_update);
    }
    
    ll query(int node, int begin, int end, int l_pos, int r_pos) {
        propagate(node, begin, end, lazy[node]);
        lazy[node] = MEANINGLESS;
        if (end < l_pos || r_pos < begin) return MEANINGLESS;
        if (l_pos <= begin && end <= r_pos) return tree[node];
        ll l_query = query(l_node, begin, mid, l_pos, r_pos);
        ll r_query = query(r_node, mid+1, end, l_pos, r_pos);
        return whichof(l_query, r_query);
    }

    virtual ll whichof(ll l, ll r) = 0;
    virtual void propagate(int node, int begin, int end, ll diff) = 0;
};

int main(){
    int n, x1, x2, y1, y2;
    scanf("%d", &n);
    vector<line> lines;
    vector<coord> coords; 
    lines.resize(2*n-1);
    for(int i = 0 ; i < n ; i++) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        lines.
    }
}




