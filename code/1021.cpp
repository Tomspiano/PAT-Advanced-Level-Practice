#include<bits/stdc++.h>
#define N 10005
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n, a,b;
vector<int> g[N];
vector<int>::iterator k;
bool vis[N];
int cnt;
set<int> s;
set<int>::iterator j;
int depth;
queue<int> q;

int main() {
	memset(vis, 0, sizeof(vis));
	scanf("%d", &n);

	rep(i,0,n-1) {
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	cnt = 0;
	int t, fst, lst, dep;
	bool flag;
	rep(i,1,n+1) {
		if(!vis[i]) {
			q.push(i);
			vis[i] = 1;
			fst = lst = i;
			dep = 0;
			while(!q.empty()) {
				t = q.front();
				flag = 1;
				for(k=g[t].begin(); k!=g[t].end(); ++k) {
					if(!vis[*k]) {
						flag = 0;
						vis[*k] = 1;
						q.push(*k);
						lst = *k;
					}
				}
				if(flag) s.insert(t);
				if(fst == t) {
					++dep;
					fst = lst;
				}
				q.pop();
			}
			depth = dep;
			++cnt;
		}
	}
	
	if(cnt > 1) printf("Error: %d components\n", cnt);
	else {
		memset(vis, 0, sizeof(vis));
		
		q.push(*s.begin());
		vis[*s.begin()] = 1;
		fst = lst = *s.begin();
		dep = 0;
		while(!q.empty()) {
			t = q.front();
			flag = 1;
			for(k=g[t].begin(); k!=g[t].end(); ++k) {
				if(!vis[*k]) {
					flag = 0;
					vis[*k] = 1;
					q.push(*k);
					lst = *k;
				}
			}
			if(flag) s.insert(t);
			if(fst == t) {
				++dep;
				fst = lst;
			}
			q.pop();
		}
		depth = max(depth, dep);
		
		for(j=s.begin(); j!=s.end(); ++j)
			printf("%d\n", *j);
	}
	
	return 0;
}

