#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;

int sushi[3005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, d, k, c;
	cin >> n >> d >> k >> c;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int kind = 0;
	for (int i = 0; i < k; i++)
	{
		v.push_back(v[i]);
		if (sushi[v[i]] == 0)
		{
			kind++;
		}
		sushi[v[i]]++;
	}

	int ans = 0;
	if (sushi[c] == 0)
		ans = max(ans, kind + 1);
	else
		ans = max(ans, kind);

	int st = 0;
	int ed = k-1;
	while (ed + 1 < v.size())
	{
		sushi[v[st]]--;
		if (sushi[v[st]] == 0)
		{
			kind--;
		}
		st++;
		ed++;
		if (sushi[v[ed]] == 0)
		{
			kind++;
		}
		sushi[v[ed]]++;
		if (sushi[c] == 0)
			ans = max(ans, kind + 1);
		else
			ans = max(ans, kind);
	}
	
	cout << ans;

	return 0;
}
