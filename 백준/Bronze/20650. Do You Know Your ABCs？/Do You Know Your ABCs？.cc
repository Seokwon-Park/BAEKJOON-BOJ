#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v(7);
	for (auto& i : v)
		cin >> i;

	int a, b, c;
	sort(v.begin(), v.end());
	if (v[0] + v[1] != v[2])
	{
		a = v[0];
		b = v[1];
		c = v[2];
	}
	else
	{
		a = v[0];
		b = v[1];
		c = v[3];
	}

	cout << a << ' ' << b << ' ' << c;


	return 0;
}
