#include<bits/stdc++.h>
#define N 100005
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n;
int a[N];

int main() {
	scanf("%d", &n);
	rep(i,0,n) scanf("%d", &a[i]);
	sort(a, a+n);
	
	int s1, s2;
	s1 = 0;
	rep(i,0,n/2) s1+=a[i];
	s2 = 0;
	rep(i,n/2,n) s2+=a[i];
	printf("%d %d\n", n&1, s2-s1);
	return 0;
}
