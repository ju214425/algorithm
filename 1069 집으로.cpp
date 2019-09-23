#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int x, y, d, t;
    cin >> x >> y >> d >> t;
    
    double dist = sqrt(x*x + y*y);
    double time1, time2, time3, time4;
    double dist1, dist2;
    int cnt_jmp = dist / d;
    
    dist1 = cnt_jmp * d;
    time1 = (dist - dist1) + cnt_jmp * t;
    dist2 = (cnt_jmp+1) * d;
    if(cnt_jmp == 0){
        time2 = (dist2 - dist) + (cnt_jmp + 1) * t;
    }
    else{
        time2 = (cnt_jmp+1) * t;
    }
    time3 = (cnt_jmp + 2) * t;
    time4 = dist;
    printf("%.13lf\n",min(min(time1, time2), min(time3, time4)));
    
}