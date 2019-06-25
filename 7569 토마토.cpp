#include <iostream>
#include <queue>

using namespace std;

queue <int> Q;

int dx[6] = {0, 0, 1, 0, -1, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] =	{1, 0, 0, 0, 0, -1};

int tomatoarr[105][105][105];

int main(){
	int m, n, h; //가로 세로 높이
	cin >> m >> n >> h;
	for(int i = 1 ; i <= h ; i++){
		for(int j = 1 ; j <= n ; j++){
			for(int k = 1 ; k <= m ; k++){
				cin >> tomatoarr[j][k][i];
			}
		}
	}

}