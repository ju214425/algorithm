#include <iostream>
#include <vector>

#define mid ((begin+end)>>1)
#define l_node (node<<1)
#define r_node (l_node+1)

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
    
    ll update(int node, int begin, int end, int pos, ll val) {
        if (end < pos || pos < begin) return tree[node];
        if (begin == end) return tree[node] = val;
        ll l_update = update(l_node, begin, mid, pos, val);
        ll r_update = update(r_node, mid+1, end, pos, val);
        return tree[node] = whichof(l_update, r_update);
    }

    ll query(int node, int begin, int end, int l_pos, int r_pos) {
        if (end < l_pos || r_pos < begin) return MEANINGLESS;
        if (l_pos <= begin && end <= r_pos) return tree[node];
        ll l_query = query(l_node, begin, mid, l_pos, r_pos);
        ll r_query = query(r_node, mid+1, end, l_pos, r_pos);
        return whichof(l_query, r_query);
    }

    virtual ll whichof(ll l, ll r) = 0;
};

struct SumSegmentTree: public SegmentTree {
	SumSegmentTree(int size) : SegmentTree(size) {
		MEANINGLESS = 0;
	}
	virtual ll whichof(ll l, ll r) {
		if (l == MEANINGLESS) return r;
		if (r == MEANINGLESS) return l;
		return (r + l);
  
	}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;
	SumSegmentTree st(n);
	for(int i = 1 ; i <= n ; i++){
		cin >> st.arr[i];
	}

	st.init(1,1,n);

	for(int i = 1 ; i <= q ; i++){
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		if(x > y) swap(x, y);
		cout << st.query(1, 1, n, x, y) << "\n";
		st.update(1, 1, n, a, b);
	}
}