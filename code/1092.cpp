#include<bits/stdc++.h>
#define N 1005
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

char a[N], b[N];
map<char, int> mp;
map<char, int>::iterator j;
const char ans[2][5] = {"No", "Yes"};

int main() {
	scanf("%s%s", a, b);
	int len1=strlen(a), len2=strlen(b);
	int cnt1=0, cnt2=0;
	rep(i,0,len1)
		++mp[a[i]];
	rep(i,0,len2) {
		if(mp.find(b[i])==mp.end() || !mp[b[i]]) {
			++cnt2;
		}
		else {
			--mp[b[i]];
		}
	}
	if(!cnt2) {
		for(j=mp.begin(); j!=mp.end(); ++j) {
			cnt1 += j->second;
		}
	}
	printf("%s %d\n", ans[cnt2 ? 0 : 1], (cnt2 ? cnt2 : cnt1));
	return 0;
}

