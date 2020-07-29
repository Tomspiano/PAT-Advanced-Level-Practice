#include<cstdio>
using namespace std;

int k;
int num;
int sum, t;
int first, last, t1, t2;

int main() {
	sum = -1;
	t = 0;
	bool pos = 0;
	scanf("%d", &k);
	for(int i=0; i<k; ++i) {
		scanf("%d", &num);
		if(num >= 0) pos = 1;
		if(!t) t1 = t2 = num;
		if(!i) {
			first = last = num;
			if(num > 0)
				sum = t = num;
		}
		else {
			t += num;
			if(t > sum) {
				first = t1;
				last = t2 = num;
				sum = t;
			}
			else if(t < 0) {
				t = 0;
			}
		}
//printf("%d %d %d %d %d %d\n", sum, t, first, last, t1, t2);
	}	
	if(!pos) last = t2;
	printf("%d %d %d", (sum>0 ? sum : 0), first, last);
	return 0;
}
