#include<bits/stdc++.h>
#define N 4
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long LL;

LL a1,b1, a2,b2, t;
LL ans[N][3];
const char op[N] = {'+', '-', '*', '/'};

LL gcd(LL a, LL b) {
	a=abs(a), b=abs(b);
	LL tmp;
	if(a < b) {
		tmp=a, a=b, b=tmp;
	}
	
	while(b) {
		tmp = a%b;
		a = b;
		b = tmp;
	}
	return a;
}

void solve(int id) {
	LL num, den=b1*b2;
	switch(id) {
		case 0: {
			num = a1*b2 + a2*b1;
			break;
		}
		case 1: {
			num = a1*b2 - a2*b1;
			break;
		}
		case 2: {
			num = a1*a2;
			break;
		}
		case 3: {
			den = b1*a2;
			num = a1*b2;
			den=abs(den), num=abs(num);
			if(a1*a2 < 0)
				num = -num;
			break;
		}
	}
	t = gcd(num,den);
	num/=t, den/=t;
	if(den) ans[id][0] = num/den;
	ans[id][1] = num - ans[id][0]*den;
	ans[id][2] = den;
//rep(i,0,3) printf("%d ", ans[id][i]); printf("\n");
	return ;
}

void Prt(LL t1, LL a1, LL b1) {
	if(b1 == 0) {
		printf("Inf");
		return ;
	}
	if(t1<0 || a1<0) printf("(");
	if(t1 != 0) printf("%lld", t1);
	if(a1 != 0) {
		if(t1 != 0) printf(" ");
		if(t1 < 0) printf("%lld", -a1);
		else printf("%lld", a1);
	}
	if(!t1 && !a1) printf("0");
	else if(b1 != 1) printf("/%lld", b1);
	if(t1<0 || a1<0) printf(")");
	return ;
}

int main() {
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
	t = gcd(a1,b1);
	a1/=t, b1/=t;
	t = gcd(a2,b2);
	a2/=t, b2/=t;
	
	rep(i,0,N) solve(i);
	
	LL t1, t2;
	t1=a1/b1, t2=a2/b2;
	a1-=t1*b1, a2-=t2*b2;
	rep(i,0,N) {	
		Prt(t1,a1,b1);
		printf(" %c ", op[i]);
		
		Prt(t2,a2,b2);
		printf(" = ");
		
		Prt(ans[i][0], ans[i][1], ans[i][2]);
		printf("\n");
	}
	return 0;
}

