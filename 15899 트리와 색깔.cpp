#include <cstdio>
#include <vector>
#include <algorithm>

#define l_node (node<<1)
#define r_node (l_node+1)
#define mid ((begin+end)>>1)

#define MOD 1000000007

using namespace std;

typedef int ll;

struct SegmentTree {
    vector<ll> tree, lazy;
    
    SegmentTree(int size) {
        tree.resize(size<<2);
        lazy.resize(size<<2);
    }
    
    ll update(int node, int begin, int end, int l_pos, int r_pos, ll dif) {
        propagate(node, begin, end, lazy[node]);
        lazy[node] = 0;
        if (r_pos < begin || end < l_pos) return tree[node];
        if (l_pos <= begin && end <= r_pos) {
            propagate(node, begin, end, dif);
            return tree[node];
        }
        ll l = update(l_node, begin, mid, l_pos, r_pos, dif);
        ll r = update(r_node, mid+1, end, l_pos, r_pos, dif);
        return tree[node] = (l + r) % MOD;
    }
    
    ll query(int node, int begin, int end, int l_pos, int r_pos) {
        propagate(node, begin, end, lazy[node]);
        lazy[node] = 0;
        if (r_pos < begin || end < l_pos) return 0;
        if (l_pos <= begin && end <= r_pos) return tree[node];
        ll l = query(l_node, begin, mid, l_pos, r_pos);
        ll r = query(r_node, mid+1, end, l_pos, r_pos);
        return (l + r) % MOD;
    }
    
    void propagate(int node, int begin, int end, ll dif) {
        if (dif == 0) return;
        tree[node] += (end + 1 - begin) * dif;
        if (begin ^ end) {
            lazy[l_node] += dif;
            lazy[r_node] += dif;
        }
    }
};

struct HLD {
    SegmentTree st;
    vector<int> h, p, f, c;
    vector<vector<int> > adj;
    int size = 0;
    
    HLD(int size): st(size-1) {
        h.resize(size);
        p.resize(size);
        f.resize(size);
        c.resize(size);
        adj.resize(size);
    }
    
    int traverse1(int root) {
        c[root] = 1;
        for (auto child : adj[root]) {
            if (child ^ p[root]) {
                p[child] = root;
                c[root] += traverse1(child);
            }
        }
        return c[root];
    }
    
    void traverse2(int root) {
        int first = 0;
        for (auto child : adj[root])
            if (child ^ p[root] && c[first] < c[child])
                first = child;
        for (auto child : adj[root])
            if (child ^ p[root] && child ^ first)
                traverse2(child);
        if (h[root] == 0)
            h[root] = root;
        if (first) {
            h[first] = h[root];
            traverse2(first);
        }
        f[root] = ++size;
    }
    
    void update(int s, int d, ll dif) {
        if (f[s] > f[d]) swap(s, d);
        if (h[s] == h[d]) st.update(1, 1, size, f[s], f[d], dif);
        else {
            update(s, h[s], dif);
            update(p[h[s]], d, dif);
        }
    }
    
    ll query(int s, int d) {
        if (f[s] > f[d]) swap(s, d);
        if (h[s] == h[d]) return st.query(1, 1, size, f[s], f[d]);
        ll l = query(s, h[s]);
        ll r = query(p[h[s]], d);
        return (l + r) % MOD;
    }
};

struct Color{
	int idx, color;
};

bool cmp(Color &c1, Color &c2){
	return c1.color == c2.color ? c1.idx < c2.idx : c1.color < c2.color;
}

int main(){
	int n, m, c, ret = 0;
	scanf("%d%d%d", &n, &m, &c);
	
	HLD hld(n+1);
	vector<Color> v, q;

	v.resize(n);
	q.resize(m);
	
	for(int i = 0 ; i < n ; i++) {
		scanf("%d", &v[i].color);
		v[i].idx = i + 1;
	}

	for(int i = 0 ; i < n-1 ; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		hld.adj[a].push_back(b);
		hld.adj[b].push_back(a);
	}

	for(int i = 0 ; i < m ; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		q[i].idx = a;
		q[i].color = b;
	}
	hld.traverse1(1);
	hld.traverse2(1);

	sort(q.begin(), q.end(), cmp);
	sort(v.begin(), v.end(), cmp);

	int color_idx = 1;
	int p1 = 0;
	int p2 = 0;

	while(color_idx <= c) {
		for(; p1 < n ; p1++){
			if(v[p1].color == color_idx){
				hld.update(1, v[p1].idx, 1);
			}
			else break;
		}
		for(; p2 < m ; p2++){
			if(q[p2].color == color_idx){
				ret = (ret + hld.query(q[p2].idx, q[p2].idx)) % MOD;
			}
			else break;
		}
		color_idx++;
	}

	printf("%d", ret % MOD);

	return 0;
}