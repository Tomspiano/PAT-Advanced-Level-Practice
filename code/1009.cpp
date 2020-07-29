#include<cstdio>
#include<map>
#include<cmath>
#define N 15
#define EPS 1e-3
using namespace std;

int k1, k2;
struct Poly {
	int exponent;
	double coefficient;
} p1[N], p2[N], t;
map<int, double, greater<int> > ans;
map<int, double, greater<int> >::iterator iter;

int main() {
	scanf("%d", &k1);
	for(int i=0; i<k1; ++i) {
		scanf("%d %lf", &p1[i].exponent, &p1[i].coefficient);
	}
	scanf("%d", &k2);
	for(int i=0; i<k2; ++i) {
		scanf("%d %lf", &p2[i].exponent, &p2[i].coefficient);
	}
	
	for(int i=0; i<k1; ++i)
		for(int j=0; j<k2; ++j) {
			t.exponent = p1[i].exponent + p2[j].exponent;
			t.coefficient = p1[i].coefficient * p2[j].coefficient;
			if(ans.find(t.exponent) != ans.end()) {
				ans[t.exponent] += t.coefficient;
			}
			else {
				ans[t.exponent] = t.coefficient;
			}
			if(fabs(ans[t.exponent]) < EPS)
				ans.erase(t.exponent);
		}
	
	printf("%d", ans.size());
	for(iter=ans.begin(); iter!=ans.end(); ++iter) {
		printf(" %d %.1f", iter->first, iter->second);
	}
	return 0;
}
