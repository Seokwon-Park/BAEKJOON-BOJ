#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	
	for (int i = 1; i <= s.size(); i++)
	{
		int a = stoi(s.substr(0, i));
		int b = a;
		int cur = 0;
		bool isWrong = false;
		while (1)
		{
			string tmp = to_string(b);
			isWrong = false;
			for (int k = 0; k < tmp.size(); k++)
			{
				if (tmp[k] != s[cur+k])
				{
					isWrong = true;
					break;
				}
			}
			if (isWrong)
			{
				break;
			}
			cur += tmp.size();
			if (cur >= s.size()) break;
			b++;
		}
		if (!isWrong)
		{
			cout << a << ' ' << b;
			return 0;
		}
	}

	return 0;
}