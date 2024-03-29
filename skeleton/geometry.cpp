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

struct ClosestPair: PointSet {
    
    ClosestPair(int size): PointSet(size) {}
    
    auto closest_pairs() {
        sort(P.begin(), P.end(), [] (Vector &a, Vector &b) {
            return a.x == b.x ? a.y < b.y : a.x < b.x;
        });
        P.erase(unique(P.begin(), P.end()), P.end());
        set<Vector> SET = {P[0], P[1]};
        
        vector<PointSet> pairs = {{P[0], P[1]}};
        ll min = (P[0]-P[1]).size2();
        for (int i = 2, j = 0; i < P.size(); ++i) {
            Vector I = P[i];
            for (; j < i; ++j) {
                Vector J = P[j];
                Vector tmp = I-J;
                if (tmp.x * tmp.x < min) break;
                SET.erase(J);
            }
            
            ll d = sqrt(min) + 1;
            Vector D = {d, d};
            auto end = SET.upper_bound(I+D);
            for (auto it = SET.lower_bound(I-D); it != end; ++it) {
                Vector J = *it;
                ll tmp = (I-J).size2();
                
                if (tmp < min) {
                    pairs = {{I,J}};
                    min = tmp;
                } else if (tmp == min) {
                    pairs.push_back({I,J});
                }
            }
            SET.insert(I);
        }
        return pairs;
    }
};

struct FarthestPair: PointSet {
    FarthestPair(int size): PointSet(size) {}
    
    auto farthest_pairs() {
        auto hull = convex_hull();
        
        vector<PointSet> pairs = {{hull[0], hull[1]}};
        ll max = (hull[0]-hull[1]).size2();
        for (int i = 0, j = 1; i < hull.size(); ++i) {
            int ni = (i+1) % hull.size();
            Vector NI = hull[ni], I = hull[i], NJ, J;
            while (1) {
                int nj = (j+1) % hull.size();
                NJ = hull[nj]; J = hull[j];
                if ((NI-I).cross(NJ-J) > 0) j = nj;
                else break;
            }
            ll tmp = (I-J).size2();
            if(max < tmp) {
                pairs = {{I, J}};
                max = tmp;
            } else if (max == tmp) {
                pairs.push_back({I, J});
            }
        }
        for (auto pair: pairs) if (pair.P[0] < pair.P[1]) swap(pair.P[0], pair.P[1]);
        sort(pairs.begin(), pairs.end(), [](PointSet &a, PointSet &b){
            return a.P[0] == b.P[0] ? a.P[1] < b.P[1] : a.P[0] < b.P[0];
        });
        pairs.erase(unique(pairs.begin(), pairs.end(), [](PointSet &a, PointSet &b){
            return a.P[0] == b.P[0] && a.P[1] == b.P[1];
        }), pairs.end());
        return pairs;
    }
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
