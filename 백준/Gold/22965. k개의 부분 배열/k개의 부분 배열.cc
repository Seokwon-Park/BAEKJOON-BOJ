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
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	bool isAscend = true;
	int save = 0;
	for (int i = 0; i < n-1; i++)
	{
		if (v[i] > v[i + 1])
		{
			isAscend = false;
			save = i + 1;
			break;
		}
	}

	bool checkSecond = true;
	for (int i = save; i < n - 1; i++)
	{
		if (v[i] > v[i + 1])
		{
			checkSecond = false;
			save = i + 1;
			break;
		}
	}
	if (checkSecond)
	{
		if (v[n - 1] > v[0])
			checkSecond = false;
	}

	if (isAscend)
	{
		cout << 1;
	}
	else if(checkSecond)
	{
		cout << 2;
	}
	else
	{
		cout << 3;
	}


	return 0;
}