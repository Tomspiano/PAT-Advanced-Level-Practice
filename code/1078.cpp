#include<bits/stdc++.h>
#define N 100005
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int m, n;
int p[N], cnt;
bool vis[N];

void table() {
	memset(vis, 0, sizeof(vis));
	cnt = 0;
	rep(i,2,N) {
		if(!vis[i]) {
			p[cnt++] = i;
			for(int j=1; j*i<N; ++j) {
				vis[i*j] = 1;
			}
		}
	}
	return ;
}

int Hash(int x, int size) {
	return x%size;
}

int main() {
	table();
	scanf("%d%d", &m, &n);
	m = *lower_bound(p, p+cnt, m);
	memset(vis, 0, sizeof(vis));
	int t, pos, pre;
	while(n--) {
		scanf("%d", &t);
		pos = Hash(t, m);
		if(!vis[pos]) {
			printf("%d%c", pos, (n ? ' ' : '\n'));
			vis[pos] = 1;
		}
		else {
			t = 1;
			pre = pos;
			while(vis[pre]) {
				if(t >= m) {
					printf("-%c", (n ? ' ' : '\n'));
					break;
				}
				pre = (pos + t*t)%m;
				++t;
			}
			if(!vis[pre]) {
				printf("%d%c", pre, (n ? ' ' : '\n'));
				vis[pre] = 1;
			}
		}
	}
	return 0;
}

