#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	cin >> s;
	bool isPull = false;
	bool isPulled = false;
	int cur = 0; // A 구역에 있음
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'P')
		{
			isPull = !isPull;
			if (cur == 1)
			{
				isPulled = true;
			}

		}
		else if (s[i] == 'W')
		{
			if (cur == 0)
				cur++;
			else if (cur == 1)
			{
				if (isPulled)
					cout << 6;
				else if (isPull)
					cout << 1;
				else
					cout << 5;
				return 0;
			}
		}
	}
	cout << 0;


	return 0;
}