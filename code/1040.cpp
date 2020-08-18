#include<bits/stdc++.h>
#define N 1005
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b-1); i>=(a); --i)

char s[N];
bool dp[N][N];
int mlen;

int main() {
	memset(dp, 0, sizeof(dp));
	cin.getline(s, N);
	int len = strlen(s);
	rep(i,0,len) {
		dp[i][i] = 1;
		if(i == len-1) continue;
		dp[i][i+1] = (s[i] == s[i+1]);
	}
	rep(j,2,len) {
		rep(i,0,j-1) {
			dp[i][j] = (dp[i+1][j-1] && (s[i] == s[j]));
		}
	}
	
	mlen = 0;
	rep(i,0,len) {
		per(j,i,len) {
			if(dp[i][j]) {
				if(j+1-i > mlen)
					mlen = j+1-i;
				break;
			}
		}
	}
	printf("%d", mlen);
	return 0;
}
