#include<bits/stdc++.h>
#define N 15
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n;
struct Stu {
	char name[N], id[N];
	int grade;
	
	Stu(int g=0) {
		grade = g;
	}
	bool operator< (const Stu &t) const {
		return grade > t.grade;
	}
} t;
vector<Stu> vec;
int g1, g2;

int main() {
	scanf("%d", &n);
	getchar();
	rep(i,0,n) {
		scanf("%s%s%d", t.name, t.id, &t.grade);
		vec.push_back(t);
	}
	sort(vec.begin(), vec.end());
//printf("%s\n%s\n%s\n%s\n", vec[0].name, vec[1].name, vec[2].name, vec[3].name);
	scanf("%d%d", &g1, &g2);
	vector<Stu>::iterator j = lower_bound(vec.begin(), vec.end(), Stu(g2));
	
	bool flag = 0;
	while(j!=vec.end() && j->grade>=g1) {
		flag = 1;
		printf("%s %s\n", j->name, j->id);
		++j;
	} 
	if(!flag) printf("NONE\n");
	return 0;
}

