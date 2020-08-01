#include<bits/stdc++.h>
#define N 100005
#define P 2
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int word[P];
int n;
struct Node {
	int addr, next;
	char data;
	bool flag;
	Node() {
		flag = 0;
	}
} node[N];
map<int, int> id;
int suffix;

int main() {
	scanf("%d%d%d", &word[0], &word[1], &n);
	rep(i,0,n) {
		scanf("%d %c %d", &node[i].addr, &node[i].data, &node[i].next);
		id[node[i].addr] = i;
	}
	
	if(word[0]==-1 || word[1]==-1) {
		printf("-1\n");
		return 0;
	}
	
	do {
		node[id[word[0]]].flag = 1;
		word[0] = node[id[word[0]]].next;
	} while(word[0] != -1);
	
	suffix = -1;
	do {
		if(node[id[word[1]]].flag) {
			suffix = node[id[word[1]]].addr;
			break;
		}
		word[1] = node[id[word[1]]].next;
	} while(word[1] != -1);
	
	if(suffix != -1)
		printf("%05d\n", suffix);
	else printf("-1\n");
	return 0;
}

