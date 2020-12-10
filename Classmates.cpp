#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false);cin.tie(0);
#define Fr(i,s,e) for(auto i = s ; i < e ; i++)
#define endl '\n'
#define Ft first
#define Sd second
#define All(v) v.begin(),v.end();
#define _ <<' '<<

typedef long long ll;
typedef pair<int, int> pii;

int N, M;
int cnt1 = 0, cnt2 = 0;
bool group;

struct Node{
	bool pass = false;
	vector<int> ch;
};
vector< Node > fri;

void dfs(int cur, int pre){
	fri[cur].pass = true;
	int sz = fri[cur].ch.size();
	Fr(i,0,sz){
		if(fri[cur].ch[i] != pre){
			if(fri[fri[cur].ch[i]].pass == true)group = true;
			if(fri[fri[cur].ch[i]].pass == false){
				dfs(fri[cur].ch[i], cur);
			}
		}
	}
}

int main(){
	cin >> N >> M;
	fri.resize(N);
	Fr(i,0,M){
		int a, b; cin >> a >> b;
		fri[a].ch.push_back(b);
		fri[b].ch.push_back(a);
	}
	Fr(i,0,N){
		if(fri[i].pass == false){
			group = false;
			dfs(i, -1);
			cnt1++;
			if(group)cnt2++;
		}
	}
	cout << cnt1 << ' ' << cnt2 << endl;
	return 0;
}