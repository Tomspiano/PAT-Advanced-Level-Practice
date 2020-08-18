#include<bits/stdc++.h>
#define N 65
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

char s[4][N];
const char d[7][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};


int main() {
	rep(i,0,4) scanf("%s", s[i]);
	
	int len1=strlen(s[0]), len2=strlen(s[1]);
	int i=0, j=0;
	while(i<len1 && j<len2) {
		if(s[0][i]==s[1][j] && s[0][i]>='A' && s[0][i]<='G') {
			break;
		}
		++i, ++j;
	}
	printf("%s ", d[s[0][i]-'A']);
	
	++i, ++j;
	while(i<len1 && j<len2) {
		if(s[0][i]==s[1][j] && 
		(s[0][i]>='A' && s[0][i]<='N' || s[0][i]>='0' && s[0][i]<='9')) {
			break;
		}
		++i, ++j;
	}
	printf("%02d:", s[0][i]-(s[0][i]>='A' && s[0][i]<='N' ? 'A' : '0')+
							(s[0][i]>='A' && s[0][i]<='N' ? 10 : 0));
	
	len1=strlen(s[2]), len2=strlen(s[3]);
	i=0, j=0;
	while(i<len1 && j<len2) {
		if(s[2][i]==s[3][j] && 
		(s[2][i]>='A' && s[2][i]<='Z' || s[2][i]>='a' && s[2][i]<='z')) {
			break;
		}
		++i, ++j;
	}
	printf("%02d", i);
	return 0;
}

