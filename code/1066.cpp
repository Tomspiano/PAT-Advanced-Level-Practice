#include<bits/stdc++.h>
using namespace std;

int n, a;
struct Node {
	int data;
	int h;
	Node *lf, *rt;
	Node() {
		lf = rt = 0;
	}
};

int getHeight(Node *r) {
	if(r == 0) return 0;
	return max(getHeight(r->lf), getHeight(r->rt)) + 1;
}

Node *L(Node *r) {
	Node *LF = r->lf;
	r->lf = LF->rt;
	LF->rt = r;
	r->h = max(getHeight(r->lf), getHeight(r->rt)) + 1;
	LF->h = max(getHeight(LF->lf), r->h) + 1;
	return LF;
}

Node *R(Node *r) {
	Node *RT = r->rt;
	r->rt = RT->lf;
	RT->lf = r;
	r->h = max(getHeight(r->lf), getHeight(r->rt)) + 1;
	RT->h = max(getHeight(RT->rt), r->h) + 1;
	return RT;
}

Node *RL(Node *r) {
	r->rt = L(r->rt);
	return R(r);
}

Node *LR(Node *r) {
	r->lf = R(r->lf);
	return L(r);
}

Node *Insert(Node *r, int x) {
	if(r == 0) {
		r = new Node;
		r->data = x;
		r->h = 0;
	}
	else if(x < r->data) {
		r->lf = Insert(r->lf, x);
		if(getHeight(r->lf) - getHeight(r->rt) == 2) {
			if(x < r->lf->data)
				r = L(r);
			else
				r = LR(r);
		}
	}
	else if(x > r->data) {
		r->rt = Insert(r->rt, x);
		if(getHeight(r->rt) - getHeight(r->lf) == 2) {
			if(x > r->rt->data)
				r = R(r);
			else
				r = RL(r);
		}
	}
	r->h = getHeight(r);
	return r;
}

int main() {
	scanf("%d", &n);
	Node *r = 0;
	while(n--) {
		scanf("%d", &a);
		r = Insert(r, a);
	}
	printf("%d\n", r->data);
	return 0;
}
