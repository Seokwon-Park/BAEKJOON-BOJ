#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int times[55];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int cur = 0;
	int n;
	while (1)
	{
		cin >> n;
		if (n == 0) break;
		cin.ignore();
		int cur = 0;
		while (n--)
		{
			string s;
			getline(cin, s);
			if (s.size() < cur) continue;
			while (cur < s.size() && s[cur] != ' ')
			{
				cur++;
			}
		}
		cout << cur + 1 << '\n';
	}

	return 0;
}