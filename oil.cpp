#include <iostream>
#include <stack>

using namespace std;

int m,n,a,x,y;
bool b[102][102], v[102][102];
stack < pair <int,int> > s;

void f(int i, int j) {
	if (b[i][j] && !v[i][j]) {
		s.push(make_pair(i,j));
		v[i][j] = true;
	}
}

int main() {
	for (cin >> m >> n; m != 0; cin >> m >> n) {
		a = 0;
		for (int i = 0; i < n+1; i++) {
			b[0][i] = false;
			b[m+1][i] = false;
		}
		for (int i = 0; i < m+1; i++) {
			b[i][0];
			b[i][n+1];
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				char c;
				cin >> c;
				b[i][j] = c == '@';
				v[i][j] = false;
			}
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (b[i][j] && !v[i][j]) {
					s.push(make_pair(i,j));
					v[i][j] = true;
					a++;
					while (!s.empty()) {
						x = s.top().first;
						y = s.top().second;
						s.pop();
						f(x-1,y);
						f(x-1,y+1);
						f(x,y+1);
						f(x+1,y+1);
						f(x+1,y);
						f(x+1,y-1);
						f(x,y-1);
						f(x-1,y-1);
					}
				}
			}
		}
		cout << a << endl;
	}
}
