#include<bits/stdc++.h>
#define N 10005
#define K 10
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n, k, m;
int pro[K];
struct Usr {
	int p[K];
	int sum, cnt;
	bool flag;
	Usr() {
		memset(p, -1, sizeof(p));
		sum = cnt = 0;
		flag = 0;
	}
	void add() {
		rep(i,1,k+1) {
			if(p[i] > 0)
				sum += p[i]; 
//printf("%d:%d ", i, p[i]);
		}
//printf("\n");
	}
	void update(int id, int score) {
		if(score==-1 && p[id]<0) {
			p[id] = -2;
		}
		else if(score > p[id]) {
			flag = 1;
			p[id] = score;
			if(score == pro[id])
				++cnt;
		}
//printf("%d:%d\n", id, p[id]);
	}
} usr[N];
struct cmp {
	bool operator() (const int a, const int b) const {
		if(usr[a].sum != usr[b].sum)
			return usr[a].sum > usr[b].sum;
		if(usr[a].cnt != usr[b].cnt)
			return usr[a].cnt > usr[b].cnt;
		return a < b;
	}
};
int t[N];

int main() {
	scanf("%d%d%d", &n, &k, &m);
	rep(i,1,k+1) scanf("%d", &pro[i]);
	int id, pid, ps;
	while(m--) {
		scanf("%d%d%d", &id, &pid, &ps);
		usr[id].update(pid, ps);
	}
	rep(i,1,n+1) {
		t[i] = i;
		usr[i].add();
	}
	sort(t+1, t+n+1, cmp());
	
	int cnt=1, pre=1, tmp=usr[t[1]].sum;
	printf("1 %05d %d", t[1], usr[t[1]].sum);
	rep(j,1,k+1) {
		if(usr[t[1]].p[j] >= 0)
			printf(" %d", usr[t[1]].p[j]);
		else if(usr[t[1]].p[j] == -2)
			printf(" 0");
		else
			printf(" -");
	}
	printf("\n");
	rep(i,2,n+1) {
		if(!usr[t[i]].flag)
			continue;
		++cnt;
		if(usr[t[i]].sum != tmp)
			pre = cnt;
		printf("%d %05d %d", pre, t[i], usr[t[i]].sum);
		rep(j,1,k+1) {
			if(usr[t[i]].p[j] >= 0)
				printf(" %d", usr[t[i]].p[j]);
			else if(usr[t[i]].p[j] == -2)
				printf(" 0");
			else
				printf(" -");
		}
		printf("\n");
		tmp = usr[t[i]].sum;
	}
	return 0;
}

