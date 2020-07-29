#include<iostream>
#include<queue>
#define N 105
using namespace std;

int n, m;
int id, k;
int tree[N][N];
queue<int> q;

int main() {
	scanf("%d", &n);
	if(n) {
		scanf("%d", &m);
		for(int i=0; i<m; ++i) {
			scanf("%d%d", &id, &k);
			tree[id][0] = k;
			for(int j=1; j<=k; ++j) {
				scanf("%d", &tree[id][j]);
			}
		}

		q.push(1);
		int pre = 1;
		int sum = 0;
		int lst = 1;
		while(!q.empty()) {
			int t = q.front();
			for(int i=1; i<=tree[t][0]; ++i) {
				q.push(tree[t][i]);
				lst = tree[t][i];
			}
			if(!tree[t][0])
				++sum;
			if(t==pre) {
				if(pre!=1) printf(" ");
				printf("%d", sum);
				pre = lst;
				sum = 0;
			}
			q.pop();
		}
		
		printf("\n");
	}
	
	return 0;
}
