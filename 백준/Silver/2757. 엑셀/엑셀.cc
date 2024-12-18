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

	string s;
	while (cin >> s)
	{

		string tmp = "";
		int st = 1;
		while (isdigit(s[st]))
		{
			tmp += s[st];
			st++;
		}
		int row = stoi(tmp);

		st++;
		tmp = "";
		while (st < s.size())
		{
			tmp += s[st];
			st++;
		}
		int col = stoi(tmp);

		if (row == 0 && col == 0)break;
		string res;

		int k = 1;
		while (col >= k)
		{
			col--;
			res.push_back('A' + col % 26);
			col /= 26;
		}
		reverse(res.begin(), res.end());
		cout << res<<row << '\n';
	}


	

	return 0;
}
