#include<cstdio>
#define N 3
using namespace std;

char table[N];
const char map[N] = {'W', 'T', 'L'};

int main() {
	double bet, maxb;
	double profit = 0.65;
	for(int i=0; i<N; ++i) {
		maxb = 0;
		for(int j=0; j<N; ++j) {
			scanf("%lf", &bet);
			if(bet>maxb) {
				maxb=bet;
				table[i] = map[j];
			}
		}
		profit *= maxb;
	}
	profit = (profit - 1)*2;
	printf("%c %c %c %.2f", table[0], table[1], table[2], profit);
	return 0;
}
