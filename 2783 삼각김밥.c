#include <stdio.h>
#include <algorithm>

using namespace std;
int main(){
	float x, y;
	float xarr[100] = {}, yarr[100] = {};
	//1그램당 가격
	float value[100] = {};
	scanf("%f %f", &x, &y);
	int numberOfConvinient;
	//1그램당 가격
	float value25 = x / y;
	scanf("%d", &numberOfConvinient);
	for(int i = 0 ; i < numberOfConvinient ; i++){
		scanf("%f %f", &xarr[i], &yarr[i]);
		value[i] = xarr[i] / yarr[i];
	}
	std::sort(value, value + numberOfConvinient);
	if(value[0] < value25) printf("%.2f", value[0] * 1000);
	else printf("%.2f", value25 * 1000);
}