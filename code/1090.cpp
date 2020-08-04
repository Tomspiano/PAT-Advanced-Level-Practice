#include<bits/stdc++.h>
#define N 100005
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n, t;
double p, r;
vector<int> vec[N];
vector<int>::iterator j;
queue<int> q;

int main() {
	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100.0;
	
	int root;
	rep(i,0,n) {
		scanf("%d", &t);
		if(t==-1) root=i;
		else vec[t].push_back(i);
	}
	
	double ans, tans=1;
	int cnt, tcnt=0;
	int fst=root, lst;
	q.push(root);
	while(!q.empty()) {
		t = q.front();
		++tcnt;
		for(j=vec[t].begin(); j!=vec[t].end(); ++j) {
			q.push(*j);
			lst = *j;
		}
		
		if(t == fst) {
			ans = tans;
			cnt = tcnt;
			tans *= 1+r;
			tcnt = 0;
			fst = lst;
		}
		q.pop();
	}
	
	ans *= p;
	printf("%.2f %d", ans, cnt);
	return 0;
}
