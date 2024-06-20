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

	while (1)
	{
		string s;
		getline(cin,s);
		if (s == "***")break;
		cout << string(s.rbegin(), s.rend()) << '\n';

	}

	return 0;
}
