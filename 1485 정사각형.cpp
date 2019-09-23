#include <iostream>
#include <vector>
#include <algorithm>

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
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		vector<Vector> v(4);
		for(int i = 0 ; i < 4 ; i++){
			cin >> v[i].x >> v[i].y;
		}

		sort(v.begin(), v.end());
		
		if(v[0] + v[3] == v[1] + v[2]){
			if((v[1] - v[0]).dot(v[2] - v[0]) == 0){
				if((v[1] - v[0]).size2() == (v[2] - v[0]).size2()){
					cout << 1 << "\n";
					continue;
				}
			}
		}
		cout << 0 << "\n";
		
	}
}