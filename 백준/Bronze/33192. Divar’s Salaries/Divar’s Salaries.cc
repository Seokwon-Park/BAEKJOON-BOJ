#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int res = 0;
		int x, k, h;
		cin >> x >> k >> h;
		res += 2 * x * h;
		k -= h;
		if (k > 140)
		{
			res += x * 140 + x/2*3 * (k-140);
			
		}
		else
		{
			res += x * k;
		}
		string tmp = to_string(res);
		int offset = 3 - (tmp.size() % 3);
		string ans;
		for (int i = 0; i < tmp.size(); i++)
		{
			ans.push_back(tmp[i]);
			offset++;
			if (offset % 3 == 0 && i != tmp.size()-1)
			{
				ans.push_back(',');
			}
		}
		cout << ans << '\n';


	}
	
	return 0;
}