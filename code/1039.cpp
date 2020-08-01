#include<bits/stdc++.h>
#define K 2505
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n, k;
int id, num;
string stu;
unordered_map<string, vector<int> > mp;
vector<int>::iterator j;

int main() {
	scanf("%d%d", &n, &k);
	while(k--) {
		scanf("%d%d", &id, &num);
		while(num--) {
			cin >> stu;
			mp[stu].push_back(id);
		}
	}
	while(n--) {
		cin >> stu;
		printf("%s", stu.c_str());
		printf(" %d", mp[stu].size());
		sort(mp[stu].begin(), mp[stu].end());
		for(j=mp[stu].begin(); j!=mp[stu].end(); ++j)
			printf(" %d", *j);
		printf("\n");
	}
	return 0;
}
