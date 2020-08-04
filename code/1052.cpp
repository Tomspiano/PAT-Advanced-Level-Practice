#include<bits/stdc++.h>
#define N 100005
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n, head;
struct Node {
	int addr, key, next;
	bool operator< (const Node &t) const {
		return key < t.key;
	}
} t[N], a[N];
map<int, int> mp;
int cnt;

int main() {
	scanf("%d%d", &n, &head);
	rep(i,0,n) {
		scanf("%d%d%d", &t[i].addr, &t[i].key, &t[i].next);
		mp[t[i].addr] = i;
	}
	
	cnt = 0;
	while(head != -1) {
		a[cnt++] = t[mp[head]];
		head = t[mp[head]].next;
	}
	sort(a, a+cnt);
	
	if(cnt) printf("%d %05d\n", cnt, a[0].addr);
	else printf("%d -1\n", cnt);
	rep(i,0,cnt-1) {
		printf("%05d %d %05d\n", a[i].addr, a[i].key, a[i+1].addr);
	}
	if(cnt) printf("%05d %d -1\n", a[cnt-1].addr, a[cnt-1].key);
	return 0;
}
