#include<bits/stdc++.h>
#define N 100
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n, t;
typedef struct Node *tree;
struct Node {
	int data;
	int height;
	tree lf, rt;
	Node() {
		lf = rt = 0;
	}
};
int a[N];
bool vis[N];

int getHeight(tree r) {
	if(!r) return 0;
	return max(getHeight(r->lf), getHeight(r->rt)) + 1;
}

tree LL(tree r) {
	tree tmp = r->lf;
	r->lf = tmp->rt;
	tmp->rt = r;
	r->height = max(getHeight(r->lf), getHeight(r->rt)) + 1;
	tmp->height = max(getHeight(tmp->lf), r->height) + 1;
	return tmp;
}

tree RR(tree r) {
	tree tmp = r->rt;
	r->rt = tmp->lf;
	tmp->lf = r;
	r->height = max(getHeight(r->lf), getHeight(r->rt)) + 1;
	tmp->height = max(getHeight(tmp->rt), r->height) + 1;
	return tmp;
}

tree LR(tree r) {
	r->lf = RR(r->lf);
	return LL(r);
}

tree RL(tree r) {
	r->rt = LL(r->rt);
	return RR(r);
}

tree Insert(tree r, int x) {
	if(!r) {
		r = new Node;
		r->data = x;
	}
	else {
		if(x < r->data) {
			r->lf = Insert(r->lf, x);
			if(getHeight(r->lf) - getHeight(r->rt) == 2) {
				if(x < r->lf->data)
					r = LL(r);
				else
					r = LR(r);
			}
		}
		else if(x > r->data) {
			r->rt = Insert(r->rt, x);
			if(getHeight(r->rt) - getHeight(r->lf) == 2) {
				if(x > r->rt->data)
					r = RR(r);
				else
					r = RL(r);
			}
		}
	}
	r->height = getHeight(r);
	return r;
}

void lev(tree r, int id) {
	a[id] = r->data;
	vis[id] = 1;
	if(r->lf) lev(r->lf, 2*id+1);
	if(r->rt) lev(r->rt, 2*id+2);
	return;
}

int main() {
	scanf("%d", &n);
	tree r = 0;
	rep(i,0,n) {
		scanf("%d", &t);
		r = Insert(r, t);
	}
	
	memset(vis, 0, sizeof(vis));
	lev(r, 0);
	bool flag = 1;
	int i = 0;
	while(n) {
		if(vis[i]) {
			printf("%d", a[i]);
			--n;
			if(n) printf(" ");
			else printf("\n");
		}
		else flag = 0;
		++i;
	}
	printf("%s", (flag ? "YES" : "NO"));
	return 0;
}

