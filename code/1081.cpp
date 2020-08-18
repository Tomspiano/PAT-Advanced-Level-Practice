#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;
LL a, b;

LL gcd(LL p, LL q) {
	p=abs(p), q=abs(q);
	
	LL t;
	if(p < q) {
		t=p, p=q, q=t;
	}
	while(q) {
		t = p%q;
		p = q;
		q = t;
	}
	return p;
}


int main() {
	scanf("%d", &n);
	LL t, num=0, den=1;
	while(n--) {
		scanf("%lld/%lld", &a, &b);
		t = gcd(a, b);
		a/=t, b/=t;
		
		num = num*b + den*a;
		den *= b;
		t = gcd(den, num);
		den/=t, num/=t;
//printf("%d/%d\n", num, den);
	}
	
	t = num/den;
	num -= t*den;
	if(t) printf("%lld", t);
	if(t && num) printf(" ");
	if(num) printf("%lld/%lld\n", abs(num), den);
	if(!t && !num) printf("0\n");
	return 0;
}

