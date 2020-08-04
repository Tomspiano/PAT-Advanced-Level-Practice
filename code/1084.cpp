#include<bits/stdc++.h>
#define N 85
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

char s[2][N], c;
unordered_set<char> us;
//set<char> us;

int main() {
	scanf("%s", s[0]);
	scanf("%s", s[1]);
	int len1=strlen(s[0]), len2=strlen(s[1]);
	int j = 0;
	rep(i,0,len1) {
		if(s[0][i] == s[1][j]) {
			++j;
		}
		else {
			c = s[0][i];
			if(c>='a' && c<='z')
				c = c - 'a' + 'A';
			if(us.find(c) == us.end()) {
				us.insert(c);
				printf("%c", c);
			}
		}
	}
	return 0;
}

