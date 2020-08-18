#include<bits/stdc++.h>
#define N 35
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n;

int main() {
//while(~
	scanf("%d", &n);
//) {
	int sum = 0, r = 1;
	int lf, curr, rt;
	while(n/r) {
		lf=n/(r*10), curr=n/r%10, rt=n%r;
		if(curr == 0) {
//printf("%d ", lf*r);
			sum += lf*r;
		}	
		else if(curr == 1) {
//printf("%d ", lf*r + rt + 1);
			sum += lf*r + rt + 1;	
		}
		else {
//printf("%d ", (lf + 1)*r);
			sum += (lf + 1)*r; 
		}
		r *= 10;
	}
	printf("%d\n", sum);
//}
	return 0;
}

