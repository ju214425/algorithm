#include <cstdio>
#include <vector>

#define mid ((begin+end)>>1)
#define l_node (node<<1)
#define r_node (l_node+1)

using namespace std;

typedef long long ll;

struct SegmentTree {
    vector<int> tree;
    vector<int> lazy;
    int MEANINGLESS;
    SegmentTree(int size) {
        lazy.resize(size<<2, 0);
        tree.resize(size<<2);
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

struct SumSegmentTree: public SegmentTree {
	SumSegmentTree(int size) : SegmentTree(size) {
		MEANINGLESS = 0;
	}

	virtual ll whichof(ll l, ll r) {
		return l + r;
	}

	virtual void propagate(int node, int begin, int end, ll diff) {
        //if diff == 0 do nothing
        if(diff != 0){
    		tree[node] = ((end - begin + 1)) - tree[node];
    		if(begin ^ end) {
    			lazy[l_node] = not lazy[l_node];
    			lazy[r_node] = not lazy[r_node];
    		}
        }
	}

};

int main(){
	int N, M;
    scanf("%d%d", &N, &M);
    SumSegmentTree seg(N);
    for(int i = 0 ; i < M ; i++){
        int O, S, T;
        scanf("%d%d%d", &O, &S, &T);
        if(O == 0){
            seg.update_range(1, 1, N, S, T, 1);
        }
        else if(O == 1){
            printf("%lli\n", seg.query(1, 1, N, S, T));
        }
    }
}