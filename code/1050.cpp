#include<bits/stdc++.h>
#define N 10005
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

unordered_set<char> us;
//set<char> us;
char s[N], c;

int main() {
	cin.getline(s, N);
	while(c=getchar(), c!='\n')
		us.insert(c);
	
	int len = strlen(s);
	rep(i,0,len) {
		if(us.find(s[i]) != us.end())
			continue;
		printf("%c", s[i]);
	}
	return 0;
}
