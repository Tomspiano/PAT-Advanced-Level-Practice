//#include<iostream>
//#include<iomanip>
#include<cstdio>
using namespace std;

int a, b, rst;
int i, len, cnt;

int main() {
//	cin >> a >> b;
	scanf("%d%d", &a, &b);
	rst = a + b;
	if(rst < 0) {
//		cout << '-';
		printf("-");
		rst = -rst;
	}
	
//	cout << setfill('0'); 
//	if(rst >= 1000000)
//		cout << rst/1000000 << ',' << setw(3) << rst%1000000/1000 << ',' << setw(3) << rst%1000;
//	else if(rst >= 1000)
//		cout << rst/1000 << ',' << setw(3) << rst%1000;
//	else
//		cout << rst;
	if(rst >= 1000000)
		printf("%d,%03d,%03d", rst/1000000, rst%1000000/1000, rst%1000);
	else if(rst >= 1000)
		printf("%d,%03d", rst/1000, rst%1000);
	else
		printf("%d", rst);
	return 0;
}
