#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v(1,0);
	vector<int> vsqrt(1,0);
	for (int i = 1;; i++)
	{
		if (i * i - v[i - 1] <= 1e5)
		{
			v.push_back(i * i);
			vsqrt.push_back(i);
		}
		else
			break;
	}
	
	int g;
	cin >> g;
	
	int st = 1;
	int en = 1;
	bool isNoAns = true;
	while (en < v.size())
	{
		int res = v[en] - v[st];
		if (res < g)
		{
			en++;
		}
		else if (res > g)
		{
			st++;
		}
		else
		{
			isNoAns = false;
			cout << vsqrt[en] << '\n';
			en++;
		}
	}

	if (isNoAns)
		cout << -1;

	return 0;
}