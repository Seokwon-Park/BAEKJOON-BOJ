#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	string pat = "driip";

	if (s.size() < pat.size())
	{
		cout << "not cute";
		return 0;
	}
	else
	{
		for (int i = 0; i < pat.size(); i++)
		{
			if (s[s.size() - 1 - i] != pat[pat.size() - 1 - i])
			{
				cout << "not cute";
				return 0;
			}
		}
	}
	cout << "cute";


	return 0;
}