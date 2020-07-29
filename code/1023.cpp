#include<bits/stdc++.h>
#define N 10
#define M 25
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b-1); i>=(a); --i)

char n;
int num[M], ans[M];
int vis[N];
const int d[N] = {0, 2, 4, 6, 8, 0, 2, 4, 6, 8};

void solve(int len) {
	int carr = 0;
	bool flag = 1;
	per(i,0,len) {
		ans[i] = d[num[i]] + carr;
		if(num[i] >= 5)
			carr = 1;
		else
			carr = 0;
		
		--vis[ans[i]];
		if(flag && vis[ans[i]]<0) {
			flag = 0;
			cout << "No\n";
		}
	}
	if(flag && carr) {
		flag = 0;
		cout << "No\n";
	}
	if(flag) cout << "Yes\n";
	
	if(carr) cout << carr;
	rep(i,0,len) {
		cout << ans[i];
	}
	return;
}

int main() {
	int len = 0;
	while(n=getchar(), n!='\n') {
		num[len++] = n - '0';
		++vis[n - '0'];
	}
	
	solve(len);
	
	return 0;
}

