#include <cstdio>
#include <vector>

#define mid ((begin+end)>>1)
#define l_node (node<<1)
#define r_node (l_node+1)

using namespace std;

struct SegmentTree {
    vector<long long> arr, lazy, tree;
    int MEANINGLESS;
    SegmentTree(int size) {
    	arr.resize(size + 1);
        lazy.resize(size<<2);
        tree.resize(size<<2);
    }
    
    long long init(int node, int begin, int end) {
        if (begin == end) return tree[node] = arr[begin];
        long long l_init = init(l_node, begin, mid);
        long long r_init = init(r_node, mid+1, end);
        return tree[node] = whichof(l_init, r_init);
    }
    
    long long query(int node, int begin, int end, int l_pos, int r_pos) {
        propagate(node, begin, end, lazy[node]);
        lazy[node] = MEANINGLESS;
        if (end < l_pos || r_pos < begin) return MEANINGLESS;
        if (l_pos <= begin && end <= r_pos) return tree[node];
        long long l_query = query(l_node, begin, mid, l_pos, r_pos);
        long long r_query = query(r_node, mid+1, end, l_pos, r_pos);
        return whichof(l_query, r_query);
    }
    
    long long update_range(int node, int begin, int end, int l_pos, int r_pos, long long diff) {
    	propagate(node, begin, end, lazy[node]);
    	lazy[node] = MEANINGLESS;
    	if(end < l_pos || r_pos < begin) return tree[node];
    	if(l_pos <= begin && end <= r_pos) {
    		propagate(node, begin, end, diff);
    		return tree[node];
    	}
    	long long l_update = update_range(l_node, begin, mid, l_pos, r_pos, diff);
    	long long r_update = update_range(r_node, mid+1, end, l_pos, r_pos, diff);
    	return tree[node] = whichof(l_update, r_update);
    }

    virtual long long whichof(long long l, long long r) = 0;
    virtual void propagate(int node, int begin, int end, long long diff) = 0;
    /* modified part*/
};

struct SumSegmentTree: public SegmentTree {
	SumSegmentTree(int size) : SegmentTree(size) {
		MEANINGLESS = 0;
	}

	virtual long long whichof(long long l, long long r) {
		return l + r;
	}

	virtual void propagate(int node, int begin, int end, long long diff) {
		tree[node] += ((end - begin + 1) * diff);
		if(begin ^ end) {
			lazy[l_node] += diff;
			lazy[r_node] += diff;
		}
	}

};

int main(){
	int N, M, K, a, b, c;
	long long d;
	scanf("%d %d %d", &N, &M, &K);
	SumSegmentTree seg(N);
	for(int i = 1 ; i <= N ; i++){
		scanf("%lli", &seg.arr[i]);
	}
	seg.init(1, 1, N);
	while((M + K) != 0){
		scanf("%d", &a);
		if(a == 1) {
			scanf("%d %d %lli", &b, &c, &d);
			seg.update_range(1, 1, N, b, c, d);
			M--;
		}
		else if(a == 2) {
			scanf("%d %d", &b, &c);
			printf("%lli\n", seg.query(1, 1, N, b, c));
			K--;
		}
	}
}