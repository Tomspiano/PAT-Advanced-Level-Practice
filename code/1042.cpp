#include<bits/stdc++.h>
#define N 13
#define M 5
#define P 54
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n;
char cards[P][M];
int t[2][P+1];
int order[P+1];
const char cls[M-1] = {'S', 'H', 'C', 'D'};

void Init() {
	int k;
	rep(i,0,P-2) {
		k = 0;
		cards[i][k++] = cls[i/N];
		if((i%N+1)/10) cards[i][k++] = '1';
		cards[i][k++] = '0' + (i%N+1)%10;
		cards[i][k] = 0;
		t[0][i+1] = i;
	}
	cards[P-2][0] = cards[P-1][0] = 'J';
	cards[P-2][2] = cards[P-1][2] = 0;
	cards[P-2][1] = '1';
	cards[P-1][1] = '2';
	t[0][P-1] = P-2;
	t[0][P] = P-1;
}

int solve(int id) {
	int pre = id;
	id ^= 1;
	rep(i,1,P+1) {
		t[id][order[i]] = t[pre][i];
	}
	return id;
}

int main() {
	Init();
	scanf("%d", &n);
	rep(i,1,P+1) scanf("%d", &order[i]);
	int id = 0;
	while(n--) {
		id = solve(id);
	}
	rep(i,1,P+1) {
		if(i!=1) printf(" ");
		printf("%s", cards[t[id][i]]);
	}
	return 0;
}
