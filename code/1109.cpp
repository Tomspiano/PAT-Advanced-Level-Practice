#include<bits/stdc++.h>
#define N 10005
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b-1); i>=(a); --i)

int n, k;
struct Node {
	char name[10];
	int h;
} a[N];
struct cmp {
	bool operator() (const int p, const int q) const {
		if(a[p].h != a[q].h)
			return a[p].h > a[q].h;
		return strcmp(a[p].name, a[q].name) < 0;
	}
};
int t[N];

int main() {
	scanf("%d%d", &n, &k);
	rep(i,0,n) {
		scanf("%s%d", a[i].name, &a[i].h);
		t[i] = i;
	}
	sort(t, t+n, cmp());
	
	int j = n/k + n - n/k*k;
	per(i,0,j)
		if(i&1) printf("%s ", a[t[i]].name);
	printf("%s", a[t[0]].name);
	rep(i,0,j)
		if(i && !(i&1)) printf(" %s", a[t[i]].name);
	printf("\n");
	while(j+n/k <= n) {
		per(i,j,j+n/k)
			if((i-j)&1) printf("%s ", a[t[i]].name);
		printf("%s", a[t[j]].name);
		rep(i,j,j+n/k)
			if(i!=j && !((i-j)&1)) printf(" %s", a[t[i]].name);
		printf("\n");
		j += n/k;
	}
	return 0;
}

