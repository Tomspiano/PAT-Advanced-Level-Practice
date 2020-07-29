#include<bits/stdc++.h>
#define N 105
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n, m;
int id, k;
int tree[N][N];
queue<int> q;

int main() {
	scanf("%d%d", &n, &m);

	rep(i,0,m) {
		scanf("%d%d", &id, &k);
		tree[id][0] = k;
		rep(j,1,k+1) {
			scanf("%d", &tree[id][j]);
		}
	}

	q.push(1);
	int pre = 1;
	int sum=0, msum=0;
	int lst = 1;
	int level=1, depth;
	while(!q.empty()) {
		int t = q.front();
		++sum;
		rep(i,1,tree[t][0]+1) {
			q.push(tree[t][i]);
			lst = tree[t][i];
		}
		if(t==pre) {
			if(msum < sum) {
				msum = sum;
				depth = level;
			}
			sum = 0;
			++level;
			pre = lst;
		}
		q.pop();
	}
	
	printf("%d %d\n", msum, depth);
	
	return 0;
}
