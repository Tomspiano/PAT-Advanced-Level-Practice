#include<bits/stdc++.h>
#define N 100005
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n, low, high;
struct Node {
	char id[10];
	int vir, tal;
} tmp, a[N];

bool is_sage(int i) {
	return a[i].vir>=high && a[i].tal>=high;
}

bool is_noble(int i) {
	return a[i].vir>=high && a[i].tal<high;
}

bool is_fool(int i) {
	return a[i].vir<high && a[i].tal<high && a[i].vir>=a[i].tal;
}

struct cmp {
	bool operator() (const int &p, const int &q) const {
		if(is_sage(p)) {
			if(is_sage(q)) {
				if(a[p].vir+a[p].tal != a[q].vir+a[q].tal)
					return a[p].vir+a[p].tal > a[q].vir+a[q].tal;
				if(a[p].vir != a[q].vir)
					return a[p].vir > a[q].vir;
				return strcmp(a[p].id, a[q].id) < 0;
			}
			return 1;
		}
		if(is_noble(p)) {
			if(is_sage(q))
				return 0;
			if(is_noble(q)) {
				if(a[p].vir+a[p].tal != a[q].vir+a[q].tal)
					return a[p].vir+a[p].tal > a[q].vir+a[q].tal;
				if(a[p].vir != a[q].vir)
					return a[p].vir > a[q].vir;
				return strcmp(a[p].id, a[q].id) < 0;
			}
			return 1;
		}
		if(is_fool(p)) {
			if(is_sage(q) || is_noble(q))
				return 0;
			if(is_fool(q)) {
				if(a[p].vir+a[p].tal != a[q].vir+a[q].tal)
					return a[p].vir+a[p].tal > a[q].vir+a[q].tal;
				if(a[p].vir != a[q].vir)
					return a[p].vir > a[q].vir;
				return strcmp(a[p].id, a[q].id) < 0;
			}
			return 1;
		}
		if(is_sage(q) || is_noble(q) || is_fool(q))
			return 0;
		if(a[p].vir+a[p].tal != a[q].vir+a[q].tal)
			return a[p].vir+a[p].tal > a[q].vir+a[q].tal;
		if(a[p].vir != a[q].vir)
			return a[p].vir > a[q].vir;
		return strcmp(a[p].id, a[q].id) < 0;
	}
};
int t[N];

int main() {
	scanf("%d%d%d", &n, &low, &high);
	int cnt = 0;
	while(n--) {
		scanf("%s%d%d", tmp.id, &tmp.vir, &tmp.tal);
		if(tmp.vir>=low && tmp.tal>=low) {
			a[cnt] = tmp;
			t[cnt] = cnt;
			++cnt;
		}
	}
	sort(t, t+cnt, cmp());
	printf("%d\n", cnt);
	rep(i,0,cnt) {
		printf("%s %d %d\n", a[t[i]].id, a[t[i]].vir, a[t[i]].tal);
	}
	return 0;
}
