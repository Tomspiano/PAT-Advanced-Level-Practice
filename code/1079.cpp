#include<bits/stdc++.h>
#define N 100005
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n, k, t;
double p, r;
vector<int> vec[N];
vector<int>::iterator j;
queue<int> q;
bool vis[N];

int main() {
	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100.0;
	
	int root;
	memset(vis, 0, sizeof(vis));
	rep(i,0,n) {
		scanf("%d", &k);
		rep(j,0,k) {
			scanf("%d", &t);
			vec[i].push_back(t);
			vis[t] = 1;
		}
		if(!k) {
			scanf("%d", &t);
			vec[i].push_back(-t);
		}
	}
	rep(i,0,n) if(!vis[i]) {
		root = i;
		break;
	}
	
	double sum=0, tans=1;
	int fst=root, lst;
	q.push(root);
	while(!q.empty()) {
		t = q.front();
		if(*vec[t].begin() < 0)
			sum += tans*(-(*vec[t].begin()));
		else {
			for(j=vec[t].begin(); j!=vec[t].end(); ++j) {
				q.push(*j);
				lst = *j;
			}
		}
		
		if(t == fst) {
			tans *= 1+r;
			fst = lst;
		}
		q.pop();
	}
	
	printf("%.1f", sum*p);
	return 0;
}

