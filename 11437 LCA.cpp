#include <cstdio>
#include <vector>
#include <algorithm>

#define l_node  (node<<1)
#define r_node  ((l_node)+1)
#define mid     ((begin+end)>>1)

typedef long long ll;

using namespace std;

struct SegmentTree {
    vector<ll> tree;
    
    SegmentTree(int size) {
        tree.resize(size<<2);
    }
    
    ll update(int node, int begin, int end, int pos, ll val) {
        if (pos < begin || end < pos) return tree[node];
        if (begin == end) return tree[node] = val;
        ll l_update = update(l_node, begin, mid, pos, val);
        ll r_update = update(r_node, mid+1, end, pos, val);
        return tree[node] = max(l_update, r_update);
    }
    
    ll query(int node, int begin, int end, int l_pos, int r_pos) {
        if (r_pos < begin || end < l_pos) return 0;
        if (l_pos <= begin && end <= r_pos) return tree[node];
        ll l_query = query(l_node, begin, mid, l_pos, r_pos);
        ll r_query = query(r_node, mid+1, end, l_pos, r_pos);
        return max(l_query, r_query);
    }
};

struct Edge {
    int c, p, w;
};

struct HLD {
    int size = 0;
    vector<Edge> e;
    vector<int> c, h, p, f;
    vector<vector<int> > adj;
    SegmentTree st;
    
    HLD(int size) : st(size-1) {
        // size == N+1
        // this->size == N
        e.resize(size);
        c.resize(size);
        h.resize(size);
        p.resize(size);
        f.resize(size);
        adj.resize(size);
    }
    
    int traverse1(int root) {
        c[root] = 1;
        for (int child : adj[root]) {
            if (child ^ p[root]) {
                p[child] = root;
                c[root] += traverse1(child);
            }
        }
        return c[root];
    }
    
    void traverse2(int root) {
        int first = 0;
        for (int child : adj[root])
            if (child ^ p[root]&& c[first] < c[child])
                first = child;
        for (int child : adj[root])
            if (child ^ p[root] && child ^ first)
                traverse2(child);
        if (!h[root])
            h[root] = root;
        if (first) {
            h[first] = h[root];
            traverse2(first);
        }
        f[root] = ++size;
    }
    
    void init() {
        for (int i = 1; i < size; ++i) {
            if (p[e[i].p] == e[i].c)
                swap(e[i].c, e[i].p);
            st.update(1, 1, size-1, f[e[i].c], e[i].w);
        }
        // sort(e.begin(), e.end());
    }
    
    ll query(int s, int d) {
        if (h[s] == h[d]) {
            if (f[s] > f[d]) swap(s, d);
            return st.query(1, 1, size-1, f[s], f[d]-1);
        }
        if (c[h[s]] > c[h[d]]) swap(s, d);
        ll temp1 = query(s, h[s]);
        ll temp2 = query(p[h[s]], d);
        ll temp3 = st.query(1, 1, size-1, f[h[s]], f[h[s]]);
        
        return max(temp1, max(temp2, temp3));
    }

    int LCA(int s, int d) {
        while(h[s] != h[d]) {
            if(c[h[s]] > c[h[d]]) swap(s, d);
            s = p[h[s]];    
        }
        if(c[s] < c[d]) swap(s,d);
        return s;
    }

    ll update(int idx, int val) {
        st.update(1, 1, size-1, f[e[idx].c], val);
    }
};


int main(int argc, const char * argv[]) {
    int N, M;
    scanf("%d", &N);
    HLD hld(N+1);
    for (int i = 1; i < N; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        hld.e[i].c = u;
        hld.e[i].p = v;
        hld.adj[u].push_back(v);
        hld.adj[v].push_back(u);
    }
    
    hld.traverse1(1);
    hld.traverse2(1);
    hld.init();
    
    scanf("%d", &M);
    for (; M--;) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", hld.LCA(a, b));
    }

    return 0;
}