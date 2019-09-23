#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

struct Point{
    int x, y, z;
};

double length(Point p1, Point p2){
    double dx = p1.x-p2.x;
    double dy = p1.y-p2.y;
    double dz = p1.z-p2.z;

    return sqrt(dx*dx + dy*dy + dz*dz);
}

double surface(double l1, double l2, double l3){
    double s = (l1 + l2 + l3) / 2;
    return sqrt(s * (s-l1) * (s-l2) * (s-l3));
}

int main(){
    int x, y, z;
    double AB, BC, CA;
    double s, len, ans;
    Point p[3];
    for(int i = 0 ; i < 3 ; i++){
        scanf("%d%d%d", &x, &y, &z);
        p[i].x = x;
        p[i].y = y;
        p[i].z = z;
    }
    
    AB = length(p[0],p[1]);
    BC = length(p[1],p[2]);
    CA = length(p[2],p[0]);
    s = surface(AB, BC, CA);
    if(s == 0){
        if(AB == BC + CA) ans = 0;
        else{
            ans = min(BC, CA);
        }
    }
    else{
        len = (2 * s) / AB;
        double small, m, large;
        small = min(min(AB, BC), CA);
        large = max(max(AB, BC), CA);
        if(small == AB){
            if(large == BC) m = CA;
            else m = BC;
        }
        else if(small == BC){
            if(large == CA) m = AB;
            else m = CA;
        }
        else if(small == CA){
            if(large == AB) m = BC;
            else m = AB;
        }
        if(large*large > small*small + m*m){
            if(large != AB)
                ans = min(BC, CA);
            else{
                ans = len;
            }
        }
        else{
            ans = len;
        }
    }
    printf("%.10f", ans);
}