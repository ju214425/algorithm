#include <iostream>
#include <queue>

using namespace std;

int main(){
	int n;
	cin >> n;
	queue<int> q;
	while(n--){
		string cmd;
		int number;
		cin >> cmd;
		if(cmd == "push"){
			cin >> number;
			q.push(number);
		}
		else if(cmd == "pop"){
			if(q.empty()) cout << -1 << endl;
			else {
				int f = q.front();
				q.pop();
				cout << f << endl;
			}
		}
		else if(cmd == "size"){
			cout << q.size() << endl;
		}
		else if(cmd == "empty"){
			if(q.empty()) cout << 1 << endl;
			else cout << 0 << endl;
		}
		else if(cmd == "front"){
			if(q.empty()) cout << -1 << endl;
			else cout << q.front() << endl;
		}
		else{
			if(q.empty()) cout << -1 << endl;
			else cout << q.back() << endl;
		}
	}
}