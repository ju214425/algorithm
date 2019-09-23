#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <cstdlib>
#include <cmath>
#include <algorithm>

#define INF 0x6fffffff

typedef long long ll;

using namespace std;

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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    ClosestPair CP(n);

    for(int i = 0 ; i < n ; i++){
        cin >> CP.P[i].x >> CP.P[i].y;
    }

    auto v = CP.closest_pairs();
    
    cout << (v[0].P[0] - v[0].P[1]).size2() << "\n";
}