#include<bits/stdc++.h>
using namespace std;

int n;
struct Stu {
	string name, id;
	char gender;
	int grade;
} f, m, t;

int main() {
	cin >> n;
	f.grade = -5;
	m.grade = 105;
	f.name = m.name = "Absent";
	while(n--) {
		cin >> t.name >> t.gender >> t.id >> t.grade;
		if(t.gender == 'F' && t.grade > f.grade)
			f = t;
		else if(t.gender == 'M' && t.grade < m.grade)
			m = t;
	}
	
	bool flag = 1;
	cout << f.name;
	if(f.name != "Absent")
		cout << " " << f.id;
	else flag = 0;
	cout << "\n";
	
	cout << m.name;
	if(m.name != "Absent")
		cout << " " << m.id;
	else flag = 0;
	cout << "\n";
	
	if(flag)
		cout << f.grade - m.grade;
	else
		cout << "NA";
		
	return 0;
}
