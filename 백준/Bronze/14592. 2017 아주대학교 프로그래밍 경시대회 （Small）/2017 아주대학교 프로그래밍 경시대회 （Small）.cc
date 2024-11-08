
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
	vector<vector<int>> v(n);
	vector<vector<int>> srt(n);
	for (int i = 0; i < n; i++)
	{
		int s, c, l;
		cin >> s >> c >> l;
		v[i] = { s,c,l };
	}
	srt = v;

	sort(srt.begin(), srt.end(), [](auto a, auto b)
		{
			if (a[0] == b[0])
			{
				if (a[1] == b[1])
				{
					return a[2] < b[2];
				}
				return a[1] < b[1];
			}
			return a[0] > b[0];
		});

	for (int i = 0; i < n; i++)
	{
		if (srt[0] == v[i])
		{
			cout << i + 1;
			break;
		}
	}

	return 0;
}