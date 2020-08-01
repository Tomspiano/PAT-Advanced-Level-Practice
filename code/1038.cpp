#include<bits/stdc++.h>
#define N 10005
#define M 10
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n;
char num[N][M];
int t[N];

struct cmp {
	bool operator() (const int a, const int b) {
		char str[2][2*M];
		strcpy(str[0], num[a]); strcat(str[0], num[b]);
		strcpy(str[1], num[b]); strcat(str[1], num[a]);
		return strcmp(str[0], str[1]) < 0;
	}
};

int main() {
	scanf("%d", &n);
	
	rep(i,0,n) {
		scanf("%s", num[i]);
		t[i] = i;
	}
	sort(t, t+n, cmp());
	
	bool flag = 0;
	rep(i,0,n) {
		if(!flag) {
			int j = 0;
			int len = strlen(num[t[i]]);
			while(j<len && num[t[i]][j]=='0') ++j;
			if(j<len) {
				flag = 1;
				while(j<len) printf("%c", num[t[i]][j++]);
			}
		}
		else
			printf("%s", num[t[i]]);
	}
	if(!flag) printf("0");
	
	return 0;
}

