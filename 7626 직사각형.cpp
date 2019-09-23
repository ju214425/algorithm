#include <cstdio>
#include <vector>
#include <algorithm>

#define l_node (node<<1)
#define r_node (l_node+1)
#define mid ((begin+end)>>1)

using namespace std;

typedef long long ll;

struct SegmentTree {
    vector<ll> arr;
    vector<ll> tree, lazy;
    int MEANINGLESS;
    
    SegmentTree(int size) {
        arr.resize(size+1);
        tree.resize(size<<2);
        lazy.resize(size<<2);
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
        if (r_pos < begin || end < l_pos) return tree[node];
        if (l_pos <= begin && end <= r_pos) {
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
        if (r_pos < begin || end < l_pos) return MEANINGLESS;
        if (l_pos <= begin && end <= r_pos) return tree[node];
        ll l_query = query(l_node, begin, mid, l_pos, r_pos);
        ll r_query = query(r_node, mid+1, end, l_pos, r_pos);
        return whichof(l_query, r_query);
    }
    
    virtual ll whichof(ll l, ll r) = 0;
    virtual void propagate(int node, int begin, int end, ll diff) = 0;
};

struct SumSegmentTree : public SegmentTree {
    SumSegmentTree(int size): SegmentTree(size) {
        MEANINGLESS = 0;
    }
    
    virtual ll whichof(ll l, ll r) {
        return (l + r);
    }
    
    virtual void propagate(int node, int begin, int end, ll dif) {
        tree[node] += (end - begin +1) * dif;
        if (begin != end) {
            lazy[l_node] += dif;
            lazy[r_node] += dif;
        }
    }
};

struct Line{
	int y1, y2, xpos, cnt;

	Line(int y1, int y2, int x, int c){
		y1 = y1;
		y2 = y2;
		xpos = x;
		cnt = c;
	}
};

void print(vector<int> v){
	for(int i = 0 ; i < v.size() ; i++){
		printf("%d\n", v[i]);
	}
	printf("\n");
} 

bool cmp(Line l1, Line l2){
	return l1.xpos < l2.xpos;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> xpos, ypos;
	vector<int> xidx, yidx;
	vector<Line> line;
	
	for(int i = 0 ; i < n ; i++){
		int x1, x2, y1, y2;
		scanf("%d%d%d%d", &x1, &x2, &y1, &y2);
		line.push_back(Line(y1, y2, x1, 1));
		line.push_back(Line(y1, y2, x2, -1));
		xpos.push_back(x1);
		xpos.push_back(x2);
		ypos.push_back(y1);
		ypos.push_back(y2);
		xidx.push_back(x1);
		xidx.push_back(x2);
		yidx.push_back(y1);
		yidx.push_back(y2);
	}

	sort(line.begin(), line.end(), cmp);
	sort(xpos.begin(), xpos.end());
	sort(ypos.begin(), ypos.end());
	sort(xidx.begin(), xidx.end());
	sort(yidx.begin(), yidx.end());
	xidx.erase(unique(xidx.begin(), xidx.end()), xidx.end());
	yidx.erase(unique(yidx.begin(), yidx.end()), yidx.end());
	xpos.erase(unique(xpos.begin(), xpos.end()), xpos.end());
	ypos.erase(unique(ypos.begin(), ypos.end()), ypos.end());

	for(int i = 0 ; i < xidx.size() ; i++){
		xidx[i] = (int)(lower_bound(xidx.begin(), xidx.end(), xpos[i]) - xidx.begin());
	}
	
	for(int i = 0 ; i < yidx.size() ; i++){
		yidx[i] = (int)(lower_bound(yidx.begin(), yidx.end(), ypos[i]) - yidx.begin());
	}

	int size = yidx.size();
	SumSegmentTree st(size-1);

	for(int i = 1 ; i < size ; i++){
		st.arr[i] = ypos[i] - ypos[i-1];
	}

	st.init(1, 1, size);
	ll ans = 0;
	for(int i = 1 ; i < line.size() ; i++){
		ans += (st.query(1, 1, size-1, 1, size-1) * (line[i].xpos - line[i-1].xpos));
		st.update_range(1, 1, size-1, line[i].y1, line[i].y2, line[i].cnt);
	}

	printf("%lli", ans);
}