#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string p = "PPAP";
	string s;
	cin >> s;
	string cur;
	for (char c : s)
	{
		cur += c;
		while (cur.size() >= 4 && cur.substr(cur.size() - 4) == p)
		{
			for (int i = 0; i < 3; i++)
			{
				cur.pop_back();
			}
		}
	}
	if (cur == "P") cout << "PPAP";
	else cout << "NP";

	return 0;
}