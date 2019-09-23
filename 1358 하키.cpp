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


int main(){
    int w, h, x, y, p, x1, y1;
    int cnt = 0;
    cin >> w >> h >> x >> y >> p;

    Vector c1 = {x, y + h/2};
    Vector c2 = {x + w, y + h/2};

    for(int i = 0 ; i < p ; i++){
        cin >> x1 >> y1;
        Vector v = {x1, y1};
        if(x <= x1 and x1 <= x + w and y <= y1 and y1 <= y + h){
            cnt++;
        }        
        else if((c1 - v).size2() <= h/2 * h/2){
            cnt++;
        }
        else if((c2 - v).size2() <= h/2 * h/2){
            cnt++;
        }
    }

    cout << cnt;
}

