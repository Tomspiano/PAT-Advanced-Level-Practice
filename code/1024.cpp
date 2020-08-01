#include<bits/stdc++.h>
#define N 105
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b-1); i>=(a); --i)

int num[2][N];
char tmp[N];
char c;
int k;
int step, id;

bool rever(int index, int len) {
	rep(i,0,len/2) {
		if(num[index][i] != num[index][len-1-i])
			return 0;
	}
	return 1;
}

int palindromic(int st, int len) {
	if(rever(id, len) || st==k) {
		step = st;
		return len;
	}
	
	int pre = id;
	id ^= 1;
	int carr = 0;
	rep(i,0,len) {
		num[id][i] = (num[pre][i] + num[pre][len-1-i] + carr)%10;
		carr = (num[pre][i] + num[pre][len-1-i] + carr)/10;
	}
	if(carr) {
		num[id][len++] = carr;
	}
	return palindromic(st+1, len);
}

int main() {
	scanf("%s%d", tmp, &k);
	int len = strlen(tmp);
	rep(i,0,len) 
		num[0][i] = tmp[len-1-i] - '0';
	
	id = 0;
	int j = palindromic(0, len);
	per(i,0,j) printf("%d", num[id][i]);
	printf("\n%d\n", step);
	return 0;
}
