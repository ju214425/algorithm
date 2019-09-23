#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Dot{
	int x, y;
};

bool cmp(Dot d1, Dot d2){
	return d1.x == d2.x ? d1.y < d2.y : d1.x < d2.x;
}

void print(vector<Dot> v){
	cout << "\n";

	for(int i = 0 ; i < v.size() ; i++){
		cout << v[i].x << " " << v[i].y << "\n";
	}

	cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<Dot> v(n);
		vector<int> xpos, ypos;
		for(int i = 0 ; i < n ; i++){
			cin >> v[i].x >> v[i].y;
			xpos.push_back(v[i].x);
			ypos.push_back(v[i].y);
		}

		sort(v.begin(), v.end(), cmp);
		sort(xpos.begin(), xpos.end());
		sort(ypos.begin(), ypos.end());

		xpos.erase(unique(xpos.begin(), xpos.end()), xpos.end());
		ypos.erase(unique(ypos.begin(), ypos.end()), ypos.end());

		for(int i = 0 ; i < n ; i++){
			v[i].x = (int)(lower_bound(xpos.begin(), xpos.end(), v[i].x) - xpos.begin());
			v[i].y = (int)(lower_bound(ypos.begin(), ypos.end(), v[i].y) - ypos.begin());
		}

		print(v);
	}
}