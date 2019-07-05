#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long sum(vector<int> &a){
	int sum = 0;
	for(int i = 0 ; i < a.size() ; ++i) {
		sum += a[i];
	}
	return sum;
}