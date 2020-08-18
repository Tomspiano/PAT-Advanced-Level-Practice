#include<bits/stdc++.h>
#define N 20
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n;
char s[N];
int z, a, b;

int main() {
	scanf("%d", &n);
	int len;
	while(n--) {
		scanf("%s", s);
		len = strlen(s);
		a = b = z = 0;
		rep(i,0,len/2) {
			a = 10*a + (s[i] - '0');
			z = 10*z + (s[i] - '0');
		}
		rep(i,len/2, len) {
			b = 10*b + (s[i] - '0');
			z = 10*z + (s[i] - '0');
		}
		if(!a || !b) printf("No\n");
		else printf("%s\n", (z%(a*b)==0 ? "Yes" : "No"));
	}
	return 0;
}

