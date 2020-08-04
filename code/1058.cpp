#include<bits/stdc++.h>
using namespace std;

int g1,g2, s1,s2, k1,k2;
int g, s, k;

int main() {
	scanf("%d.%d.%d %d.%d.%d", &g1,&s1,&k1, &g2,&s2,&k2);
	int carr = 0;
	k = (k1 + k2)%29;
	carr = (k1 + k2)/29;
	s = (s1 + s2 + carr)%17;
	carr = (s1 + s2 + carr)/17;
	g = g1 + g2 + carr;
	printf("%d.%d.%d", g, s, k);
	return 0;
}
