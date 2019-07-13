#include <cstdio>
#include <vector>
#include <algorithm>

#define l_node (node<<1)
#define r_node (l_node+1)
#define mid ((begin+end)>>1)

using namespace std;

typedef long long ll;

struct SumSegmentTree {
    int size;
    
    vector<ll> tree;
    SumSegmentTree(int size): size(size) {
        this->size = size << 2;
        tree.resize(size << 2, 0);
    }
    
    ll update(int node, int begin, int end, int pos, ll val) {
        if (end < pos || pos < begin) return tree[node];
        if (begin == end) return tree[node] += val;
        ll l_update = update(l_node, begin, mid, pos, val);
        ll r_update = update(r_node, mid+1, end, pos ,val);
        return tree[node] = l_update + r_update;
    }

    ll query(int node, int begin, int end, int l_pos, int r_pos) {
        if (end < l_pos || r_pos < begin) return 0;
        if (l_pos <= begin && end <= r_pos) return tree[node];
        ll l_query = query(l_node, begin, mid, l_pos, r_pos);
        ll r_query = query(r_node, mid+1, end, l_pos, r_pos);
        return l_query + r_query;
    }
};

bool cmp(pair<int, int> &a, pair<int, int> &b){
        return a.second == b.second ? a.first < b.first : b.second < a.second;
}

int main() {
    int t, n, x, y;
    scanf("%d", &t);
    for(int i = 0 ; i < t ; i++) {
        ll sum = 0;
        scanf("%d", &n);
        vector<pair<int, int> > coord;
        vector<int> xpos;
        for(int j = 0 ; j < n ; j++) {
            scanf("%d%d", &x, &y);
            coord.push_back(pair<int, int> (x, y));
            xpos.push_back(x);
        }
        
        sort(xpos.begin(), xpos.end());
        xpos.erase(unique(xpos.begin(), xpos.end()), xpos.end());

        for(int j = 0 ; j < coord.size() ; ++j) {
            coord[j].first = (int)(lower_bound(xpos.begin(), xpos.end(), coord[j].first) - xpos.begin());
        }
        sort(coord.begin(), coord.end(), cmp);
        
        SumSegmentTree seg(int(xpos.size()));
        for(int j = 0 ; j < n ; ++j) {
            sum += seg.query(1, 0, xpos.size()-1, 0, coord[j].first);
            seg.update(1, 0, xpos.size()-1, coord[j].first, 1);
        }

        printf("%lli\n", sum);
    }
    return 0;
}