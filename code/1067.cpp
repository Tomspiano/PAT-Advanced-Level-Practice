#include<bits/stdc++.h>
#define N 100005
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n;
int a[N];
unordered_map<int, int> mp;

int main() {
	int cnt = 0;
	scanf("%d", &n);
	int r, tmp;
	rep(i,0,n) {
		scanf("%d", &a[i]);
		if(a[i] == 0)
			r = i;
		else if(a[i] != i) {
			mp[a[i]] = i;
//printf("insert %d\n", a[i]);
		}
	}
	while(!mp.empty()) {
		if(r == 0) {
			tmp = mp.begin()->second;
			mp.begin()->second = r;
//printf("%d %d\n", 0, r);
			r = tmp;
		}
		else {
			tmp = mp[r];
//printf("%d %d\n", r, mp.find(r)->second);
			mp.erase(mp.find(r));
			r = tmp;
		}
		++cnt;
	}
	printf("%d\n", cnt);
	return 0;
}

