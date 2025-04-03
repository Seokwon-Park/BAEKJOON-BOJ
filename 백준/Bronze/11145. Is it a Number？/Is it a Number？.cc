#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;


string CheckInvalid(string s)
{
	bool isSpaceStart = true;
	string result = "";
	int ix = 0;
	while (ix < s.size() && s[ix] == ' ')ix++;
	for (int i = ix; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			for (int j = i + 1; j < s.size(); j++)
			{
				if (s[j] != ' ')return "-1";
			}
		}
		else
		{
			if (!isdigit(s[i]))
			{
				return "-1";
			}
			else
			{
				result += s[i];
			}
		}
	}
	if (result.empty()) return "-1";
	ix = 0;
	while (result[ix] == '0') ix++;
	if (ix == result.size())
	{
		return "0";
	}
	else
	{
		return result.substr(ix);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string s;
		getline(cin, s);
		string result = CheckInvalid(s);
		if (result == "-1")
		{
			cout << "invalid input";
		}
		else
		{
			cout << result;
		}
		cout << '\n';
	}



	return 0;
}