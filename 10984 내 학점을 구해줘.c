#include <stdio.h>

int main(){
	int numberOfSemester, numberOfSubject, size = 0, tempsize = 0;
	float grade = 0, tempgrade = 0 ;
	scanf("%d", &numberOfSemester);
	int sizearr[numberOfSemester];
	float gradearr[numberOfSemester];
	for(int i = 0 ; i < numberOfSemester ; i++){
		scanf("%d", &numberOfSubject);
		for(int j = 0 ; j < numberOfSubject ; j++){
			scanf("%d %f", &tempsize, &tempgrade);
			size += tempsize;
			grade += (tempsize * tempgrade);
		}
		grade /= size;
		sizearr[i] = size;
		gradearr[i] = grade;
		size = 0;
		grade = 0;
	}
	for(int i = 0 ; i < numberOfSemester ; i++){
		printf("%d %.1f\n", sizearr[i], gradearr[i]);
	}
}