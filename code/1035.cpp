#include<bits/stdc++.h>
#define N 1005
#define M 15
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n;
struct Usr {
	char name[M], pssw[M];
} usr[N];
int id[N];

int main() {
	scanf("%d", &n);
	rep(i,0,n) {
		scanf("%s%s", usr[i].name, usr[i].pssw);
	}
	
	int cnt = 0;
	int len;
	bool flag;
	rep(i,0,n) {
		flag = 0;
		len = strlen(usr[i].pssw);
		rep(j,0,len) {
			if(usr[i].pssw[j] == '1') {
				usr[i].pssw[j] = '@';
				flag = 1;
			}
				
			else if(usr[i].pssw[j] == '0') {
				usr[i].pssw[j] = '%';
				flag = 1;
			}
				
			else if(usr[i].pssw[j] == 'l') {
				usr[i].pssw[j] = 'L';
				flag = 1;
			}
				
			else if(usr[i].pssw[j] == 'O') {
				usr[i].pssw[j] = 'o';
				flag = 1;
			}
		}
		
		if(flag) {
			id[cnt++] = i;
		}
	}
	
	if(cnt) {
		printf("%d\n", cnt);
		rep(i,0,cnt) {
			printf("%s %s\n", usr[id[i]].name, usr[id[i]].pssw);
		}
	}
	
	else {
		if(n!=1) printf("There are %d accounts and no account is modified\n", n);
		else printf("There is 1 account and no account is modified\n");
	}
	
	return 0;
}
