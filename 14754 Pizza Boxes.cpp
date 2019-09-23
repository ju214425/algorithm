#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll map[1000][1000];

int main(){
	int a, b;
	ll sum = 0, m_sum = 0;
	cin >> a >> b;

	vector<ll> side(a), front(b), v;
	for(int i = 0 ; i < a ; i++){
		for(int j = 0 ; j < b ; j++){
			cin >> map[i][j];
			sum += map[i][j];
		}
	}

	for(int i = 0 ; i < a ; i++){
		for(int j = 0 ; j < b ; j++){
			side[i] = max(side[i], map[i][j]);
		}
	}

	for(int j = 0 ; j < b ; j++){
		for(int i = 0 ; i < a ; i++){
			front[j] = max(front[j], map[i][j]); 
		}
	}

	for(int i = 0 ; i < side.size() ; i++){
		v.push_back(side[i]);
	}

	for(int i = 0 ; i < front.size() ; i++){
		v.push_back(front[i]);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for(int i = 0 ; i < v.size(); i++){
		m_sum += v[i];
	}

	cout << sum - m_sum;

}