#include<bits/stdc++.h>
#define N 100005
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int first, n, k;
struct Node {
	int addr, data, next;
} a[N];
map<int, int> mp;
int t[N];

int main() {
	scanf("%d%d%d", &first, &n, &k);
	rep(i,0,n) {
		scanf("%d%d%d", &a[i].addr, &a[i].data, &a[i].next);
		mp[a[i].addr] = i;
	}
	
	int cnt = 0;
	t[cnt++] = mp[first];
	while(a[mp[first]].next != -1) {
		first = a[mp[first]].next;
		t[cnt++] = mp[first];	
	}
	
	int i = 0;
	while(i+k <= cnt) {
		rep(j,0,k/2)
			swap(t[i+j], t[i+k-1-j]);
		i += k;
	}
	
	rep(i,0,cnt-1) {
		printf("%05d %d %05d\n", a[t[i]].addr, a[t[i]].data, a[t[i+1]].addr);
	}
	printf("%05d %d -1\n", a[t[cnt-1]].addr, a[t[cnt-1]].data);
	return 0;
}

