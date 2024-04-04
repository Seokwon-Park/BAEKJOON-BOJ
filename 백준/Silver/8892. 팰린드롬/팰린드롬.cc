#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool isPelin(string s)
{
	for (int i = 0; i < s.size() / 2; i++)
	{
		if (s[i] != s[s.size() - 1 - i])
			return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		vector<string> v(n);
		for (auto& i : v)
			cin >> i;
		if (n == 1)
		{
			cout << 0 << '\n';
			continue;
		}

		vector<int> a(n, 0);
		fill(a.end() - 2, a.end(), 1);
		string ans = "0";
		do
		{
			string tmp = "";
			string tmp2 = "";
			for (int i = 0; i < n; i++)
			{
				if (a[i] == 1)
				{
					tmp += v[i];
					tmp2 = v[i] + tmp2;
				}
			}
			//cout << tmp << ' ' << tmp2 << '\n';
			if (isPelin(tmp))
			{
				ans = tmp;
				break;
			}
			else if (isPelin(tmp2))
			{
				ans = tmp2;
				break;
			}
		} while (next_permutation(a.begin(), a.end()));

		cout << ans << '\n';
	}


	return 0;
}