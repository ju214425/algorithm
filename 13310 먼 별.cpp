#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

typedef long long ll;

ll ans1 = 0, ans2 = 0;

class Vector {
public:
    ll x, y;
    Vector(){}
    Vector(ll x_, ll y_) : x(x_), y(y_) {}
    
    bool    operator == (const Vector& a)   const {return x==a.x&&y==a.y;}
    bool    operator <  (const Vector& a)   const {return y==a.y?x<a.x:y<a.y;}
    Vector  operator +  (const Vector& a)   const {return Vector(x+a.x,y+a.y);}
    Vector  operator -  (const Vector& a)   const {return Vector(x-a.x,y-a.y);}
    Vector  operator -  (void)              const {return Vector(-x,-y);}
    Vector  operator *  (const double a)    const {return Vector(x*a,y*a);}
    
    ll dot      (const Vector& a)   const {return (ll)x*a.x+(ll)y*a.y;}
    ll cross    (const Vector& a)   const {return (ll)x*a.y-(ll)y*a.x;}
    double size (void)              const {return sqrt(dot(*this));}
    ll size2    (void)              const {return dot(*this);}
};

struct PointSet {
    vector<Vector> P;
    Vector O;
    ll size;
    
    PointSet(int size) : size(size) {
        P.resize(size);
    }
    
    virtual void sort_points() = 0;
};


struct FarthestPair : public PointSet {
    vector<Vector> cvx;
    vector<Vector> farthest_pair;
    
    FarthestPair(int size) : PointSet(size) {}
    
    static bool cmp(Vector &a, Vector &b){
        ll cr = a.cross(b);
        if(cr) return cr > 0;
        return a.y + abs(a.x) < b.y + abs(b.x);
    }  

    virtual void sort_points() {
        // select (O)rigin and swap P[0]
        int o_idx = 0;
        for (int i = 1; i < size; ++i)
            if (!(P[o_idx] < P[i]))
                o_idx = i;
        swap(P[0], P[o_idx]);
        O = P[0];
        
        // sort Points by O (counter clock wise).
        for (int i = 1; i < size; ++i)
            P[i] = P[i] - O;
        sort(P.begin()+1, P.end(), cmp);
        for (int i = 1; i < size; ++i)
            P[i] = P[i] + O;
    }
    
    void graham_scan() {
        cvx.push_back(O);
        for (int i = 1; i < size; ++i) {
            while (1) {
                if (cvx.size() <= 1) break;
                Vector back1 = cvx.back(), back2 = cvx[cvx.size()-2];
                if ((back1-back2).cross(P[i]-back2) > 0) break;
                cvx.pop_back();
            }
            cvx.push_back(P[i]);
        }
    }
    
    void rotating_calipers() {
        Vector A = cvx[0], B = cvx[1];
        ll max = (A-B).size2();
        for (int i = 0, j = 1; i < cvx.size(); ++i) {
            int ni = (i+1) % cvx.size();
            Vector NI = cvx[ni], I = cvx[i], NJ, J;
            while (1) {
                int nj = (j+1) % cvx.size();
                NJ = cvx[nj]; J = cvx[j];
                if ((NI-I).cross(NJ-J) > 0) j = nj;
                else break;
            }
            ll tmp = (I-J).size2();
            if(max < tmp) {max = tmp; A = I; B = J;}
        }
        farthest_pair.push_back(A);
        farthest_pair.push_back(B);
    }
};


struct Point{
    int x, y, dx, dy;
};

ll func(vector<Point> p, int t){
    FarthestPair fp(p.size());
    for(int i = 0 ; i < p.size() ; i++){
        fp.P[i].x = p[i].x + t * p[i].dx;
        fp.P[i].y = p[i].y + t * p[i].dy;
    }    

    fp.sort_points();
    fp.graham_scan();
    fp.rotating_calipers();

    Vector ans = fp.farthest_pair[0] - fp.farthest_pair[1];

    return ans.size2();
}


void ternary_search(vector<Point> v, int lo, int hi){
    while(hi - lo >= 3){
        int p = (2 * lo + hi) / 3;
        int q = (lo + hi * 2) / 3;
        if(func(v, p) <= func(v, q)) hi = q;
        else lo = p;
        // printf("lo = %d, hi = %d \n", lo, hi);
    }
    
    ll min_val = 0x7fffffffffffffff;
    ll index = 0;
    for(int i = lo ; i <= hi ; i++){
        ll temp = func(v, i);
        if(temp < min_val){
            min_val = temp;
            index = i;
        }
    }

    ans1 = index;
    ans2 = min_val;
}

int main(){
    int n, t;
    scanf("%d%d", &n, &t);
    vector<Point> p(n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d%d%d%d", &p[i].x, &p[i].y, &p[i].dx, &p[i].dy);
    }
    
    ternary_search(p, 0, t);
    
    printf("%lli\n%lli\n", ans1, ans2);

    return 0;
}