#include<bits/stdc++.h>
#define N 105
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b-1); i>=(a); --i)

int n, b;
int num[N];

int main() {
	cin >> n >> b;
	int i = 0;
	while(n) {
		num[i++] = n%b;
		n /= b;
	}
	
	bool flag = 1;
	rep(j,0,i/2) {
		if(num[j] != num[i-1-j]) {
			flag = 0;
			cout << "No\n";
			break;
		}
	}
	if(flag) cout << "Yes\n";
	per(j,0,i) cout << num[j] << (j==0 ? '\n' : ' ');
	return 0;
}
