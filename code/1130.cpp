#include<bits/stdc++.h>
#define N 25
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n;
struct Node {
	char s[15];
	int lf, rt;
} a[N];
bool vis[N];

void order(int r) {
	if(r == -1) return;
	
	order(a[r].lf);
	printf("%s", a[r].s);
	order(a[r].rt);
	return ;
}

int main() {
	scanf("%d", &n);
	memset(vis, 0, sizeof(vis));
	rep(i,1,n+1) {
		scanf("%s%d%d", a[i].s, &a[i].lf, &a[i].rt);
		if(a[i].lf != -1)
			vis[a[i].lf] = 1;
		if(a[i].rt != -1)
			vis[a[i].rt] = 1;
	}
	
	int r;
	rep(i,1,n+1) {
		if(!vis[i]) {
			r = i;
			break;
		}
	}
	
	order(r);
	return 0;
}

