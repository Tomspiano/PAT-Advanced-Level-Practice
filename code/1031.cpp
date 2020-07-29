#include<bits/stdc++.h>
#define N 85
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

char str[N];

int main() {
	scanf("%s", str);
	int len = strlen(str);
	int n1, n2;
	n1 = (len + 2)/3;
	n2 = len + 2 - 2*n1;
	
	int i = 0;
	for(; i<n1-1; ++i) {
		printf("%c", str[i]);
		rep(k,0,n2-2) printf(" ");
		printf("%c\n", str[len-1-i]);
	}
	rep(j,0,n2) printf("%c", str[i+j]);
	return 0;
}
