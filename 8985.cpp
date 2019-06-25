#include <iostream>

using namespace std;

int main(){
	int number_of_testcase = 0, accum = 0, score = 0;
	string str;
	cin >> number_of_testcase;
	int answer_array[1000] = {0,};
	for(int i = 0 ; i < number_of_testcase ; i++){
		cin >> str;
		accum = 0, score = 0;
		for(int j = 0 ; j < str.size() ; j++){
			if(str.at(j) == 'X' or (str.at(j) == '0' and j == str.size())){
				score += (accum * (accum + 1) / 2);
				cout << score ;
				accum = 0;
			}
			else{
				accum++;
			}
		}

		answer_array[i] = score;
		cout << endl;
	}
	for(int i = 0 ; i < number_of_testcase ; i++){
		cout << answer_array[i] << endl;
	}

	return 0;
}