#include<bits/stdc++.h>
#define N 105
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n;
int a[N], s[N];

bool insertionSort() {
	int i = 1;
	while(i < n) {
		if(s[i] < s[i-1])
			break;
		++i;
	}
	int j = i;
	while(j < n) {
		if(s[j] != a[j])
			return 0;
		++j;
	}
	
	printf("Insertion Sort\n");
	j = 0;
	while(j<i && s[j]<s[i]) {
		if(j) printf(" ");
		printf("%d", s[j]);
		++j;
	}
	if(j) printf(" ");
	printf("%d", s[i]);
	while(j < i) {
		printf(" %d", s[j]);
		++j;
	}
	while(++i < n) {
		printf(" %d", a[i]);
	}
	return 1;
}

bool mergeSort() {
	printf("Merge Sort\n");
	
	bool flag;
	int j;
	for(int len=2; len<=n; len*=2) {
		for(j=0; j<n; ++j) {
			if(a[j] != s[j]) {
				flag = 0;
				break;
			}
		}
		if(j==n) flag=1;
		
		rep(i,0,n/len)
			sort(a+i*len, a+(i+1)*len);
		sort(a+n/len*len, a+n);
		if(flag) break;
	}
	rep(i,0,n) printf("%d%c", a[i], (i==n-1 ? '\n' : ' '));
	return 1;
}

int main() {
	scanf("%d", &n);
	rep(i,0,n) scanf("%d", &a[i]);
	rep(i,0,n) scanf("%d", &s[i]);
	if(!insertionSort())
		mergeSort();
	return 0;
}

