#include<cstdio>
using namespace std;

const int up=6, down=4, stay=5;
int sum=0;
int n, pre, pos;

int main() {
	scanf("%d", &n);
	pre = 0;
	while(n--) {
		scanf("%d", &pos);
		if(pos > pre) {
			sum += up*(pos - pre) + stay;
		}
		else if(pos < pre) {
			sum += down*(pre - pos) + stay;
		}
		else {
			sum += stay;
		}
		pre = pos;
	}
	printf("%d", sum);
	return 0;
}
