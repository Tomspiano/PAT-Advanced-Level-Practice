#include<bits/stdc++.h>
#define N 105
#define M 260
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b-1); i>=(a); --i)

int n;
char s[N][M], t;

int main() {
	scanf("%d", &n);
	getchar();
	int len;
	rep(i,0,n) {
		cin.getline(s[i], M);
		len = strlen(s[i]);
		rep(j,0,len/2) {
			t=s[i][j], s[i][j]=s[i][len-1-j], s[i][len-1-j]=t;
		}
	}
	
	len = 0;
	bool f = 1;
	while(f) {
		if(!s[0][len]) {
			break;
		}
		rep(i,1,n) {
			if(!s[i][len] || s[i][len]!=s[i-1][len]) {
				f = 0;
				break;
			}
		}
		if(f) ++len;
	}
	
	if(len) {
		per(i,0,len)
			printf("%c", s[0][i]);
	}
	else
		printf("nai");
	return 0;
}
