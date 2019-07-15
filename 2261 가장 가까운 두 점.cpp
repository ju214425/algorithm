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


struct ClosestPair : public PointSet {
    vector<Vector> closest_pair;
    
    ClosestPair(int size) : PointSet(size) {}
    
    static bool cmp(Vector &a, Vector &b){
        return a.x == b.x ? a.y < b.y : a.x < b.x;
    }

    virtual void sort_points() {
        sort(P.begin(), P.end(), cmp);
    }
    
    void sweeping() {
        set<Vector> SET;
        SET.insert(P[0]);
        SET.insert(P[1]);
        Vector A = P[0], B = P[1];
        ll min = (A-B).size2();
        
        for (int i = 2, j = 0; i < size; ++i) {
            Vector I = P[i];
            for (; j < i; ++j) {
                Vector J = P[j];
                if ((I-J).x * (I-J).x < min) break;
                SET.erase(J);
            }
            
            int d = sqrt(min) + 1;
            Vector D;
            D.x = d;
            D.y = d;

            auto begin = SET.lower_bound(I-D);
            auto end = SET.upper_bound(I+D);
            
            for (auto it = begin; it != end; ++it) {
                Vector J = *it;
                ll tmp = (I-J).size2();
                if (tmp < min) {min = tmp; A = I; B = J;}
            }
            SET.insert(I);
        }
        closest_pair.push_back(A);
        closest_pair.push_back(B);
    }
};

int main(){
    int n;
    scanf("%d", &n);
    ClosestPair cp(n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d%d", &cp.P[i].x, &cp.P[i].y);
    }

    cp.sort_points();
    cp.sweeping();

    Vector ans = cp.closest_pair[0] - cp.closest_pair[1];
    printf("%d\n", ans.size2());

    return 0;
}