#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		multiset<int> s;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			char op;
			int val;
			cin >> op >> val;
			if (op == 'I')
			{
				s.insert(val);
			}
			else
			{
				if (!s.empty())
				{
					if (val == 1)
					{
						s.erase(prev(s.end()));
					}
					else
					{
						s.erase(s.begin());
					}
				}
			}
		}
		if (s.empty()) cout << "EMPTY";
		else cout << *s.rbegin() << ' ' << *s.begin();
		cout << '\n';
	}

	return 0;
}