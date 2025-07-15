#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;

	string prev;
	cin >> prev;
	int ans = prev.size();
	for (int i = 0; i < n-1; i++)
	{
		ans++; // newline
		string nxt;
		cin >> nxt;
		if (prev == nxt)
		{
			ans++; // copy
		}
		else
		{
			string tmp = nxt;
			if (nxt.size() < prev.size())
			{
				 tmp += string(prev.size() - nxt.size(), ' ');
			}
			bool isprefix = true;
			for (int j = 0; j < prev.size(); j++)
			{
				if (tmp[j] != prev[j])
				{
					int caseA = 1 + prev.size() - j + nxt.size() - j; // copy + delete
					int caseB = nxt.size();
					ans += min(caseA, caseB);
					isprefix = false;
					break;
				}
			}
			if (isprefix)
			{
				ans += 1 + nxt.size() - prev.size(); // copy + delete
			}
			prev = nxt;
		}
	}
	cout << ans;

	return 0;
}