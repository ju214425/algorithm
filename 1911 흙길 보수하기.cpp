#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Pond{
	int start, end;
};

bool cmp(Pond a, Pond b){
	return a.start == b.start ? a.end < b.end : a.start < b.start;
}

int main(){
	int n, l;
	scanf("%d%d", &n, &l);
	int pointer, cnt = 0, temp = 0;
	vector<Pond> v(n+1);
	for(int i = 1 ; i <= n ; i++){
		scanf("%d%d", &v[i].start, &v[i].end);
	}

	sort(v.begin()+1, v.end(), cmp);
	pointer = v[1].start;
	for(int i = 1 ; i<= n ; i++){
		if(pointer < v[i].start) pointer = v[i].start;
		if(pointer > v[i].end-1) continue;
		if(v[i].start <= pointer and pointer <= v[i].end-1){
			if((v[i].end - pointer) % l == 0){
				temp = (v[i].end - pointer) / l;
			}
			else{
				temp = (v[i].end - pointer) / l + 1;
			}
			pointer += (temp * l);
			cnt += temp;
		}
	}
	
	printf("%d", cnt);
}