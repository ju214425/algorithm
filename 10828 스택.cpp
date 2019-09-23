#include <iostream>
#include <stack>

using namespace std;

int main(){
	int n, number;
	string cmd;
	cin >> n;
	stack<int> s;
	for(int i = 0 ; i < n ; i++){
		cin >> cmd;
		if(cmd == "push"){
			cin >> number;
			s.push(number);
		}
		else if(cmd == "pop"){
			if(s.empty()) cout << "-1" << "\n";
			else{
				cout << s.top() << "\n";
				s.pop();
			}
		}
		else if(cmd == "size"){
			cout << s.size() << "\n";
		}
		else if(cmd == "empty"){
			cout << s.empty() << "\n";
		}
		else if(cmd == "top"){
			if(s.empty()) cout << "-1" << "\n";
			else{
				cout << s.top() << "\n";
			}
		}
	}
}