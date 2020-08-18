#include<bits/stdc++.h>
#define N 100000
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long LL;

LL n;
vector<LL> p;
vector<LL>::iterator k;
//clock_t beg_t, end_t;

void table() {
//beg_t = clock();
	LL upper = N;
	vector<bool> vis(upper, 0);
	rep(i,2,upper) {
		if(!vis[i]) {
			p.push_back(i);
			for(int j=1; i*j<=upper; ++j) {
				vis[i*j] = 1;
			} 
		}
	}
//end_t = clock();
//printf("%f\n", (double)(end_t-beg_t)/CLOCKS_PER_SEC);
	return;
}

int main() {
	scanf("%lld", &n);
	table();
	int cnt;
	bool flag = 0;
	printf("%lld", n);
	if(n == 1) {
		printf("=1");
		return 0;
	}
	
	for(k=p.begin(); k!=p.end(); ++k) {
		if(n%(*k) == 0) {
			if(!flag) {
				printf("=");
				flag = 1;
			}
			else
				printf("*");
			cnt = 0;
			while(n%(*k) == 0) {
				++cnt;
				n /= *k;
			}
			
			printf("%lld", *k);
			if(cnt > 1)
				printf("^%d", cnt);
		}
	}
	return 0;
}

