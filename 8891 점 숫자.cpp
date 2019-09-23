#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_dot_num(int x, int y){
	int ans = ((x+y-1) * (x+y))/2;
	for(int i = x+y-1 ; i >= 1 ; i--){
		if(i == x){
			break;
		}
		ans--;
	}

	return ans;
}

pair<int, int> rev_dot_num(int num){
	int temp;
	pair<int, int> ans;
	for(int i = 1 ; i < 150 ; i++){
		if((i*(i-1)/2) < num and num <= (i*(i+1)/2)){
			temp = i+1;
			break;
		}
	}

	for(int i = 1 ; i < temp ; i++){
		if(get_dot_num(i, temp - i) == num){
			ans.first = i;
			ans.second = temp - i;
			break;
		}
	}

	return ans;

}

int main(){
	int t;
	cin >> t;

	while(t--){
		int a, b, ans;
		cin >> a >> b;
		pair<int, int> p1, p2;
		p1 = rev_dot_num(a);
		p2 = rev_dot_num(b);
		
		cout << get_dot_num(p1.first + p2.first, p1.second + p2.second) << "\n";
	}
}