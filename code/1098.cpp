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

bool heapSort() {
	printf("Heap Sort\n");
	
	int i = n - 1;
	while(i && s[i] >= s[0]) {
		--i;
	}
	swap(s[0], s[i]);
	int j=0, k=1;
	while(k < i) {
		if(k+1<i && s[k]<s[k+1]) ++k;
		if(s[j] >= s[k]) break;
		swap(s[j], s[k]);
		j=k; k=2*j+1;
	}
	rep(i,0,n) printf("%d%c", s[i], (i==n-1 ? '\n' : ' '));
	return 1;
}

int main() {
	scanf("%d", &n);
	rep(i,0,n) scanf("%d", &a[i]);
	rep(i,0,n) scanf("%d", &s[i]);
	if(!insertionSort())
		heapSort();
	return 0;
}

