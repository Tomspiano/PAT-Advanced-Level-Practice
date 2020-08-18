#include<bits/stdc++.h>
#define N 15
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n;
struct Node {
	int lf, rt;
} t[N];
bool vis[N];
queue<int> q;
int cnt;

void order(int r) {
	if(t[r].rt != -1)
		order(t[r].rt);
	++cnt;
	printf("%d%c", r, (cnt==n ? '\n' : ' '));
	if(t[r].lf != -1)
		order(t[r].lf);
	return ;
}

int main() {
	scanf("%d", &n);
	char t1, t2;
	memset(vis, 0, sizeof(vis));
	rep(i,0,n) {
		scanf(" %c %c", &t1, &t2);
		if(t1 == '-') {
			t[i].lf = -1;
		}
		else {
			t[i].lf = t1 - '0';
			vis[t[i].lf] = 1;
		}
		if(t2 == '-') {
			t[i].rt = -1;
		}
		else {
			t[i].rt = t2 - '0';
			vis[t[i].rt] = 1;
		}
//printf("%d %d\n", t[i].lf, t[i].rt);
	}
	int r;
	rep(i,0,n) {
		if(!vis[i]) {
			r = i;
			break;
		}
	}
	q.push(r);
	int tmp;
	while(!q.empty()) {
		tmp = q.front();
		if(t[tmp].rt != -1)
			q.push(t[tmp].rt);
		if(t[tmp].lf != -1)
			q.push(t[tmp].lf);
		q.pop();
		printf("%d%c", tmp, (q.empty() ? '\n' : ' '));
	}
	cnt = 0;
	order(r);
	return 0;
}

