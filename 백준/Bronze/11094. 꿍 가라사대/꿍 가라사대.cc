#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::vector<string> cmd;
		string s;
		while (cin >> s)
		{
			cmd.push_back(s);
			if (s.back() == '.')break;
		}
		if (cmd.size() <= 2)continue;
		if (cmd[0] == "Simon" && cmd[1] == "says")
		{
			for (int j = 2; j < cmd.size(); j++)
			{
				cout << ' ' << cmd[j];
			}
			cout << '\n';
		}
	}

	return 0;
}