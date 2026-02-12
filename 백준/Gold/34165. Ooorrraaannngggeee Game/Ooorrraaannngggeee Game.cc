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

int pix[256];
int dp[6];
int len[1000005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	string p = "orange";
	fill(pix, pix + 256, -1);
	for (int i = 0; i < p.size(); i++)
	{
		pix[p[i]] = i;
	}

	int st = s.find('o');
	if (st == string::npos)
	{
		cout << 0;
		return 0;
	}
	for (int i = st; i < s.size(); i++)
	{
		int ix = pix[s[i]];
		if (ix == -1) continue;
		if (ix == 0)
		{
			dp[ix]++;
		}
		else if(dp[ix-1] > 0)
		{
			dp[ix] = max(dp[ix], dp[ix - 1]) + 1;
		}
		len[i] = dp[ix];
	}

	int ans = dp[5];
	cout << ans << '\n';
	if (ans != 0)
	{
		int nxt = ans;
		string res;
		int targetix = 5;
		for (int i = s.size()-1; i >= 0; i--)
		{
			int curix = pix[s[i]];
			if (curix < 0) continue;
			if (len[i] == nxt)
			{
				if (res.empty() && targetix != curix) continue;
				if(!res.empty() && (targetix != curix && targetix-1 != curix)) continue;
				nxt--;
				res += s[i];
				targetix = curix;
			}
		}
		reverse(res.begin(), res.end());
		cout << res;
	}

	return 0;
}