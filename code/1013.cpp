#include<cstdio>
#include<cstring>
#include<queue>
#define N 1005
using namespace std;

int n, m, k;
bool g[N][N];
bool vis[N];
int a, b;
int cnt;

int main() {
	scanf("%d%d%d", &n, &m, &k);
	memset(g, 0, sizeof(g));
	while(m--) {
		scanf("%d%d", &a, &b);
		g[a][b] = g[b][a] = 1;
	}
	while(k--) {
		scanf("%d", &a);
		memset(vis, 0, sizeof(vis));
		vis[a] = 1;
		
		cnt = 0;
		int i = 1;
		while(i != n + 1) {
			if(!vis[i]) {
				++cnt;
				vis[i] = 1;
				queue<int> q;
				q.push(i);
				
				int t;
				while(!q.empty()) {
					t = q.front();
					for(int j=1; j<=n; ++j) {
						if(g[t][j] && !vis[j]) {
							vis[j] = 1;
							q.push(j);
						}
					}
					q.pop();
				}
			}
			++i;
		}
		
		printf("%d\n", cnt - 1);
	}
	return 0;
}
