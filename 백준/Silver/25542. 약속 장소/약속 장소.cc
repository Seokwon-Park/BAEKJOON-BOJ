#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

bool check(string s, vector<string>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		int diff = 0;
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] != v[i][j])
				diff++;
		}
		if (diff > 1)
			return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, l;
	cin >> n >> l;

	vector<string> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < l; j++)
		{
			for (char k = 'A'; k <= 'Z'; k++)
			{
				string s = v[i];
				s[j] = k;

				if (check(s, v))
				{
					cout << s;
					return 0;
				}
			}
		}
	}
	cout << "CALL FRIEND";

	return 0;
}