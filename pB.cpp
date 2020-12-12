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

	int N, M;
	bool Yes = true;
	cin >> N >> M;
	vll v(N,vl(M));
	Fr(i,0,N){
		ll sum = 0;
		Fr(j,0,M){
			cin >> v[i][j];
			sum += v[i][j];
		}
		if(sum != 0)Yes = false;
	}
	if(Yes){
		Fr(i,0,M){
			ll sum = 0;
			Fr(j,0,N){
				sum += v[j][i];
			}
			if(sum != 0){
				Yes = false;
				break;
			}
		}
	}
	cout << (Yes ? "Yes" : "No") << endl;
	return 0;
}