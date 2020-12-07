#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define FAST ios::sync_with_stdio(false);cin.tie(0);
#define Fr(i,s,e) for(auto i = s ; i < e ; i++)
#define endl '\n'
#define Ft first
#define Sd second
#define All(v) v.begin(),v.end()
#define _ <<' '<<

typedef long long ll;
typedef pair<int, int> pii;

constexpr ll MOD = 1'080'494'663;

int main(){
	int n;
	cin >> n;
	auto Fast_Fib = [&](int x){
		struct matrix{
			ll ma[2][2];
		}ans, base; 
		auto mul = [&](matrix a, matrix b){
			matrix M;
			Fr(i,0,2)Fr(j,0,2){
				M.ma[i][j] = 0;
				Fr(k,0,2){
					M.ma[i][j] += a.ma[i][k] * b.ma[k][j];
					M.ma[i][j] %= MOD;
				}
			}
			return M;
		};
		base.ma[0][0] = base.ma[0][1] = base.ma[1][0] = 1;
		base.ma[1][1] = 0;
		ans.ma[0][0] = ans.ma[1][1] = 1;
		ans.ma[0][1] = ans.ma[1][0] = 0;
		while(x){
			if(x&1)
				ans = mul(ans, base);
			base = mul(base, base);
			x >>= 1 ;
		}
		return ans.ma[0][1];
	};
	int p1 = 0, p2 = 1, cur = 1;
	ll sum = 0;
	while(n >= 0){
		sum += Fast_Fib(cur + 1);
		cur = p1 + p2, p1 = p2, p2 = cur;
		n--;
	}
	cout << sum << endl;
}