#include<iostream>
#define N 25
using namespace std;

int i, j, k1, k2, t;
struct term {
	int e;
	double c;
} a[N], b[N], rst[N];

int main() {
	scanf("%d", &k1);
	for(i=0; i<k1; i++)
		scanf("%d%lf", &a[i].e, &a[i].c);
	scanf("%d", &k2);
	for(i=0; i<k2; i++)
		scanf("%d%lf", &b[i].e, &b[i].c);
	i = j = t = 0;
	while(i<k1 && j<k2) {
		if(a[i].e > b[j].e)
			rst[t++] = a[i++];
		else if(a[i].e < b[j].e)
			rst[t++] = b[j++];
		else {
			rst[t].c = a[i].c + b[j].c;
			rst[t].e = a[i].e;
			i++; j++;
			if(rst[t].c) t++;
		}
	}
	while(i<k1) rst[t++] = a[i++];
	while(j<k2) rst[t++] = b[j++];
	printf("%d", t);
	for(i=0; i<t; i++)
		printf(" %d %.1f", rst[i].e, rst[i].c);
	return 0;
}
