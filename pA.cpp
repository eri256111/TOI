#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

using ll = long long;
using pci = pair<char, int>;
using pii = pair<int, int>;
using piii = pair<int, pii>;
using vi = vector<int>;
using vii = vector<vi>;
using vl = vector<ll>;
using vll = vector<vl>;

#define FAST ios::sync_with_stdio(false);cin.tie(0);
#define Fr(i,s,e) for(auto i = s ; i < e ; i++)
#define endl '\n'
#define Ft first
#define Sd second
#define Pb push_back
#define All(v) v.begin(),v.end()
#define coutv(v) for(auto i : v){\
	cout << i << ' '; \
}cout << endl;

#define Htable gp_hash_table
#define _ <<' '<<

int main(){
	FAST;
	
	int n;
	ll OE = 0, OO = 0, EO = 0, EE = 0;
	cin >> n;
	while(n--){
		int a, b; cin >> a >> b;
		if(a % 2 == 0 and b % 2 == 0)
			EE++;
		else if(a % 2 == 0 and b % 2 == 1)
			EO++;
		else if(b % 2 == 0)
			OE++;
		else
			OO++;
	}
	auto C2 = [&](ll num){
		if(num == 0ll)return 0ll;
		else return num * (num - 1ll) / 2ll;
	};
	cout << C2(EE) + C2(EO) + C2(OE) + C2(OO) << endl;
	return 0;
}