#include<bits/stdc++.h>
#define N 505
#define INF 0x7fffffff
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b-1); i>=(a); --i)

int n, m, s, d;
int a, b;
int g[N][N];
int cost[N][N];
bool vis[N];

int path[N], tmp[N];
int mdis=INF, msum=INF;

void dfs(int pre, int dis, int sum, int depth) {
	tmp[depth++] = pre;
	
	if(pre == d) {
		if(dis < mdis) {
			mdis = dis;
			msum = sum;
			memcpy(path, tmp, sizeof(path));
		}
		else if(dis==mdis && sum<msum) {
			msum = sum;
			memcpy(path, tmp, sizeof(path));
		}
		return ;
	}
	
	if(dis >= mdis) return ;
	
	vis[s] = 1;
	rep(i,0,n) {
		if(g[pre][i] && !vis[i]) {
			vis[i] = 1;
			dfs(i, dis+g[pre][i], sum+cost[pre][i], depth);
			vis[i] = 0;
		}
	}
	return ;
}

int main() {
	scanf("%d%d%d%d", &n, &m, &s, &d);
	while(m--) {
		scanf("%d%d", &a, &b);
		scanf("%d%d", &g[a][b], &cost[a][b]);
		g[b][a]=g[a][b]; cost[b][a]=cost[a][b];
	}
	
	memset(vis, 0, sizeof(vis));
	memset(tmp, -1, sizeof(tmp));
	dfs(s, 0, 0, 0);
	
	int i = 0;
	while(path[i] != -1) {
		printf("%d ", path[i++]);
	}
	printf("%d %d\n", mdis, msum);
	return 0;
}
