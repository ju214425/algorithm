#include <iostream>
#include <vector>

using namespace std;

int map[101][101];

void init(){
	for(int i = 0 ; i < 101 ; i++){
		for(int j = 0 ; j < 101 ; j++){
			map[i][j] = -1;
		}
	}
}

int get_blank(int x, int y, int n){
	int cnt = 0;
	for(int i = x+1 ; i < n ; i++){
		if(map[i][y] == 0){
			cnt++;
		}
		if(map[i][y] == -1)
			break;
	}
	return cnt;
}

struct coord{
	int x, y;
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	int m, n;
	int sum;
	cin >> t;
	while(t--){
		cin >> m >> n;
		sum = 0;
		init();
		
		vector<coord> v;
		for(int i = 0 ; i < m ; i++){
			for(int j = 0 ; j < n ; j++){
				cin >> map[i][j];
				if(map[i][j] == 1)
					v.push_back({i, j});
			}
		}

		for(int i = 0 ; i < v.size() ; i++){
			sum += get_blank(v[i].x, v[i].y, m);
		}

		cout << sum << "\n";

	}
}