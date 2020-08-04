#include<bits/stdc++.h>
#define N 55 
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n, m, k;
int p1, p2;
set<int> s[N];


int main() {
	scanf("%d", &n);
	rep(i,1,n+1) {
		scanf("%d", &m);
		while(m--) {
			scanf("%d", &k);
			s[i].insert(k);
		}
	}
	
	scanf("%d", &k);
	while(k--) {
		scanf("%d%d", &p1, &p2);
		vector<int> c, t;
		set_intersection(s[p1].begin(), s[p1].end(), s[p2].begin(), s[p2].end(), inserter(c, c.begin()));
		set_union(s[p1].begin(), s[p1].end(), s[p2].begin(), s[p2].end(), inserter(t, t.begin()));	
		printf("%.1f%\n", c.size()*100./t.size());
	}
	return 0;
}
