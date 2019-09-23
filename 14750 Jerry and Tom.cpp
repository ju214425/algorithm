#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Coord{
	int x, y;
};

struct Line{
	Coord c1, c2;
};

int main(){
	int n, k, h, m;
	cin >> n >> k >> h >> m;


	vector<Coord> corner(n), hole(h), mouse(m);
	vector<Line> line(n);
	cin >> corner[0].x >> corner[0].y;

	for(int i = 1 ; i < n ; i++){
		cin >> corner[i].x >> corner[i].y;
		Line[i-1].c1 = corner[i-1];
		Line[i-1].c2 = corner[i];
	}
	Line[n-1].c1 = corner[n-1];
	Line[n-1].c2 = corner[0];

	for(int i = 0 ; i < h ; i++){
		cin >> hole[i].x >> hole[i].y;
	}

	for(int i = 0 ; i < m ; i++){
		cin >> mouse[i].x >> mouse[i].y;
	}


}