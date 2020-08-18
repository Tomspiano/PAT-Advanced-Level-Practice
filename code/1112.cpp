#include<bits/stdc++.h>
#define N 1005
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int k;
char s[N];
set<char> mp;
char book[N];
set<char>::iterator j;

int main() {
	scanf("%d%s", &k, s);
	int len = strlen(s);
	int cnt = 1;
	int id = 0;
	rep(i,1,len) {
		if(s[i]==s[i-1]) {
			++cnt;
		}
		else {
			j = mp.find(s[i-1]);
			if(cnt%k == 0) {
				if(j == mp.end()) {
					book[id++] = s[i-1];
					mp.insert(s[i-1]);
				}
			}
			else {
				if(j != mp.end())
					mp.erase(j);
			}
			cnt = 1;
		}
	}
	
	if(cnt > 1) {
		j = mp.find(s[len-1]);
		if(cnt%k == 0) {
			if(j == mp.end()) {
				book[id++] = s[len-1];
				mp.insert(s[len-1]);
			}
		}
		else {
			if(j != mp.end())
				mp.erase(j);
		}
	}
	
	rep(i,0,id) {
		if(mp.find(book[i]) != mp.end())
			printf("%c", book[i]);
	}
	printf("\n");
	int i = 0;
	do {
		printf("%c", s[i]);
		if(mp.find(s[i]) != mp.end())
			i += k;
		else ++i;
	} while(i < len);
	return 0;
}

