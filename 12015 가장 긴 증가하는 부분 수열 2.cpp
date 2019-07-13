#include <cstdio>
#include <vector>
#include <algorithm>

#define l_node (node<<1)
#define r_node (l_node+1)
#define mid ((begin+end)>>1)

using namespace std;

typedef long long ll;

struct Node{
	int val, idx;
};

struct SegmentTree {
    int size;
    
    vector<ll> tree;
    SegmentTree(int size): size(size) {
        this->size = size << 2;
        tree.resize(size << 2, 0);
    }
    
    ll update(int node, int begin, int end, int pos, ll val) {
        if (end < pos || pos < begin) return tree[node];
        if (begin == end) return tree[node] += val;
        ll l_update = update(l_node, begin, mid, pos, val);
        ll r_update = update(r_node, mid+1, end, pos ,val);
        return tree[node] = max(l_update, r_update);
    }

    ll query(int node, int begin, int end, int l_pos, int r_pos) {
        if (end < l_pos || r_pos < begin) return 0;
        if (l_pos <= begin && end <= r_pos) return tree[node];
        ll l_query = query(l_node, begin, mid, l_pos, r_pos);
        ll r_query = query(r_node, mid+1, end, l_pos, r_pos);
        return max(l_query, r_query);
    }
};

bool cmp(Node &a, Node &b){
    return a.val == b.val ? b.idx < a.idx : a.val < b.val;
}



int main() {
	int n;
	scanf("%d", &n);
	vector<Node> v;
	v.resize(n);
	SegmentTree seg(n+1);
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &v[i].val);
		v[i].idx = i+1;
	}

	sort(v.begin(), v.end(), cmp);

	for(int i = 1 ; i <= n ; i++){
		ll val = seg.query(1, 1, n, 1, v[i-1].idx-1);
		seg.update(1, 1, n, v[i-1].idx, val+1);
	}

	printf("%lli", seg.tree[1]);

    return 0;
}