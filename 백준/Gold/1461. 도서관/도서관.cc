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

	int n, m;
	cin >> n >> m;
	vector<int> neg;
	vector<int> pos;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		if (k < 0)
			neg.push_back(k);
		else
			pos.push_back(k);
	}
	sort(neg.begin(), neg.end());
	sort(pos.begin(), pos.end(), greater<int>());
	int ans = 0;
	if (neg.empty())
	{
		ans += pos[0];
		for (int i = 1; i < pos.size() / m; i++)
		{
			ans += pos[i * m] * 2;
		}
		if (pos.size() % m != 0 && pos.size() / m * m !=0)
		{
			ans += pos[pos.size() / m * m] * 2;
		}
	}
	else if (pos.empty())
	{
		ans += abs(neg[0]);
		for (int i = 1; i < neg.size() / m; i++)
		{
			ans += abs(neg[i * m]) * 2;
		}
		if (neg.size() % m != 0 && neg.size() / m * m!= 0)
		{
			ans += abs(neg[neg.size() / m * m]) * 2;
		}
	}
	else if (abs(neg[0]) > pos[0])
	{
		ans += abs(neg[0]);
		for (int i = 1; i < neg.size()/m;i++)
		{
			ans += abs(neg[i * m]) * 2;
		}
		if (neg.size() % m != 0 && neg.size() / m * m != 0)
		{
			ans += abs(neg[neg.size() / m*m]) * 2;
		}
		for (int i = 0; i < pos.size() / m; i++)
		{
			ans += pos[i * m] * 2;
		}
		if (pos.size() % m != 0)
		{
			ans += pos[pos.size() / m * m] * 2;
		}
	}
	else
	{
		ans += pos[0];
		for (int i = 0; i < neg.size() / m; i++)
		{
			ans += abs(neg[i * m]) * 2;
		}
		if (neg.size() % m != 0)
		{
			ans += abs(neg[neg.size() / m * m]) * 2;
		}
		for (int i = 1; i < pos.size() / m; i++)
		{
			ans += pos[i * m] * 2;
		}
		if (pos.size() % m != 0 && pos.size() / m * m != 0)
		{
			ans += pos[pos.size() / m * m] * 2;
		}
	}


	cout << ans;


	
	return 0;
}