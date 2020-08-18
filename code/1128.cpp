#include<bits/stdc++.h>
#define N 1005
#define M 8
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int k, n;
int a, b;
bool vis[N][N];
int dir[M][2] = {1,0, 1,1, 0,1, -1,1, -1,0, -1,-1, 0,-1, 1,-1};

void color(int col, int row) {
	int x, y;
	rep(i,0,n) {
		rep(j,0,M) {
			x = col + i*dir[j][0];
			y = row + i*dir[j][1];
			if(x>0 && x<=n && y>0 && y<=n)
				vis[y][x] = 1;	
		}
	}
//printf("\n");
//rep(i,1,n+1) rep(j,1,n+1) printf("%d%c", vis[i][j], (j==n ? '\n' : ' '));
}

int main() {
	scanf("%d", &k);
	bool f;
	while(k--) {
		f = 1;
		memset(vis, 0, sizeof(vis));
		scanf("%d", &n);
		scanf("%d", &a);
		color(1, a);
		rep(i,2,n+1) {
			scanf("%d", &b);
			if(vis[b][i])
				f = 0;
			else if(f) color(i, b);
			a = b;
		}
		printf("%s\n", (f ? "YES" : "NO"));
	}
	return 0;
}

