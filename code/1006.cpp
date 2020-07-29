#include<cstdio>
using namespace std;

int m;
struct Time {
	int h, m, sec;
};
struct Staff {
	char id[20];
	Time sign_in, sign_out;
} unlocked, locked, staff;

Staff cmp1(Staff a, Staff b) {
	if(a.sign_in.h != b.sign_in.h) {
		if(a.sign_in.h > b.sign_in.h)
			return b;
		return a;
	}
		
	else if(a.sign_in.m != b.sign_in.m) {
		if(a.sign_in.m > b.sign_in.m)
			return b;
		return a;
	}
		
	if(a.sign_in.sec > b.sign_in.sec)
		return b;
	return a;
}
Staff cmp2(Staff a, Staff b) {
	if(a.sign_out.h != b.sign_out.h) {
		if(a.sign_out.h > b.sign_out.h)
			return a;
		return b;
	}
		
	else if(a.sign_out.m != b.sign_out.m) {
		if(a.sign_out.m > b.sign_out.m)
			return a;
		return b;
	}
		
	if(a.sign_out.sec > b.sign_out.sec)
		return a;
	return b;
}

int main() {
	scanf("%d", &m);
	scanf("%s %d:%d:%d %d:%d:%d", unlocked.id,
				&unlocked.sign_in.h, &unlocked.sign_in.m, &unlocked.sign_in.sec,
				&unlocked.sign_out.h, &unlocked.sign_out.m, &unlocked.sign_out.sec);
	locked = unlocked;
	
	while(--m) {
		scanf("%s %d:%d:%d %d:%d:%d", staff.id,
				&staff.sign_in.h, &staff.sign_in.m, &staff.sign_in.sec,
				&staff.sign_out.h, &staff.sign_out.m, &staff.sign_out.sec);
		
		unlocked = cmp1(unlocked, staff);
		locked = cmp2(locked, staff);
	};
	
	printf("%s %s", unlocked.id, locked.id);
	return 0;
}
