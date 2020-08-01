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
} node[N];
map<int, int> id;
vector<int> vec[P];
vector<int>::iterator j, k;
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
	
	rep(i,0,P) {
		do {
			vec[i].push_back(id[word[i]]);
			word[i] = node[id[word[i]]].next;
		} while(word[i] != -1);
	}
	
	suffix = -1;
	j = vec[0].end();
	k = vec[1].end();
	do {
		--j; --k;
		if(*j == *k)
			suffix = node[*j].addr;
		else
			break;
	} while(j!=vec[0].begin() && k!=vec[1].begin());
	if(suffix != -1)
		printf("%05d\n", suffix);
	else printf("-1\n");
	return 0;
}

