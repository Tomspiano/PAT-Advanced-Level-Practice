#include<bits/stdc++.h>
#define N 100005
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long LL;

int n, d;
bool primes[N];

void table() {
	memset(primes, 0, sizeof(primes));
	primes[0] = primes[1] = 1;
	rep(i,2,N) {
		if(!primes[i]) {
			int j = 2;
			while(j*i<N) {
				primes[j*i] = 1;
				++j;
			}
		}
	}
}

int trans(int num, int radix) {
	stack<int> st;
	while(num) {
		st.push(num%radix);
		num /= radix;
	}
//printf("%.0f ", pow(2, st.size()-1));
	int ans = 0;
	int r = 1;
	while(!st.empty()) {
		ans += r*(st.top());
		st.pop();
		r *= radix;
	}
//printf("%d ", ans);
	return ans;
}

int main() {
	table();
	
	while(scanf("%d", &n), n>=0) {
		scanf("%d", &d);
		if(!primes[n]) {
			int num = trans(n, d);
			if(!primes[num])
				printf("Yes\n");
			else
				printf("No\n");
		}
		else
			printf("No\n");
	}
	
	return 0;
}
