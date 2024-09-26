#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<ll> v(n);
	vector<ll> res(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		res[i] = v[i];
	}
	
	for (int i = n - 2; i >= 0; i--)
	{
		if(res[i] < res[i + 1])
		{
			ll tmp = res[i + 1] / res[i];
			if (res[i + 1] % res[i] == 0)
			{
				tmp--;
			}
			res[i] += v[i] * tmp;
		}
	}

	cout << res[0];


	return 0;
}

