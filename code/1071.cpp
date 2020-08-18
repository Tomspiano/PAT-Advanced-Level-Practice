#include<bits/stdc++.h>
#define N 1048580
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

char c;
string s;
map<string, int> mp;

struct cmp {
	bool operator() (const pair<string, int> a, const pair<string, int> b) const {
		if(a.second != b.second)
			return a.second > b.second;
		return a.first < b.first;
	}
};

int main() {
	s = "";
	while(1) {
		c = getchar();
		if(c>='0' && c<='9'
		|| c>='a' && c<='z'
		|| c>='A' && c<='Z') {
			if(c>='A' && c<='Z')
				c = c - 'A' + 'a';
			s += c;
		}
		else if(s != ""){
			++mp[s];
			s = "";
		}
		if(c == '\n')
			break;
	}
	vector<pair<string, int> > vec(mp.begin(), mp.end());
	sort(vec.begin(), vec.end(), cmp());
	printf("%s %d\n", vec.begin()->first.c_str(), vec.begin()->second);
	return 0;
}
