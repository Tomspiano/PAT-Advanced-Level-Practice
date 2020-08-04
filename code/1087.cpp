#include<bits/stdc++.h>
#define N 205
#define INF 0x7fffffff
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n, k;
int h[N];
int g[N][N], src, dst;
bool vis[N];
string tsrc, t;
const string tdst = "ROM";
map<string, int> mp;
vector<string> vec;
int cnt, cst, hap, sum;
int path[N], tmp[N];

void dfs(int r, int tcst, int thap, int tsum) {
	if(tcst > cst) return ;
	if(r == dst) {
		if(tcst == cst) {
			if(thap == hap) {
				if(tsum < sum) {
					sum = tsum;
					memcpy(path, tmp, sizeof(path));
				}
			}
			else if(thap > hap) {
				hap = thap;
				sum = tsum;
				memcpy(path, tmp, sizeof(path));
			}
			++cnt;
		}
		else {
			cst = tcst;
			cnt = 1;
			hap = thap;
			sum = tsum;
			memcpy(path, tmp, sizeof(path));
		}
		return ;
	}
	
	tmp[tsum++] = r;
	rep(i,0,n) {
		if(g[r][i] && !vis[i]) {
			vis[i] = 1;
			dfs(i, tcst+g[r][i], thap+h[i], tsum);
			vis[i] = 0;
		}
	}
	return ;
}

int main() {
	cin >> n >> k;
	cin >> tsrc;
	vec.push_back(tsrc);
	src = 0;
	rep(i,1,n) {
		cin >> t >> h[i];
		mp[t] = i;
		vec.push_back(t);
		if(t==tdst) dst=i;
	}
	
	memset(g, 0, sizeof(g));
	while(k--) {
		cin >> tsrc >> t;
		cin >> g[mp[tsrc]][mp[t]];
		g[mp[t]][mp[tsrc]] = g[mp[tsrc]][mp[t]];
	}
	
	memset(vis, 0, sizeof(vis));
	vis[src] = 1;
	cst = INF;
	dfs(src,0,0,0);
	
	printf("%d %d %d %d\n", cnt, cst, hap, hap/sum);
	rep(i,0,sum) {
		printf("%s->", vec[path[i]].c_str());
	}
	printf("ROM\n");
	return 0;
}

