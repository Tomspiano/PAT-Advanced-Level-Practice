#include<bits/stdc++.h>
#define N 200005
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

long long a[N], ans;
int t1, t2, mid, cnt, tmp;

int main() {
	scanf("%d", &t1);
	rep(i,0,t1) scanf("%d", &a[i]);
	scanf("%d", &t2);
	mid = (t1 + t2)/2 + ((t1 + t2)&1 ? 1 : 0);
	cnt = 0;
	int j = 0;
	rep(i,0,t2) {
		scanf("%d", &tmp);
		while(cnt<mid && j<t1 && a[j]<tmp) {
			++cnt;
//printf("%d:%d:%d\n", cnt, j, a[j]);
			if(cnt == mid) {
				ans = a[j];
				break;
			}
			++j;
		}
		++cnt;
//printf("%d:%d\n", cnt, tmp);
		if(cnt == mid)
			ans = tmp;
	}
	if(cnt < mid) {
		while(j < t1) {
			++cnt;
			if(cnt == mid) {
				ans = a[j];
				break;
			}
			++j;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

