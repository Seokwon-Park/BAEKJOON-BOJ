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


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	vector<int> sinfo(26);
	for (auto c : s)
	{
		sinfo[c - 'a']++;
	}
	int n;
	cin >> n;
	while (n--)
	{
		string p;
		cin >> p;
		if (p.size() < s.size())
		{
			cout << "NO";
		}
		else
		{
			bool find = false;
			string cmp = p.substr(0, s.size());
			vector<int> pinfo(26);
			for (auto c : cmp)
			{
				pinfo[c - 'a']++;
			}
			int st = 0;
			int en = s.size() - 1;
			while (en < p.size())
			{
				int gap = 0;
				for (int i = 0; i < 26; i++)
				{
					gap += max(0, sinfo[i] - pinfo[i]);
				}

				if (p.size() == s.size()) // 길이가 같은 경우는 1개가 달라야 가능
				{
					if (gap == 1)
					{
						find = true;
						break;
					}
				}
				else // p가 더 긴경우는 0개여도 되고 1개여도 되고
				{
					if (gap <= 1)
					{
						find = true;
						break;
					}
				}

				pinfo[p[st] - 'a']--;
				st++;
				en++;
				if (en >= p.size()) break;
				pinfo[p[en] - 'a']++;
			}
			cout << (find ? "YES" : "NO");
		}
		cout << '\n';
	}

	return 0;
}