#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <cstdlib>
#include <cmath>
#include <algorithm>

#define INF 0x6fffffff

using namespace std;

typedef long long ll;

struct Vector {
    ll x, y;
    Vector(){}
    Vector(ll _x,ll _y):x(_x),y(_y){}
    
    bool    operator == (const Vector &a)   const {return x==a.x&&y==a.y;}
    bool    operator <  (const Vector &a)   const {return y==a.y?x<a.x:y<a.y;}
    Vector  operator +  (const Vector &a)   const {return {x+a.x,y+a.y};}
    Vector  operator -  (const Vector &a)   const {return {x-a.x,y-a.y};}
    Vector  operator -  (void)              const {return {-x,-y};}
    Vector  operator *  (const ll a)        const {return {x*a,y*a};}
    
    ll dot       (const Vector &a)   const {return x*a.x+y*a.y;}
    ll cross     (const Vector &a)   const {return x*a.y-y*a.x;}
    //double size  (void)              const {return sqrt(x*x+y*y);}
    ll size2     (void)              const {return x*x+y*y;}
    
    void print_info() {cout<<"("<<x<<","<<y<<")\n";}
};

struct PointSet {
    vector<Vector> P;
    
    PointSet(int size) {
        P.resize(size);
    }
    PointSet(Vector A, Vector B) {
        P.push_back(A);
        P.push_back(B);
    }
    
    auto convex_hull() {
        vector<Vector> hull;
        
        swap(P[0], *min_element(P.begin(), P.end()));
        for (int i = 1; i < P.size(); ++i) P[i] = P[i] - P[0];
        sort(P.begin()+1, P.end(), [] (const Vector &a, const Vector &b) {
            ll cr = a.cross(b);
            if (cr) return cr > 0;
            return a.y + abs(a.x) < b.y + abs(b.x);
        });
        for (int i = 1; i < P.size(); ++i) P[i] = P[i] + P[0];
        
        hull = {P[0]};
        for (int i = 1; i < P.size(); ++i) {
            while (1) {
                if (hull.size() <= 1) break;
                Vector back1 = hull.back(), back2 = hull[hull.size()-2];
                if ((back1-back2).cross(P[i]-back2) > 0) break;
                hull.pop_back();
            }
            hull.push_back(P[i]);
        }
        
        return hull;
    }
};

struct LineSegment: PointSet {
    LineSegment(Vector A, Vector B):PointSet(A, B){}
};

struct Polygon: PointSet {
    Polygon(int size):PointSet(size){}
};

struct Geometry {
    static bool intersect(LineSegment a, LineSegment b) {
        Vector p = a.P[1] - a.P[0];
        Vector q = b.P[1] - b.P[0];
        Vector r = b.P[0] - a.P[0];
        ll det = p.cross(q);
        ll t1 = r.cross(q);
        ll t2 = r.cross(p);
        if (det == 0) {
            if (t1 != 0 || t2 != 0) return 0; // 평행
            if (a.P[0] < a.P[1]) swap(a.P[0], a.P[1]);
            if (b.P[0] < b.P[1]) swap(b.P[0], b.P[1]);
            if (b.P[0] < a.P[1]) return 0; // 일부 겹침
            if (a.P[0] < b.P[1]) return 0; // 일부 겹침
            return 1; // 직선의 다른 부분
        }
        if (det<0) {
            t1*=-1;
            t2*=-1;
            det*=-1;
        }
        return 0<=t1&&t1<=det&&0<=t2&&t2<=det; // 한점에서 만남
    }
    
    static bool inside(Polygon a, Vector b) {
        int cn = 0;
        for (int i = 0; i < a.P.size(); ++i) {
            Vector I = a.P[i];
            int j = (i + 1) % a.P.size();
            Vector J = a.P[j];
            
            if (I == b) return 1;
            
            if (Geometry::intersect({I, J}, {b, {INF, b.y+1}}))
                cn++;
            
            if ((I-b).cross(J-b) == 0) {
                if (J < I) swap(I, J);
                if (I < b && b < J) return 1;
            }
        }
        return cn % 2;
    }
    
    static bool intersect(Polygon a, Polygon b) {
        if (inside(a, b.P[0])) return 0;
        if (inside(b, a.P[0])) return 0;
        for (int i1 = 0; i1 < a.P.size(); ++i1) {
            int j1 = (i1 + 1) % a.P.size();
            Vector I1 = a.P[i1];
            Vector J1 = a.P[j1];
            for (int i2 = 0; i2 < b.P.size(); ++i2) {
                int j2 = (i2 + 1) % b.P.size();
                Vector I2 = b.P[i2];
                Vector J2 = b.P[j2];
                if (intersect({I1, J1}, {I2, J2})) return 0;
            }
        }
        return 1;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    
    int n;
    cin >> n;

    Polygon poly(n);
    for(int i = 0 ; i < n ; i++){
        ll x, y;
        cin >> x >> y; 
        poly.P[i] = {x, y};
    }

    Geometry g;

    for(int i = 0 ; i < 3 ; i++){
        ll x, y;
        cin >> x >> y;
        cout << g.inside(poly, {x, y}) << "\n";
    }

}