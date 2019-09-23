#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Point{
	int x, y, cnt;
};

bool cmp(Point &a, Point &b){
	return (a.x == b.x and a.y == b.y) ? 
	a.cnt > b.cnt :
	((double)a.y / (double)a.x) > ((double)b.y / (double)b.x);
}


int main(){
	ll n, ans = 0, val = 0;
	scanf("%lli", &n);
	vector<Point> v(2 * n +1);
	for(ll i = 1 ; i <= n ; i++){
		scanf("%d%d%d%d", &v[i].x, &v[i+n].y, &v[i+n].x, &v[i].y);
		v[i].cnt = 1;
		v[i+n].cnt = -1;
	}

	sort(v.begin()+1, v.end(), cmp);

	for(ll i = 1 ; i < v.size() ; i++){
		val += v[i].cnt;
		ans = max(ans, val);
	}

	printf("%lli\n", ans);
}