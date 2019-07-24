#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int A[27], B[27];

int main(){
	string a, b;
	int ans = 0;
	cin >> a >> b;

	for(int i = 0 ; i < a.size() ; i++){
		A[a[i]-96]++;
	}
	for(int i = 0 ; i < b.size() ; i++){
		B[b[i]-96]++;
	}
	for(int i = 1 ; i < 27 ; i++){
		ans += (abs(A[i] - B[i]));
	}

	cout << ans;
}