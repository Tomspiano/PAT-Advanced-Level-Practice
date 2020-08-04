#include<bits/stdc++.h>
#define N 1005
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n, upp, k, t, m;
int g[N][N];
bool vis[N];

int main() {
	scanf("%d%d", &n, &upp);
	memset(g, 0, sizeof(g));
	rep(i,1,n+1) {
		scanf("%d", &m);
		rep(j,1,m+1) {
			scanf("%d", &t);
			++g[t][0];
			g[t][g[t][0]] = i;
		}
	}
	
	int r, fst, lst, cnt, lev;
	scanf("%d", &k);
	while(k--) {
		queue<int> q;
		memset(vis, 0, sizeof(vis));
		scanf("%d", &r);
		vis[r] = 1;
		q.push(r);
		fst = r;
		cnt = 0;
		lev = -1;
		while(!q.empty()) {
			t = q.front();
//printf("%d ", t);
			++cnt;
			rep(i,1,g[t][0]+1) {
				if(vis[g[t][i]])
					continue;
				vis[g[t][i]] = 1;
				q.push(g[t][i]);
				lst = g[t][i];
			}
			
			if(fst == t) {
				++lev;
				if(lev == upp)
					break;
				fst = lst;
			}
			q.pop();
		}
		
		printf("%d\n", --cnt);
	}
	return 0;
}

