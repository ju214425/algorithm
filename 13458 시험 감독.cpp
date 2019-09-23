#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll arr[1000005];

int main(){
	ll n, b, c;
	ll total = 0;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> arr[i];
	}
	cin >> b >> c;

	for(int i = 0 ; i < n ; i++){
		if(arr[i] >= b){
			arr[i] -= b;
			total++;
		}
		else{
			total++;
			continue;
		}

		if(arr[i] >= c){
			if(arr[i] % c == 0){
				total += (arr[i]/c);
			}
			else{
				total += (arr[i]/c + 1);
			}
		}
		else if(arr[i] != 0){
			total++;
		}
	}

	cout << total << endl;
}