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
	
	string s, p;
	cin >> s >> p;

	int cursor = 0;
	int ans = 0;
	while (cursor < p.size())
	{
		string tmp = "";
		for (int i = 0; i < s.size() && cursor + i < p.size(); i++)
		{
			tmp += p[cursor + i];
			if (s.find(tmp) == string::npos)
			{
				tmp.pop_back();
				break;
			}
		}
		cursor += tmp.size();
		ans++;
	}

	cout << ans;

	return 0;
}