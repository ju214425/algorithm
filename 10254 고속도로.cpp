#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

typedef long long ll;

class Vector {
public:
    int x, y;
    Vector(){}
    Vector(int x_, int y_) : x(x_), y(y_) {}
    
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
    int size;
    
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
        ll max = 0;
        Vector A, B;
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

int main(){
    int t;
    int n;
    int x, y;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        FarthestPair fp(n);
        for(int i = 0 ; i < n ; i++){
            scanf("%d%d", &fp.P[i].x ,&fp.P[i].y);
        }
        fp.sort_points();
        fp.graham_scan();
        fp.rotating_calipers();
        
        Vector p1, p2;
        p1 = fp.farthest_pair[0];
        p2 = fp.farthest_pair[1];
        printf("%d %d %d %d\n", p1.x, p1.y, p2.x, p2.y);
    }
    return 0;
}