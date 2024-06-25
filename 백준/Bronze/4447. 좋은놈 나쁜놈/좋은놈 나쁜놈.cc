#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

double f[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	cin.ignore();
	while (tc--)
	{
		int g = 0;
		int b = 0;
		string s;
		getline(cin, s);
		for (auto c : s)
		{
			if (c == 'g' || c == 'G')
				g++;
			if (c == 'b' || c == 'B')
				b++;
		}

		cout << s;
		if (g > b)
			cout << " is GOOD";
		else if (g < b)
			cout << " is A BADDY";
		else
			cout << " is NEUTRAL";
		cout << '\n';
	}
	

	return 0;
}