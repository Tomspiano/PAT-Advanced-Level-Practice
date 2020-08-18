#include<bits/stdc++.h>
#define N 100005
#define MOD 1000000007
using namespace std;

char s[N];


int main() {
	int p, t;
	scanf("%s", s);
	int len = strlen(s);
	p = t = 0;
	int i = 0;
	while(i<len && s[i]!='A') {
		if(s[i] == 'P')
			++p;
		++i;
	}
	int j = len-1;
	while(j>i) {
		if(s[j] == 'T')
			++t;
		--j;
	}
	
	long long sum = 0;
	while(i<len) {
		if(s[i] == 'A')
			sum = (sum%MOD + ((p%MOD)*(t%MOD))%MOD)%MOD;
		else if(s[i] == 'P')
			++p;
		else 
			--t;
		++i;
	}
	printf("%lld\n", sum);
	return 0;
}

