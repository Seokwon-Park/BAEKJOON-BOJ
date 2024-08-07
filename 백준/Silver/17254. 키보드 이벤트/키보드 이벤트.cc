#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, char>> v;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		char c;
		cin >> a >> b >> c;
		v.push_back(tie(a, b, c));
	}

	sort(v.begin(), v.end(), [](auto a, auto b) 
		{
			int aa, ab, ac;
			int ba, bb, bc;
			tie(aa, ab, ac) = a;
			tie(ba, bb, bc) = b;
			if (ab == bb)
			{
				return aa < ba;
			}
			return ab < bb;

		});

	for (int i = 0; i < m; i++)
	{
		int a, b;
		char c;
		tie(a, b, c) = v[i];
		cout << c;
	}

	return 0;
}