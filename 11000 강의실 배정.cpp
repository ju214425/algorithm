#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct lecture{
	int start, end;
};

bool cmp(lecture l1, lecture l2){
	return l1.start == l2.start ? l1.end < l2.end : l1.start < l2.start;
}

int main(){
	int n, cnt = 0;
	int pointer = 0;
	scanf("%d", &n);
	vector<lecture> v(n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d", &v[i].start, &v[i].end);
	}
	sort(v.begin(), v.end(), cmp);

	for(int i = 0 ; i < n ; i++){
		if(v[i].start >= pointer){
			pointer = v[i].end;
			cnt++;
		}
	}

	printf("%d", cnt);
}