#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'009;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	cin.ignore();
	while (tc--)
	{
		string msg;
		getline(cin, msg);
		string rule;
		getline(cin, rule);

		for (auto& c : msg)
		{
			if (c == ' ')continue;
			int ix = c - 'A';
			c = rule[ix];
		}
		cout << msg << '\n';
	}
	
	return 0;
}

