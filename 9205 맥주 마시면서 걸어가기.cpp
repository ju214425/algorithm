#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[103][103];

void clear(){
	for(int i = 0 ; i < 103 ; i++){
		for(int j = 0 ; j < 103 ; j++){
			map[i][j] = 0;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, n, x, y;
	cin >> t;
	while(t--){
		cin >> n;
		vector<pair<int, int> > v(n+2);
		clear();
		cin >> x >> y;
		v[0].first = x; v[0].second = y;
		for(int i = 1 ; i <= n ; i++){
			cin >> x >> y;
			v[i].first = x;
			v[i].second = y;
		}
		cin >> x >> y;
		v[n+1].first = x; v[n+1].second = y;

		for(int i = 0 ; i < v.size() ; i++){
			for(int j = i + 1 ; j < v.size() ; j++){
				if(abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second) <= 1000){
					map[i][j] = map[j][i] = 1;
				}
			}
		}

		for(int i = 0 ; i < n + 2 ; i++){
			for(int j = 0 ; j < n + 2 ; j++){
				for(int k = 0 ; k < n + 2 ; k++){
					if(map[j][i] and map[i][k]){
						map[j][k] = 1;
					}
				}
			}			
		}

		if(map[0][n+1]){
			cout << "happy" << "\n";
		}
		else{
			cout << "sad" << "\n";
		}
	}
}