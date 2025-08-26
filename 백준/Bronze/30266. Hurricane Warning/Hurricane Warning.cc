#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int i = 1; i <=tc; i++)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		int res = 0;
		for (int j = 0; j < n; j++)
		{
			string str;
			cin >> str;
			bool chk = false;
			for (int k = 0; k < str.size(); k++)
			{
				if (s.find(str[k]) != string::npos)
				{
					chk = true;
					break;
				}
			}
			res += chk;
		}
		cout << "Data Set " << i << ":\n";
		cout << res << "\n\n";
	}

	return 0;
}