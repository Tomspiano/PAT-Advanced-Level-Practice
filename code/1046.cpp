#include<bits/stdc++.h>
#define N 100005
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n, m;
int d[N];
int c[N];

int main() {
	scanf("%d", &n);
	c[0] = 0;
	rep(i,1,n+1) {
		scanf("%d", &d[i]);
		c[i] = c[i-1] + d[i];
	}
	
	int a, b;
	int len1, len2;
	scanf("%d", &m);
	while(m--) {
		scanf("%d%d", &a, &b);
		if(a > b) {
			a^=b, b^=a, a^=b;
		}
		len1 = c[b-1] - c[a-1];
		len2 = c[a-1] + d[n] + c[n-1] - c[b-1];
		printf("%d\n", min(len1, len2));
	}
	return 0;
}

