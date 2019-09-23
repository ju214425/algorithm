#include <cstdio>
#include <vector>

using namespace std;

int map[101][101];

int main(){
	int cnt = 0;
	for(int t = 0 ; t < 4 ; t++){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		for(int i = x1 ; i < x2 ; i++){
			for(int j = y1 ; j < y2 ; j++){
				if(map[i][j] == 0){
					map[i][j] = 1;
					cnt++;
				}
			}
		}
	}
	printf("%d", cnt);
}