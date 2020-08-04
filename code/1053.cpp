#include<bits/stdc++.h>
#define N 105
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define mkp make_pair

int n, m, s;
int w[N];
multimap<int, int, greater<int> > tree[N];  // weight, id
int q[N][N], id, cnt;

void dfs(int r, int sum) {
	sum += w[r];
	
	if(sum>=s) {
//printf("\n");
		if(sum==s && !tree[r].size()) {
			++cnt;
			memcpy(q[cnt], q[cnt-1], sizeof(int)*N);
		}
		return ;
	}
	
	for(multimap<int, int>::iterator j=tree[r].begin(); j!=tree[r].end(); ++j) {
		q[cnt][id++] = w[j->second];
//printf("%d:%d:%d(%d:%d) ", j->second, q[cnt][id-1], sum, cnt, id);
		dfs(j->second, sum);
		q[cnt][--id] = -1;
	}
	
	return ;
}

int main() {
	scanf("%d%d%d", &n, &m, &s);
	rep(i,0,n) scanf("%d", &w[i]);
	int idx, k, lf;
	while(m--) {
		scanf("%d%d", &idx, &k);
		while(k--) {
			scanf("%d", &lf);
			tree[idx].insert(mkp(w[lf], lf));
		}
	}
//printf("\n");
	id = cnt = 0;
	q[cnt][id++] = w[0];
	memset(q,-1,sizeof(q));
	dfs(0,0);
//printf("\n\n");	

	int j;
	rep(i,0,cnt) {
		printf("%d", w[0]);
		j = 1;
		while(q[i][j] != -1) {
			printf(" %d", q[i][j++]);
		}
		printf("\n");
	}
	return 0;
}

