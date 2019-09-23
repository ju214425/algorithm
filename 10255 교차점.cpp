
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

typedef long long ll;

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
    Vector  operator *  (const ll a)        const {return Vector(x*a,y*a);}
    
    ll dot      (const Vector& a)   const {return x*a.x+y*a.y;}
    ll cross    (const Vector& a)   const {return x*a.y-y*a.x;}
    double size (void)              const {return sqrt(dot(*this));}
    ll size2    (void)              const {return dot(*this);}
};

struct LineSegment {
    Vector P, Q;
    LineSegment(){}
    LineSegment(Vector P, Vector Q) {
        if (Q < P) swap(P, Q);
        this->P = P;
        this->Q = Q;
    }
    int intersect(LineSegment a) {
        Vector p = Q - P;
        Vector q = a.Q - a.P;
        Vector r = a.P - P;
        ll det = p.cross(q);
        ll t1 = r.cross(q);
        ll t2 = r.cross(p);
        if (det == 0) { //평행 or 일치
            if (t1 != 0) return 0;  
            if (t2 != 0) return 0;
            if (Q < a.P) return 0;
            if (a.Q < P) return 0;
            return 100;
        }
        if (det < 0) {t1 *= -1; t2 *= -1; det *= -1;}
        if(0 == t1 or t1 == det or 0 == t2 or t2 == det)
        	return 1; //모서리 만남
        if(0 < t1 && t1 < det && 0 < t2 && t2 < det)
    		return 10; // 가운데에서 만
    	else return 0;
        // else return 0;
    }
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		int cnt = 0;
		int x1, y1, x2, y2;
		int lx1, ly1, lx2, ly2;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> lx1 >> ly1 >> lx2 >> ly2;
		LineSegment line({lx1, ly1}, {lx2, ly2});
		LineSegment l1({x1,y1}, {x1,y2});
		LineSegment l2({x1,y1}, {x2,y1});
		LineSegment l3({x1,y2}, {x2,y2});
		LineSegment l4({x2,y1}, {x2,y2});

		cnt += line.intersect(l1);
		cnt += line.intersect(l2);
		cnt += line.intersect(l3);
		cnt += line.intersect(l4);

		if(cnt >= 100) cout << "4\n";
		else if(cnt >= 10) cout << "2\n";
		else if(cnt >= 1) cout << "1\n";
		else cout << "0\n";
	}
}