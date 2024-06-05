#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	int variety = 0;
	vector<int> fruits(10);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];

	}

	if (n == 1)
	{
		cout << 1;
		return 0;
	}

	int st = 0;
	int en = 1;
	if (fruits[v[st]] == 0)
		variety++;
	fruits[v[st]]++;
	if (fruits[v[en]] == 0)
		variety++;
	fruits[v[en]]++;
	int ans = variety;
	while (st < en)
	{
		if (variety <= 2)
		{
			if (en + 1 < n)
			{
				en++;
				if (fruits[v[en]] == 0)
					variety++;
				fruits[v[en]]++;
				if (variety <= 2)
					ans = max(en - st + 1, ans);
			}
			else
				break;
		}
		else
		{
			fruits[v[st]]--;
			if (fruits[v[st]] == 0)
				variety--;
			st++;
			if (variety <= 2)
				ans = max(en - st + 1, ans);
		}
	}

	cout << ans;



	return 0;
}