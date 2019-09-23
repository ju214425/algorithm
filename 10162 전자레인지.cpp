#include <iostream>

using namespace std;

int main(){
	int t, a, b, c;
	cin >> t;

	a = t / 300;
	t -= a * 300;
	b = t / 60;
	t -= b * 60;
	c = t / 10;
	t -= c * 10;

	if(t != 0){
		cout << -1;
	}
	else{
		cout << a << " " << b << " " << c;
	}
}