//map
#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false);cin.tie(0);
#define Fr(i,s,e) for(int i = s ; i < e ; i++)
#define endl '\n'
#define Ft first
#define Sd second
#define All(v) v.begin(),v.end();
#define _ <<' '<<

typedef long long ll;
typedef pair<int, int> pii;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int main(){
	int X, Y,
		sx, sy, ex, ey,
		B, T;
	cin >> X >> Y;
	cin >> sx >> sy >> ex >> ey;
	cin >> B >> T;
	vector< vector<int> > step(Y, vector<int>(X, -1));
	Fr(i,0,B){
		int bx, by; cin >> bx >> by;
		step[by][bx] = -2;
	}
	Fr(i,0,T){
		int tx, ty; cin >> tx >> ty;
		step[ty][tx] = -3;
	}
	struct Eri{int x, y, hp;};
	queue< Eri > qu{};
	qu.push({sx, sy, 3});
	step[sy][sx] = 0;
	auto valid = [&](int x, int y){
		return x >= 0 and y >= 0 and x < X and y < Y;
	};
	while(qu.size()){
		auto [x, y, hp] = qu.front(); qu.pop();
		Fr(i,0,4){
			int nx = x + dx[i], ny = y + dy[i];
			if(valid(nx, ny)){
				if(step[ny][nx] == -1){
					qu.push({nx, ny, hp});
					step[ny][nx] = step[y][x] + 1;
				} else if (step[ny][nx] == -3 and hp > 1){
					qu.push({nx, ny, hp - 1});
					step[ny][nx] = step[y][x] + 1;
				}
			}
		}
	}
	cout << step[ey][ex] << endl;
	return 0;
}