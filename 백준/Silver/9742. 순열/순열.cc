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

	string s;
	int ix;
	while (cin >> s >> ix)
	{
		int maxix = 1;
		for (int i = 2; i <= s.size(); i++)
		{
			maxix *= i;
		}
		cout << s << ' ' << ix << " = ";
		if (ix > maxix)
		{
			cout << "No permutation";
		}
		else
		{
			for (int i = 0; i < ix - 1; i++)
			{
				next_permutation(s.begin(), s.end());
			}
			cout << s;
		}

		cout << '\n';
	}

	return 0;
}