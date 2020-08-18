#include<bits/stdc++.h>
#define N 100005
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

bool vis[N];
set<int> prime, check;
map<int, int> mp;  // id, pos
int a[N];
const char ans[5][100] = {"Are you kidding?", 
	"Mystery Award", "Minion", "Chocolate",
	"Checked"};

void table() {
	memset(vis, 0, sizeof(vis));
	rep(i,2,N) {
		if(!vis[i]) {
			prime.insert(i);
			for(int j=1; i*j<N; ++j)
				vis[i*j] = 1;
		}
	}
	return;
}

int main() {
	table();
	int n, k, id;
	scanf("%d", &n);
	rep(i,1,n+1) {
		scanf("%d", &a[i]);
		mp[a[i]] = i;
	}
	
	scanf("%d", &k);
	while(k--) {
		scanf("%d", &id);
		if(check.find(id) != check.end())
			printf("%04d: %s\n", id, ans[4]);
		else {
			if(mp.find(id) == mp.end())
				printf("%04d: %s\n", id, ans[0]);
			else {
				check.insert(id);
				if(mp[id] == 1)
					printf("%04d: %s\n", id, ans[1]);
				else {
					if(prime.find(mp[id]) == prime.end())
						printf("%04d: %s\n", id, ans[3]);
					else
						printf("%04d: %s\n", id, ans[2]);
				}
			}	
		}
	}
	return 0;;
}

