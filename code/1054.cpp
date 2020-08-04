#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

unordered_map<int, int> ump;
int m, n, tmp;

int main() {
	scanf("%d%d", &m, &n);
	rep(i,0,n) rep(j,0,m) {
		scanf("%d", &tmp);
		ump[tmp]++;
	}
	
	int ans, cnt=0;
	for(auto i=ump.begin(); i!=ump.end(); ++i) {
		if(i->second > cnt) {
			cnt = i->second;
			ans = i->first;
		}
	}
	printf("%d", ans);
	return 0;
}

