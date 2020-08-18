#include<bits/stdc++.h>
#define N 10005
using namespace std;
#define mkp make_pair

int n, t1, t2;
map<int, int> cp;
set<int> tmp, sing;
set<int>::iterator j;

int main() {
	scanf("%d", &n);
	while(n--) {
		scanf("%d%d", &t1, &t2);
		cp.insert(mkp(t1, t2));
		cp.insert(mkp(t2, t1));
	}
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &t1);
		tmp.insert(t1);
	}
	
	for(j=tmp.begin(); j!=tmp.end(); ++j) {
		if(cp.find(*j) == cp.end() || tmp.find(cp[*j]) == tmp.end())
			sing.insert(*j);
	}
	
	printf("%d\n", sing.size());
	j = sing.begin();
	while(j != sing.end()) {
		printf("%05d", *j);
		++j;
		printf("%c", j==sing.end() ? '\n' : ' ');	
	}
	return 0;
}
