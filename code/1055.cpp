#include<bits/stdc++.h>
#define N 100005
#define M 100
#define AGE 205
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n, k, m, amin, amax;
struct Node {
	char name[10];
	int age, w;
} a[N];
int t[N], s[N];
int c[AGE];

struct cmp {
	bool operator() (const int p, const int q) const {
		if(a[p].w != a[q].w)
			return a[p].w > a[q].w;
		if(a[p].age != a[q].age)
			return a[p].age < a[q].age;
		return strcmp(a[p].name, a[q].name) < 0;
	}
};

int main() {
	scanf("%d%d", &n, &k);
	rep(i,0,n) {
		scanf("%s%d%d", a[i].name, &a[i].age, &a[i].w);
		t[i] = i;
	}
	sort(t, t+n, cmp());
	
	int id = 0;
	memset(c, 0, sizeof(c));
	rep(i,0,n) {
		if(c[a[t[i]].age] < M) {
			s[id++] = t[i];
			++c[a[t[i]].age];
		}
	}
	
	int cnt;
	rep(i,1,k+1) {
		scanf("%d%d%d", &m, &amin, &amax);
		cnt = 0;
		printf("Case #%d:\n", i);
		rep(j,0,id) {
			if(a[s[j]].age>=amin && a[s[j]].age<=amax) {
				++cnt;
				printf("%s %d %d\n", a[s[j]].name, a[s[j]].age, a[s[j]].w);
			}
			if(cnt == m)
				break;
		}
		if(!cnt)	printf("None\n");
	}
	return 0;
}

