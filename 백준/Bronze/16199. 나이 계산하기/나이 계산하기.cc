#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;
template <typename T>
using vec = vector<T>;

bool chk(int n)
{
	if (n == 9 || n == 8)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int m, s, y;
	int by, bm, bd;
	int cy, cm, cd;
	cin >> by >> bm >> bd;
	cin >> cy >> cm >> cd;
	y = cy - by;
	s = cy - by + 1;
	m = cy - by;
	if (bm > cm)
		m -= 1;
	else if (bm == cm)
	{
		if (bd > cd)
			m -= 1;
	}

	cout << max(m, 0) << '\n' << s << '\n' << y;

	return 0;
}