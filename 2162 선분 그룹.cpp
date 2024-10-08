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
        if (det == 0) {				
            if (t1 != 0) return 0;	 
            if (t2 != 0) return 0;	
            if (Q < a.P) return 0;	
            if (a.Q < P) return 0;	
            return 1;
        }
        else if (det < 0) {
            t1 *= -1; t2 *= -1; det *= -1;
        }
        return 0 <= t1 && t1 <= det && 0 <= t2 && t2 <= det;
    }
};

vector<vector<int> > adj;
vector<int> visit;
int numofgroup = 0;
int maxofmember = 0;

int dfs(int node) {
    if (visit[node]) return 0;
    visit[node] = 1;
    int ret = 1;
    for (int i = 0; i < adj[node].size(); ++i) {
        ret += dfs(adj[node][i]);
    }
    return ret;
}

int main() {
	int n;
	scanf("%d", &n);
	LineSegment lines[n];
	for(int i = 0 ; i < n ; ++i) {
		int x1, x2, y1, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		lines[i] = LineSegment(Vector(x1, y1), Vector(x2, y2));
	}

	adj.resize(n);
	visit.resize(n, 0);

	for(int i = 0 ; i < n-1 ; ++i) {
		for(int j = i+1 ; j < n ; ++j) {
			if(lines[i].intersect(lines[j])) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	for(int i = 0 ; i < n ; ++i) {
		int num = dfs(i);
		if(0 < num) numofgroup++;
		if(maxofmember < num) maxofmember = num;
	}

	printf("%d\n%d", numofgroup, maxofmember);

	return 0;
}