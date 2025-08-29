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

	string s;
	cin >> s;

	vector<bool> isUsed(26);

	for (auto c : s)
	{
		isUsed[c - 'a'] = true;
	}

	if (s.size() < 26)
	{
		for (auto i = 0; i < 26; i++)
		{
			if (!isUsed[i])
			{
				cout << s + (char)('a' + i);
				return 0;
			}
		}
	}
	else
	{
		char last = s.back() - 1;
		while (!s.empty())
		{
			last = s.back();
			isUsed[last - 'a'] = false;
			s.pop_back();
			for (char i = last + 1; i <= 'z'; i++)
			{
				if (isUsed[i - 'a'] == false)
				{
					s.push_back(i);
					cout << s;
					return 0;
				}
			}
		}
		if (s.empty())
		{
			cout << -1;
			return 0;
		}
		
		cout << s + last;
	}

	return 0;
}