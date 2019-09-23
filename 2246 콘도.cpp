#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct house{
	int dist, cost;
	bool check;
};

bool cmp_cost(house h1, house h2){
	return h1.cost == h2.cost ? h1.dist < h2.dist : h1.cost < h2.cost;
}

bool cmp_dist(house h1, house h2){
	return h1.dist == h2.dist ? h1.cost < h2.cost : h1.dist < h2.dist;
}


int main(){
	int n, dist, cost;
	int cnt = 0;
	cin >> n;

	vector<house> v;

	for(int i = 0 ; i < n ; i++){
		cin >> dist >> cost;
		v.push_back({dist, cost, true});
	}

	for(int i = 0 ; i < n ; i++){
		bool ans = true;
		for(int j = 0 ; j < n ; j++){
			if(i != j){
				if(v[i].cost >= v[j].cost and v[i].dist >= v[j].dist){
					ans = false;
				}
				else if(v[i].dist >= v[j].dist and v[i].cost >= v[j].cost){
					ans = false;
				}
			}
		}
		if(ans){
			cnt++;
		}
	}

	cout << cnt;
}