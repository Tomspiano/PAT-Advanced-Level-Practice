#include<iostream>
#include<map>
#include<stack>
#define N 105
using namespace std;

char num;
int sum;
map<int, string> mp;
stack<string> st;

int main() {
	mp[0] = "zero";
	mp[1] = "one";
	mp[2] = "two";
	mp[3] = "three";
	mp[4] = "four";
	mp[5] = "five";
	mp[6] = "six";
	mp[7] = "seven";
	mp[8] = "eight";
	mp[9] = "nine";
	
	sum = 0;
	while(cin >> num)
		sum += num - '0';
	while(1) {
		st.push(mp[sum%10]);
		sum /= 10;
		if(!sum)
			break;
	}
	
	while(1) {
		cout << st.top();
		st.pop();
		if(st.empty())
			break;
		cout << " ";
	}
	return 0;
}
