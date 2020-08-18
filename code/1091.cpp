#include<bits/stdc++.h>
#define N 1300
#define L 65
#define D 6
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int m, n, s, t;
bool g[L][N][N];
struct Node {
	int lev, row, col;
};
queue<Node> q;
const int dir[D][3] = {1,0,0, 0,1,0, -1,0,0, 0,-1,0, 0,0,1, 0,0,-1};

int main() {
	scanf("%d%d%d%d", &m, &n, &s, &t);
	rep(i,0,s) rep(j,0,m) rep(k,0,n) {
		scanf("%d", &g[i][j][k]);
	}
	
	int sum=0, tmp;
	Node p;
	int x, y, z;
	rep(i,0,s) rep(j,0,m) rep(k,0,n) {
		if(g[i][j][k]) {
			tmp = 0;
			g[i][j][k] = 0;
			q.push(Node{i,j,k});
			while(!q.empty()) {
				++tmp;
				p = q.front();
				rep(u,0,D) {
					y = p.row + dir[u][0];
					x = p.col + dir[u][1];
					z = p.lev + dir[u][2];
					if(y>=0 && y<m && x>=0 && x<n && z>=0 && z<s
					&& g[z][y][x]) {
						g[z][y][x] = 0;
						q.push(Node{z,y,x});
					}
				}
				q.pop();
			}
			if(tmp >= t) {
				sum += tmp;
			}
		}
	}
	printf("%d\n", sum);
	return 0;
}
