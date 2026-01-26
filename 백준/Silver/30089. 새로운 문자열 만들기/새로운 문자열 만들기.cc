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
using hashmap = unordered_map<key, value>;


bool isPelin(string s)
{
	for (int j = 0; j < s.size() / 2; j++)
	{
		if (s[j] != s[s.size() - 1 - j])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		if (isPelin(s))
		{
			cout << s << '\n';
			continue;
		}
		string srev = s;
		reverse(srev.begin(), srev.end());
		for (int i = s.size()-1; i >= 0; i--)
		{
			string tmp = s + srev.substr(i);
			if (isPelin(tmp))
			{
				cout << tmp << '\n';
				break;
			}
		}
	}
	

	return 0;
}