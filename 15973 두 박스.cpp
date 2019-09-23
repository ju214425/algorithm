#include <cstdio>

using namespace std;

#define P 1
#define L 2
#define F 3
#define N 4

struct rect{
	int x1, y1, x2, y2;
};

bool isPoint(rect r1, rect r2){
	if(r1.x2 == r2.x1 and r1.y2 == r2.y1) return true;
	if(r1.x2 == r2.x1 and r1.y1 == r2.y2) return true;
	return false;
}

bool isLine(rect r1, rect r2){
	if(r1.x2 == r2.x1){
		if(r2.y1 <= r1.y2 and r1.y2 <= r2.y2) return true;
		if(r2.y1 <= r1.y1 and r1.y1 <= r2.y2) return true;
		if(r1.y1 <= r2.y2 and r2.y2 <= r1.y2) return true;
		if(r1.y1 <= r2.y1 and r2.y1 <= r1.y2) return true;
	}
	if(r1.y2 == r2.y1){
		if(r2.x1 <= r1.x2 and r1.x2 <= r2.x2) return true;
		if(r2.x1 <= r1.x1 and r1.x1 <= r2.x2) return true;
		if(r1.x1 <= r2.x2 and r2.x2 <= r1.x2) return true;
		if(r1.x1 <= r2.x1 and r2.x1 <= r1.x2) return true;
	}
	return false;
}

// bool isFace(rect r1, rect r2){
// 	if((r2.x1 < r1.x2 and r1.x2 < r2.x2) and
// 	   ((r2.y1 <= r1.y1 and r1.y1 <= r2.y2) or
// 	   (r2.y1 <= r1.y2 and r1.y2 <= r2.y2)))
// 		return true; // 오른쪽
// 	if((r2.y1 < r1.y2 and r1.y2 < r2.y2) and
// 	   ((r2.x1 < r1.x1 and r1.x1 < r2.x2) or
// 	   (r2.x1 < r1.x2 and r1.x2 < r2.x2)))
// 		return true; // 위쪽
// 	if((r2.x1 < r1.x1 and r1.x1 < r2.x2) and
// 	   ((r2.y1 <= r1.y1 and r1.y1 <= r2.y2) or
// 	   (r2.y1 <= r1.y2 and r1.y2 <= r2.y2)))
// 		return true; // 왼쪽
// 	if((r2.y1 < r1.y1 and r1.y1 < r2.y2) and
// 	   ((r2.x1 < r1.x1 and r1.x1 < r2.x2) or
// 	   (r2.x1 < r1.x2 and r1.x2 < r2.x2)))
// 		return true; // 아래쪽

// 	return false;
// }

bool isNull(rect r1, rect r2){
	if((r1.x2 < r2.x1)) return true; //a
	if((r1.y2 < r2.y1)) return true; //b
	return false;
}

int check(rect r1, rect r2){
	if((isNull(r1, r2) or (isNull(r2, r1)))) return N;
	if((isPoint(r1, r2)) or (isPoint(r2, r1))) return P;
	if((isLine(r1, r2)) or (isLine(r2, r1))) return L;
	else return F;
}

int main(){
	rect r1, r2;
	scanf("%d%d%d%d", &r1.x1, &r1.y1, &r1.x2, &r1.y2);
	scanf("%d%d%d%d", &r2.x1, &r2.y1, &r2.x2, &r2.y2);
	int num = check(r1, r2);
	if(num == P) printf("POINT\n");
	else if(num == L) printf("LINE\n");
	else if(num == F) printf("FACE\n");
	else printf("NULL\n");

	return 0;
}