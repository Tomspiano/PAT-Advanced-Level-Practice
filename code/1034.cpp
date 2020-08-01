#include<bits/stdc++.h>
#define N 2005
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)

int n, k;
string a, b;
int t;
map<string, set<string> > edge;
set<string>::iterator f1;
map<string, int> sum, id;
map<string, int>::iterator f2;
bool vis[N];
queue<string> q;
string str;
struct Node {
	string head;
	int cnt;
} node[N];
struct cmp {
	bool operator() (const int a, const int b) const {
		return node[a].head < node[b].head;
	}
};
int table[N];


int main() {
	memset(vis, 0, sizeof(vis));
	
	cin >> n >> k;
	int i = 0;
	while(n--) {
		cin >> a >> b >> t;
		edge[a].insert(b);
		edge[b].insert(a);
		
		f2 = sum.find(a);
		if(f2 == sum.end()) {
			sum[a] = t;
			id[a] = i++;
		}
		else {
			sum[a] += t;
		}
		f2 = sum.find(b);
		if(f2 == sum.end()) {
			sum[b] = t;
			id[b] = i++;
		}
		else {
			sum[b] += t;
		}
	}
	
	int index = 0;
	int cnt, mt, tmp;
	string head;
	for(f2=sum.begin(); f2!=sum.end(); ++f2) {
		if(!vis[id[f2->first]]) {
			cnt = tmp = 0;
			head = f2->first;
			mt = sum[head];
			vis[id[f2->first]] = 1;
			q.push(f2->first);
			while(!q.empty()) {
				str = q.front();
				++cnt;
				tmp += sum[str];
//cout << str << " ";
				for(f1=edge[str].begin(); f1!=edge[str].end(); ++f1) {
					if(vis[id[*f1]]) continue;
					if(sum[*f1]>mt) {
						head = *f1;
						mt = sum[head];
					}
					vis[id[*f1]] = 1;
					q.push(*f1);
				}
				q.pop();
			}
//cout << endl;
			if(tmp/2>k && cnt>2) {
				table[index] = index;
				node[index].head = head;
				node[index++].cnt = cnt;
			}
		}
	}
	
	cout << index << "\n";
	sort(table, table+index, cmp());
	rep(i,0,index) {
		cout << node[table[i]].head << " " << node[table[i]].cnt << "\n";
	}
	return 0;
}
