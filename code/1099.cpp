#include<bits/stdc++.h>
#define N 105
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n;
struct Tree {
	int data, lf, rt;
} tree[N];
int num[N];
int id = 0;
queue<int> q;

void dfs(int r) {
	if(tree[r].lf==-1 && tree[r].rt==-1)
		tree[r].data = num[id++];
	else {
		if(tree[r].lf != -1)
			dfs(tree[r].lf);
		tree[r].data = num[id++];
		if(tree[r].rt != -1)
			dfs(tree[r].rt);
	}
}

int main() {
	scanf("%d", &n);
	rep(i,0,n) {
		scanf("%d%d", &tree[i].lf, &tree[i].rt);
	}
	rep(i,0,n) {
		scanf("%d", &num[i]);
	}
	sort(num, num+n);

	dfs(0);	
	q.push(0);
	int t;
	do {
		t = q.front();
		printf("%d", tree[t].data);
		if(tree[t].lf != -1) q.push(tree[t].lf);
		if(tree[t].rt != -1) q.push(tree[t].rt);
		q.pop();
		printf("%c", q.empty() ? '\n' : ' ');
	} while(!q.empty());
	
	return 0;
}
