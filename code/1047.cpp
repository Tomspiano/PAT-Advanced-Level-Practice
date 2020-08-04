#include<bits/stdc++.h>
#define N 40005
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n, k, c, t;
string name;
vector<string> vec[N];
vector<string>::iterator j;

int main( ) {
	cin >> n >> k;
	while(n--) {
		cin >> name >> c;
		while(c--) {
			cin >> t;
			vec[t].push_back(name);
		}
	}
	rep(i,1,k+1) {
		printf("%d %d\n", i, vec[i].size());
		sort(vec[i].begin(), vec[i].end());
		for(j=vec[i].begin(); j!=vec[i].end(); ++j)
			cout << *j << "\n";
	}
	return 0;
}

