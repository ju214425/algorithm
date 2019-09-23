#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

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
    ll size2    (void)              const {return dot(*this);}
};

int main(){
	int x1,x2,x3,y1,y2,y3;

	vector<Vector> v(3);
	for(int i = 0 ; i < 3 ; i++){
		cin >> v[i].x >> v[i].y;
	}

	Vector a = v[0] - v[1];
	Vector b = v[1] - v[2];
	Vector c = v[2] - v[0];
	
	double a1 = sqrt(a.size2());
	double b1 = sqrt(b.size2());
	double c1 = sqrt(c.size2());
	

	double minimum = min(min(a1 + b1, b1 + c1), c1 + a1);
	double maximum = max(max(a1 + b1, b1 + c1), c1 + a1);

	if(a.cross(b) == 0 or b.cross(c) == 0 or c.cross(a) == 0){
		cout << "-1\n";
	}
	else{
		printf("%.17lf\n", 2 * (maximum - minimum));
	}
}
