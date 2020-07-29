#include<iostream>
#include<cstring>
#include<algorithm>
#define N 505
#define INF 0x7fffffff
using namespace std;

int n, m, c1, c2;
int a, b, len;
int rt[N];
int g[N][N];
int cnt[N];

int dist[N];
bool vis[N];
int path[N][N];

int c=0, sum=0;

void dfs(int curr, int teams) {
	if(curr==c1) {
		++c;
		sum = max(sum, teams);
		return ;
	}
	
	for(int i=0; i<cnt[curr]; ++i) {
		int pre = path[curr][i];
		dfs(pre, teams+rt[pre]);
	}
	return ;
}

int FindMinDist() {
	int MinDist = INF;
	int MinV = -1;
	for(int i=0; i<n; ++i) {
		if(!vis[i] && dist[i]<MinDist) {
			MinDist = dist[i];
			MinV = i;
		}
	}

	return MinV;
}

int main() {
	scanf("%d%d%d%d", &n, &m, &c1, &c2);
	for(int i=0; i<n; ++i) {
		vis[i] = cnt[i] = 0;
		dist[i] = INF;
		for(int j=0; j<n; ++j) {
			g[i][j] = INF;
		}
	}
	
	for(int i=0; i<n; ++i)
		scanf("%d", &rt[i]);
	for(int i=0; i<m; ++i) {
		scanf("%d%d%d", &a, &b, &len);
		g[a][b] = g[b][a] = len;
		
		if(a==c1) {
			cnt[b] = 0;
			path[b][cnt[b]++] = c1;
			dist[b] = len;
		}
		else if(b==c1) {
			cnt[a] = 0;
			path[a][cnt[a]++] = c1;
			dist[a] = len;
		}
	}
	
	dist[c1] = 0;
	vis[c1] = 1;
	while(1) {
		int v = FindMinDist();
		if(v==-1) break;
		
		vis[v] = 1;
		for(int i=0; i<n; ++i) {
			if(!vis[i] && g[v][i]<INF) {
				if(dist[v]+g[v][i] < dist[i]) {
					dist[i] = dist[v]+g[v][i];
					cnt[i] = 0;
					path[i][cnt[i]++] = v;
				}
				else if(dist[v]+g[v][i] == dist[i]) {
					path[i][cnt[i]++] = v;
				}
			}
		}
	}
	
// for(int i=0; i<n; ++i) printf("%d\t", dist[i]); printf("\n");
	
	dfs(c2, rt[c2]);
	
	printf("%d %d\n", c, sum);
	return 0;
}
