#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	string svt = bitset<5>(17).to_string();

	string res(s.size() + svt.size(), '0');

	for (int i = 0; i < s.size(); i++)
	{
		int carry = 0;
		for (int j = 0; j < svt.size(); j++)
		{
			int a = s[s.size() - i - 1] - '0';
			int b = svt[svt.size() - j - 1] - '0';
			int tmp = (res[res.size() - (i + j) - 1]-'0' + a * b + carry);
			carry = tmp / 2;
			res[res.size() - 1 - (i + j)] = tmp%2 + '0';
			//cout << res << "\n\n";
		}
		res[res.size() - 1 - (i + svt.size())] = carry + '0';
	}

	int ix = 0;
	while (res[ix] == '0')
	{
		ix++;
	}

	cout << res.substr(ix);

	return 0;
}