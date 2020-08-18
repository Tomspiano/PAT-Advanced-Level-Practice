#include<bits/stdc++.h>
#define N 100005
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int first, n;
struct Node {
	int addr, key, next;
} a[N], b[N], c[N];
map<int, int> mp;
set<int> s;

int main() {
	scanf("%d%d", &first, &n);
	int head;
	rep(i,0,n) {
		scanf("%d%d%d", &a[i].addr, &a[i].key, &a[i].next);
		mp[a[i].addr] = i;
		if(a[i].addr == first)
			head = i;
	}
	
	int id1=0, id2=0;
	b[id1++] = a[head];
	s.insert(abs(a[head].key));
	while(a[head].next != -1) {
//printf("%05d %d %05d\n", a[head].addr, a[head].key, a[head].next);
		head = mp[a[head].next];
		if(s.find(abs(a[head].key)) == s.end()) {
			b[id1++] = a[head];
			s.insert(abs(a[head].key));
		}
		else {
			c[id2++] = a[head];
		}
	}
	rep(i,0,id1-1) {
		printf("%05d %d %05d\n", b[i].addr, b[i].key, b[i+1].addr);
	}
	printf("%05d %d -1\n", b[id1-1].addr, b[id1-1].key);
	rep(i,0,id2-1) {
		printf("%05d %d %05d\n", c[i].addr, c[i].key, c[i+1].addr);
	}
	if(id2) printf("%05d %d -1\n", c[id2-1].addr, c[id2-1].key);
	return 0;
}
