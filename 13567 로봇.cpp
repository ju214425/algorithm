#include <iostream>

using namespace std;

int dirx[4] = {1,0,-1,0};
int diry[4] = {0,-1,0,1};

int main(){
	int m, n, cmd2;
	string cmd1;
	int dir = 0;
	int headx = 1, heady = 0;
	int posx = 0, posy = 0;
	cin >> m >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> cmd1 >> cmd2;
		if(cmd1 == "MOVE"){
			posx += headx * cmd2;
			posy += heady * cmd2;
		}
		else{
			if(cmd2 == 0){
				dir = (dir + 3) % 4;
			}
			else{
				dir = (dir + 1) % 4;
			}
			headx = dirx[dir];
			heady = diry[dir];
		}

		if(0 <= posx and posx <= m and 0 <= posy and posy <= m){
			continue;
		}
		cout << -1;
		return 0;
	}
	cout << posx << " " << posy;
}