#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;
template <typename T>
using vec = vector<T>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vec<vec<char>> b((n * 2 - 1), vec<char>(n, ' '));
	for (int x = 0; x < n; x++)
	{
		for (int y = x; y < (n * 2 - 1) - x; y++)
		{
			b[y][x] = '*';
		}
	}

	for (int y = 0; y < (n * 2 - 1) ; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if(b[y][x] == '*')
				cout << b[y][x];
		}
		cout << '\n';
	}

	return 0;
}