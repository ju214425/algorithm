#include <cstdio>
#include <vector>

#define mid ((begin+end)>>1)
#define l_node (node<<1)
#define r_node (l_node+1)

using namespace std;

typedef long long ll;

struct SegmentTree {
    vector<long long> arr, tree, lazy;
    int MEANINGLESS;
    SegmentTree(int size) {
        arr.resize(size+1);
        lazy.resize(size<<2);
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

    void print(){
        for(int i = 0 ; i < int(tree.size()); i++){
            printf("%lli ", tree[i]);
        }
    }
    virtual ll whichof(ll l, ll r) = 0;
    virtual void propagate(int node, int begin, int end, ll diff) = 0;
};

struct XorSegmentTree: public SegmentTree {
	XorSegmentTree(int size) : SegmentTree(size) {
		MEANINGLESS = 0;
	}

	virtual ll whichof(ll l, ll r) {
		return l^r;
	}

	virtual void propagate(int node, int begin, int end, ll diff) {
        if(diff != 0) {
            if((end - begin + 1) % 2 == 1) {
                tree[node] ^= diff;
            }
            if(begin ^ end) {
                lazy[l_node] ^= diff;
                lazy[r_node] ^= diff;
            }

            lazy[node] = 0;
        }

	}
};

int main(){
    int n, m;
    scanf("%d", &n);
    XorSegmentTree seg(n);
    for(int i = 1 ; i <= n ; i++){
        scanf("%lli", &seg.arr[i]);
    }
    seg.init(1, 1, n);
    scanf("%d", &m);
    for(int i = 0 ; i < m ; i++) {
        int t, a, b, c;
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d%d%d", &a, &b, &c);
            seg.update_range(1, 1, n, min(a+1, b+1), max(a+1, b+1), c);
        }

        if (t == 2) {
            scanf("%d%d", &a, &b);
            printf("%lli\n", seg.query(1, 1, n, min(a+1, b+1), max(a+1, b+1)));
        }
        
    }

    return 0;
}