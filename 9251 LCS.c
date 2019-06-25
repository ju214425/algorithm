#include <stdio.h>
#include <string.h>

char a[1000];
char b[1000];
int lcs[1005][1005];

int a_len;
int b_len;

int max(int num1, int num2) {
	return num1 > num2 ? num1 : num2;
}
int LCS(){
	for(int i = 1 ; i <= a_len ; i++){
		for(int j = 1 ; j <= b_len ; j++){
			if( a[i - 1] == b[j - 1] ) lcs[i][j] = lcs[i-1][j-1] + 1;
			else lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
		}
	}
	return lcs[a_len][b_len];
}

int main(){
	scanf("%s%s", a, b);
	a_len = strlen(a);
	b_len = strlen(b);
	printf("%d\n", LCS());
}