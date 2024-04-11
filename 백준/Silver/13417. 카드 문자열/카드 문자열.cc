#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		deque<char> d;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			char c;
			cin >> c;
			if (d.empty())
				d.push_back(c);
			else
			{
				if (c > d.front())
					d.push_back(c);
				else
					d.push_front(c);
			}
		}
		for (auto c : d)
			cout << c;
		cout << '\n';
	}

	return 0;
}