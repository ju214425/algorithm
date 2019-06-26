#include <cstdio>
#include <vector>

#define mid ((begin+end)>>1)
#define l_node (node<<1)
#define r_node (l_node+1)

#define DIV 1000000007

using namespace std;

typedef long long ll;

struct SegmentTree {
    vector<ll> arr;
    vector<ll> tree;
    int MEANINGLESS;
    SegmentTree(int size) {
        arr.resize(size+1);
        tree.resize(size<<2);
    }
    
    ll init(int node, int begin, int end) {
        if (begin == end) return tree[node] = arr[begin];
        ll l_init = init(l_node, begin, mid);
        ll r_init = init(r_node, mid+1, end);
        return tree[node] = whichof(l_init, r_init);
    }
    
    ll query(int node, int begin, int end, int l_pos, int r_pos) {
        if (end < l_pos || r_pos < begin) return MEANINGLESS;
        if (l_pos <= begin && end <= r_pos) return tree[node];
        ll l_query = query(l_node, begin, mid, l_pos, r_pos);
        ll r_query = query(r_node, mid+1, end, l_pos, r_pos);
        return whichof(l_query, r_query);
    }
    
    ll update(int node, int begin, int end, int index, ll number) {
    	if (end < index || index < begin) return tree[node];
    	if (begin == end) return tree[node] = number;
        ll l_update = update(l_node, begin, mid, index, number);
        ll r_update = update(r_node, mid+1, end, index, number);
    	return tree[node] = whichof(l_update, r_update);
    }

    virtual ll whichof(ll l, ll r) = 0;
};

struct MulSegmentTree: public SegmentTree {
	MulSegmentTree(int size) : SegmentTree(size) {
		MEANINGLESS = 1;
	}
	virtual ll whichof(ll l, ll r) {
		if (l == MEANINGLESS) return r;
		if (r == MEANINGLESS) return l;
		return ((r % DIV) * (l % DIV)) % DIV;
  
	}
};

int main(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	MulSegmentTree seg(n);
	for(int i = 1 ; i <= n ; i++) {
		scanf("%lli", &seg.arr[i]);
	}
	seg.init(1,1,n);
	for(int i = 0 ; i < m + k ; i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if(a == 1){
			seg.update(1,1,n,b,c);
		}
		else if(a == 2){
			printf("%lli\n", seg.query(1,1,n,b,c)%DIV);
		}
	}
    return 0;
}