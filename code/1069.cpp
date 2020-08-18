#include<bits/stdc++.h>
#define N 4
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b-1); i>=(a); --i)

char tmp[N];
int a[2][N];
const int cond[2][N] = {0,0,0,0, 4,7,1,6};

int main() {
	scanf("%s", tmp);
	int len = strlen(tmp);
	rep(i,0,len) {
		a[0][i] = tmp[i] - '0';
	}
	rep(i,len,N) a[0][i] = 0;
	
	int id=0, pre, carr=0;
	bool f1, f2;
	do {
		sort(a[id], a[id]+N);
		pre = id;
		id ^= 1;
		rep(i,0,N) {
			a[id][i] = a[pre][i] - a[pre][N-1-i] + carr;
			if(a[id][i] < 0) {
				a[id][i] += 10;
				carr = -1;
			}
			else carr = 0;
		}
		
		per(i,0,N) printf("%d", a[pre][i]);
		printf(" - ");
		rep(i,0,N) printf("%d", a[pre][i]);
		printf(" = ");
		f1 = f2 = 1;
		per(i,0,N) {
			printf("%d", a[id][i]);
			if(a[id][i] != cond[0][i])
				f1 = 0;
			if(a[id][i] != cond[1][i])
				f2 = 0;
		}
		printf("\n");
	} while(!f1 && !f2);
	return 0;
}

