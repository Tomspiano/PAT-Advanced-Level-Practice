#include<bits/stdc++.h>
//#define N 10005
using namespace std;
//#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n, num;
map<int, vector<int> > mp;  // id, num
map<int, vector<int> >::iterator j;
//int a[N];

int main() {
	scanf("%d", &n);
	int sum, tmp;
	while(n--) {
		scanf("%d", &num);
		tmp = num;
		sum = 0;
		while(num) {
			sum += num%10;
			num /= 10;
		}
		mp[sum].push_back(tmp);
	}
	
//	sum = 0;
//	for(j=mp.begin(); j!=mp.end(); ++j) {
//printf("%d ", j->first);
//		if(j->second.size() > 1)
//			a[sum++] = j->first;
//	}
//	printf("%d\n", sum);
//	rep(i,0,sum) printf("%d%c", a[i], (i==sum-1 ? '\n' : ' '));
	printf("%d\n", mp.size());
	j = mp.begin();
	while(1) {
		printf("%d", j->first);
		++j;
		if(j == mp.end()) {
			printf("\n");
			break;
		}
		else
			printf(" ");
	}
	return 0;
}

