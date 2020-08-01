#include<bits/stdc++.h>
#define N 100005
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n, c;
struct Stu {
	char id[10], name[10];
	int grade;
} s[N];
int t[N];

struct cmp1 {
	bool operator() (const int a, const int b) const {
		return strcmp(s[a].id, s[b].id) < 0;
	}
};
struct cmp2 {
	bool operator() (const int a, const int b) const {
		if(strcmp(s[a].name, s[b].name) != 0)
			return strcmp(s[a].name, s[b].name) < 0;
		return strcmp(s[a].id, s[b].id) < 0;
	}
};
struct cmp3 {
	bool operator() (const int a, const int b) const {
		if(s[a].grade != s[b].grade)
			return s[a].grade < s[b].grade;
		return strcmp(s[a].id, s[b].id) < 0;
	}
};


int main() {
	scanf("%d%d", &n, &c);
	rep(i,0,n) {
		t[i] = i;
		scanf("%s%s%d", s[i].id, s[i].name, &s[i].grade);
	}
	switch(c) {
		case 1: {
			sort(t, t+n, cmp1());
			break;
		}
		case 2: {
			sort(t, t+n, cmp2());
			break;
		}
		case 3: {
			sort(t, t+n, cmp3());
			break;
		}
	}
	rep(i,0,n)
		printf("%s %s %d\n", s[t[i]].id, s[t[i]].name, s[t[i]].grade);
	return 0;
}

