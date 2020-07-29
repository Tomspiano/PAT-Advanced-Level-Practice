#include<bits/stdc++.h>
#define N 3
#define M 2
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n[N];
char color[M];
const int radix = 13;

char trans(int num) {
	if(num>=0 && num<=9) return num+'0';
	return num - 10 + 'A';
}

int main() {
	cin >> n[0] >> n[1] >> n[2];
	
	cout << '#';
	int j;
	rep(i,0,N) {
		j = M - 1;
		if(n[i] < radix)
			color[0] = '0';
		do {
			color[j--] = trans(n[i]%radix);
			n[i] /= radix;
		} while(n[i]);
		rep(j,0,M) cout << color[j];
	}
	
	return 0;
}
