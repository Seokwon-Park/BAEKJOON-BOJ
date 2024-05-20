#include <bits/stdc++.h>

using namespace std;

#define INF LLONG_MAX

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<int> words;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		int res = 0;
		for (auto c : s)
		{
			int ch = c - 'a';
			res |= 1 << ch;
		}
		words.push_back(res);
	}

	if (k < 5)
	{
		cout << 0;
		return 0;
	}

	vector<bool> comb(26, false);
	fill(comb.end() - k, comb.end(), k);

	// anta, tica = > a,c,i,n,t;
	
	int ans = 0;
	do
	{
		if (!comb[0] || !comb[2] || !comb['i' - 'a'] || !comb['n' - 'a'] || !comb['t' - 'a']) continue;
		int teach = 0;
		for (int i = 0; i < 26; i++)
		{
			if (comb[i])
			{
				teach |= 1 << i;
			}
		}

		int cnt = 0;
		for (int i = 0; i < words.size(); i++)
		{
			if ((words[i] | teach) == teach)
			{
				cnt++;
			}
		}
		ans = max(cnt, ans);

	} while (next_permutation(comb.begin(), comb.end()));
	cout << ans;

	return 0;
}