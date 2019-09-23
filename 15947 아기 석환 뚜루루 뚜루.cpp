#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string modi(int div, int mod){
	if(mod == 1 or mod == 13){
		return "baby";
	}
	else if(mod == 2 or mod == 0){
		return "sukhwan";
	}
	else if(mod == 5){
		return "very";
	}
	else if(mod == 6){
		return "cute";
	}
	else if(mod == 9){
		return "in";
	}
	else if(mod == 10){
		return "bed";
	}
	else if(mod == 4 or mod == 8 or mod == 12){
		if(div == 0) return "turu";
		else if(div == 1) return "tururu";
		else if(div == 2) return "turururu";
		else if(div == 3) return "tururururu";
		else{
			return "check1";
		}
	}
	else{
		if(div == 0) return "tururu";
		else if(div == 1) return "turururu";
		else if(div == 2) return "tururururu";
		else{
			return "check2";
		}	
	}
}

int main(){
	int n;
	cin >> n;
	string ans;
	int div = n / 14;
	int mod = n % 14;

	ans = modi(div, mod);

	if(ans == "check1"){
		cout << "tu+ru*" << div+1;
	}
	else if(ans == "check2"){
		cout << "tu+ru*" << div+2;	
	}
	else{
		cout << ans;
	}

	return 0;
}