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

	double c;
	cin >> c;
	int n;
	cin >> n;

	int freeze = min(2, (int)floor(c / 0.99));
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int en = 0;

	int result = 0;
	for (int st = 0; st < n; st++)
	{
		if (st > 0)
		{
			if (v[st - 1] == 0)
			{
				freeze++;
			}
		}
		while (en < n)
		{
			if (v[en] == 0)
			{
				if (freeze > 0)
				{
					freeze--;
				}
				else
				{
					result = max(result, en - st);
					break;
				}
			}
			en++;
		}
		if (en == n)
		{
			result = max(result, en - st);
			break;
		}
	}

	cout << result << '\n' << *max_element(v.begin(), v.end());

	return 0;
}