#include<bits/stdc++.h>
#define N 105
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n;
int pre[N], in[N], num;
stack<int> st;
int pos[N];
char cmd[10];

void order(int r, int lf, int rt, int dns) {
	if(lf >= rt) return ;
	int *i = find(in+lf, in+rt, pre[r]);
	int lenlf = i-in-lf, lenrt = rt-(i-in)-1;
	order(r+1, lf, i-in, dns-lenrt-1);
	order(r+1+lenlf, i-in+1, rt, dns-1);
	pos[dns] = pre[r];
	return ;
}

int main() {
	scanf("%d", &n);
	int p=0, q=0;
	rep(i,0,2*n) {
		scanf("%s", cmd);
		if(cmd[1] == 'u') {
			scanf("%d", &num);
			pre[p++] = num;
			st.push(num);
		}
		else {
			in[q++] = st.top();
			st.pop();
		}
	}
	
	order(0,0,n,n-1);
	rep(i,0,n) printf("%d%c", pos[i], (i==n-1 ? '\n' : ' '));
	return 0;
}

