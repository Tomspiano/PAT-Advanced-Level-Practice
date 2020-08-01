#include<bits/stdc++.h>
#define N 100005
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n[2];
int num[2][N];

int main() {
	rep(i,0,2)  {
		scanf("%d", &n[i]);
		rep(j,0,n[i]) {
			scanf("%d", &num[i][j]);
		}
		sort(num[i], num[i]+n[i]);
	}
	
	long long sum = 0;
	int i=n[0]-1, j=n[1]-1;
	while(i>=0 && j>=0 && num[0][i]>0 && num[1][j]>0) {
		sum += num[0][i] * num[1][j];
		--i; --j;
	}
	if(i>=0 && j>=0) {
		int p=0, q=0;
		while(i>=0 && num[0][i]>=0) --i;
		while(j>=0 && num[1][j]>=0) --j;
		while(p<=i && q<=j) {
			sum += num[0][p] * num[1][q];
			++p; ++q;
		}
	}
	printf("%lld", sum);
	return 0;
}
