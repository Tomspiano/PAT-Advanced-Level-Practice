#include<bits/stdc++.h>
#define N 100005
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n, num;
set<int> s;
typedef set<int>::iterator IT;
pair<IT, bool> f;
map<int, int> mp;
typedef map<int, int>::iterator iter;
int id=N, ans;

int main() {
	scanf("%d", &n);
	rep(i,0,n) {
		scanf("%d", &num);
		f = s.insert(num);
		if(f.second)
			mp[num] = i;
		else
			mp.erase(num);
	}
	
	if(mp.empty()) printf("None\n");
	else {
		for(iter i=mp.begin(); i!=mp.end(); ++i)
			if(i->second < id) {
				ans = i->first;
				id = i->second;
			}
				
		printf("%d\n", ans); 
	}
	
	return 0;
}

