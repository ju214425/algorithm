#include <cstdio>
#include <vector>

typedef long long ll;

struct Coord{
	int x, y, z;
}

ll distance(Coord a, Coord b){
	return (a.x-b.x)*(a.x-b.x) + 
		(a.y-b.y)*(a.y-b.y) + 
		(a.z-b.z)*(a.z-b.z);
}

int main(){
	int n;
	scanf("%d", &n);
	vector<Coord> v(n+1);
	for(int i = 1 ; i <= n ; i++){
		scanf("%d%d%d", v[i].x, v[i].y, v[i].z);
	}


}