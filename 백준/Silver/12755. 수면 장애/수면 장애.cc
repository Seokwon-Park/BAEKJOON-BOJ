#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int cur = 0;
	int curlen = 1;
	int nxt = 10;
	int len = 0;
	while (len < n)
	{
		cur++;
		if (cur >= nxt)
		{
			nxt *= 10;
			curlen++;
		}
		len += curlen;
	}

	len -= n;
	string tmp = to_string(cur);
	cout << tmp[tmp.size() - len-1];

	return 0;
}