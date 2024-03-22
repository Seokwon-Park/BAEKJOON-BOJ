#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> s(n), b(m);
		for (int& i : s)
			cin >> i;
		for (int& i : b)
			cin >> i;
		sort(s.begin(), s.end());
		sort(b.begin(), b.end());
		int si = 0;
		int bi = 0;
		while (si < s.size() && bi < b.size())
		{
			if (s[si] < b[bi])
			{
				si++;
			}
			else if (s[si] == b[bi])
			{
				bi++;
			}
			else
			{
				bi++;
			}
		}
		if (si == s.size() && bi == b.size())
		{
			cout << "C\n";
		}
		else if (si == s.size())
		{
			cout << "B\n";
		}
		else
		{
			cout << "S\n";
		}

	}

	return 0;
}