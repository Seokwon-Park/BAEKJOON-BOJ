#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

char m[256];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	
	vector<string> line(4);
	line[0] = "`1234567890-=";
	line[1] = "QWERTYUIOP[]\\";
	line[2] = "ASDFGHJKL;'";
	line[3] = "ZXCVBNM,./";

	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < line[i].size(); j++)
		{
			m[line[i][j]] = line[i][j-1];
		}
	}

	string s;
	while (getline(cin, s))
	{
		string ans = "";
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ')
				ans.push_back(' ');
			else
				ans.push_back(m[s[i]]);
		}

		cout << ans << '\n';
	}

	return 0;
}
