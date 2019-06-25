#include <stdio.h>
#include <string.h>

char a[103];
char b[103];
char c[103];
int lcs[103][103][103];

int a_len;
int b_len;
int c_len;

int max(int a, int b){ return a > b ? a : b; }

int LCS(){
	for(int i = 1; i <= a_len ; i++){
		for(int j = 1 ; j <= b_len ; j++){
			for(int k = 1 ; k <= c_len ; k++){
				if(a[i-1] == b[j-1] && b[j-1] == c[k-1]){
					lcs[i][j][k] = lcs[i-1][j-1][k-1] + 1;
				}
				else{
					lcs[i][j][k] = max(lcs[i-1][j][k], max(lcs[i][j-1][k], lcs[i][j][k-1]));
				}
			}
		}
	}
	return lcs[a_len][b_len][c_len];
}

int main(){
	scanf("%s%s%s", a, b, c);
	a_len = strlen(a);
	b_len = strlen(b);
	c_len = strlen(c);
	printf("%d", LCS());

}