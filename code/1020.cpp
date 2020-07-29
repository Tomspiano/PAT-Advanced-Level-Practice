#include<bits/stdc++.h>
#define N 10000
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n;
int pos[N], in[N], lev[N];

void solve(int lf, int rt, int root, int id) {
	if(lf >= rt) return ;
	lev[id] = pos[root];
	int *i = find(in+lf, in+rt, pos[root]);
	int rtlen = (in + rt) - i - 1;
//printf("%d %d %d\n", i-in, rtlen, id);
	solve(lf, i-in, root-rtlen-1, 2*id+1);
	solve(i-in+1, rt, root-1, 2*id+2);
}

int main() {
	scanf("%d", &n);
	rep(i,0,n) scanf("%d", &pos[i]);
	rep(i,0,n) scanf("%d", &in[i]);
	
	solve(0, n, n-1, 0);
	int i = 0;
	int cnt = 0;
	while(cnt < n) {
		if(lev[i]) {
			++cnt;
			printf("%d%c", lev[i], (cnt==n ? '\n' : ' '));	
		}
		++i;
	}
	return 0;
}
