#include <cstdio>
#include <queue>

using namespace std;

int map[2005][2005];
int parent[100005];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int find(int x){
	if(parent[x] == x)
		return x;	
	return parent[x] = find(parent[x]);
}

void join(int x, int y){
	x = find(x);
	y = find(y);
	if(x == y)
		return;
	if(x < y)
		swap(x, y);
	parent[x] = y;
}

bool is_same_set(int x, int y){
	return find(x) == find(y);
}

struct Coord{
	int x, y, val;
};

bool is_in_limit(Coord a, int limit){
	if(a.x > limit or a.y > limit or a.x == 0 or a.y == 0)
		return false;
	return true;
}

void check_adjacent(Coord a, int limit, int &cnt){
	for(int i = 0 ; i < 4 ; i++){
		Coord co;
		co.x = a.x + dx[i];
		co.y = a.y + dy[i];
		if(is_in_limit(co, limit)){
			if(map[co.x][co.y] != 0 and !is_same_set(map[co.x][co.y], a.val)){
				join(map[co.x][co.y], a.val);
				cnt--;
			}
		}
	}
}



int main(){
	int n, k;
	int year = 0;
	scanf("%d%d", &n, &k);
	int civil = k;
	queue<Coord> q;
	
	for(int i = 1 ; i <= k ; i++){
		Coord c;
		scanf("%d%d", &c.x, &c.y);
		c.val = i;
		map[c.x][c.y] = i;
		check_adjacent(c, k, civil);
		if(civil == 1){
			printf("%d", year);
			return 0;
		}
		q.push(c);
	}

	while(++year){
		int qs = q.size();
		while(qs--){
			Coord c = q.front();
			q.pop();
			for(int i = 0 ; i < 4 ; i++){
				Coord co;
				co.x = c.x + dx[i];
				co.y = c.y + dy[i];
				co.val = c.val;
				if(is_in_limit(co, n)){
					map[co.x][co.y] = co.val;
					check_adjacent(co, k, civil);
					q.push(co);
				}
			}
		}
		if(civil == 1) break;
	}
	printf("%d", year);
}