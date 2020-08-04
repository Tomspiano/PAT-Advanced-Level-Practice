#include<bits/stdc++.h>
#define N 30005
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n, k;
struct Stu {
	char id[15];
	int s, locn;
	int finalr, locr;
} a[N];
int d[N];
struct cmp {
	bool operator() (const int &p, const int &q) const {
		if(a[p].s != a[q].s)
			return a[p].s > a[q].s;
		return strcmp(a[p].id, a[q].id) < 0;
	}
};
int t[N];


int main() {
	scanf("%d", &n);
	d[0] = 0;
	int j = 0;
	rep(i,1,n+1) {
		scanf("%d", &k);
		d[i] = d[i-1] + k;
		while(j < d[i]) {
			scanf("%s%d", a[j].id, &a[j].s);
			a[j].locn = i;
			t[j] = j;
			++j;
		}
	}
	
	int cnt;
	rep(i,1,n+1) {
		sort(t+d[i-1], t+d[i], cmp());
		cnt = 1;
		a[t[d[i-1]]].locr = 1;
		rep(k,d[i-1]+1,d[i]) {
			++cnt;
			if(a[t[k]].s == a[t[k-1]].s)
				a[t[k]].locr = a[t[k-1]].locr;
			else
				a[t[k]].locr = cnt;
		}
	}
	sort(t, t+j, cmp());
	printf("%d\n", j);
	cnt = 1;
	a[t[0]].finalr = 1;
	printf("%s %d %d %d\n", a[t[0]].id, a[t[0]].finalr, a[t[0]].locn, a[t[0]].locr);
	rep(k,1,j) {
		++cnt;
		if(a[t[k]].s == a[t[k-1]].s)
			a[t[k]].finalr = a[t[k-1]].finalr;
		else
			a[t[k]].finalr = cnt;
		printf("%s %d %d %d\n", a[t[k]].id, a[t[k]].finalr, a[t[k]].locn, a[t[k]].locr);
	}
	return 0;
}

