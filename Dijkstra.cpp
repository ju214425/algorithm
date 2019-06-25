//2016025841 이종욱

#include <iostream>
#define inf 100000

using namespace std;

int min(int num1, int num2){
	return num1 > num2 ? num2 : num1;
}

int main(){
	int numberOfVertex;
	cin >> numberOfVertex;
	int vertexArr[numberOfVertex + 1][numberOfVertex + 1];
	int pathArr[numberOfVertex + 1]; 
	int minimum= 50000, minimumIndex;
	int check = 1;
	for(int i = 1 ; i <= numberOfVertex ; i++){
		for(int j = 1 ; j <= numberOfVertex ; j++){
			vertexArr[i][j] = inf;
		}
	}
	for(int i = 1 ; i <= numberOfVertex ; i++){
		vertexArr[i][i] = 0;
	}
	pathArr[1] = 0;
	for(int i = 2 ; i <= numberOfVertex ; i++){
		pathArr[i] = inf;
	}
	for(int i = 1 ; i <= numberOfVertex ; i++){
		int trsh, numberOfEdges;
		cin >> trsh >> numberOfEdges;
		for(int j = 1 ; j <= numberOfEdges ; j++){
			int index, value;
			cin >> index >> value;
			vertexArr[i][index] = value;
		}
	}
	for(int i = 1 ; i <= numberOfVertex ; i++){
		for(int j = 1 ; j <= numberOfVertex ; j++){
			if(vertexArr[i][j] != inf){
				pathArr[j] = min(pathArr[i] + vertexArr[i][j], pathArr[j]);
				if(minimum > pathArr[j]){
					minimum = pathArr[j];
					minimumIndex = j;
				}
			}
		}
		i = minimumIndex;
		check++;
		if(check == numberOfVertex) break;
	}
	cout << pathArr[minimumIndex];
}