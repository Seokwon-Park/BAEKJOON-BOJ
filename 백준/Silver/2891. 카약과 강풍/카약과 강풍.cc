#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int kayak[11];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, s, r;
	cin >> n >> s >> r;

	vector<int> v(s);
	fill(kayak, kayak + 11, 1);
	for (int i = 0; i < s; i++)
	{
		cin >> v[i];
		kayak[v[i]]--;
	}

	vector<int> v2(r);
	for (int i = 0; i < r; i++)
	{
		cin >> v2[i];
		kayak[v2[i]]++;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (kayak[i] > 1)
		{
			if (kayak[i - 1] < 1)
			{
				kayak[i - 1]++;
			}
			else if (kayak[i + 1] < 1)
			{
				kayak[i + 1]++;
			}
		}
	}
	cout << count(kayak + 1, kayak + n + 1,0);


	return 0;
}
