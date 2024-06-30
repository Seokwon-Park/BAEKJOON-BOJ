#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	string s;
	char c = '\0';

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (c == '\0')
			c = s[0];
		else
		{
			if (c != s[0])
			{
				cout << 0;
				return 0;
			}
		}
	}

	cout << 1;

	return 0;
}
