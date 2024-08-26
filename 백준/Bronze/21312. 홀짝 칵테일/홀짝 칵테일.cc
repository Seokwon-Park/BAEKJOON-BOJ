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
	
	vector<int> v(3);
	bool hasOdd = false;
	for (int i = 0; i < 3; i++)
	{
		cin >> v[i];
		if (v[i] % 2)
			hasOdd = true;
	}

	if (hasOdd)
	{
		int ans = 1;
		for (int i = 0; i < 3; i++)
		{
			if (v[i] % 2)
				ans *= v[i];
		}
		cout << ans;
	}
	else
	{
		cout << v[0] * v[1] * v[2];
	}


	return 0;
}