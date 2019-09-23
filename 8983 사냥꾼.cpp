#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Coord{
	int x, y;
};

bool cmp(Coord c1, Coord c2){
	return c1.x == c2.x ? c1.y < c2.y : c1.x < c2.x;
}

int dist(Coord c1, Coord c2){
	return abs(c1.x - c2.x) + abs(c1.y - c2.y);
}

void print(vector<Coord> v){
	cout << endl;
	for(int i = 0 ; i < v.size(); i++){
		cout << i << " : " << v[i].x << " " << v[i].y << endl;
	}
	cout << v.size() << endl;
	cout << endl;
}

int main(){
	int m, n, l, cnt = 0;
	cin >> m >> n >> l;


	vector<Coord> sniper(m);
	vector<Coord> animal;
	for(int i = 0 ; i < m ; i++){
		cin >> sniper[i].x;
		sniper[i].y = 0;
	}

	for(int i = 0 ; i < n ; i++){
		int a, b;
		cin >> a >> b;
		if(b <= l){
			animal.push_back({a, b});
		}
	}

	sort(sniper.begin(), sniper.end(), cmp);
	sort(animal.begin(), animal.end(), cmp);

	print(sniper);
	print(animal);

	int p = 0;

	for(int i = 0 ; i < m ; i++){
		
	}

	cout << cnt;
}