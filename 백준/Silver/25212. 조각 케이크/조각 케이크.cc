#include <bits/stdc++.h>

using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;

	vector<int> v(n);
	for (int& i : v)
	{
		cin >> i;
	}

	int brute = 1 << n;
	int ans = 0;
	for(int i = 0; i< brute;i++)
	{
		double res = 0.0;
		for (int j = 0; j < n; j++)
		{
			if ((1 << j) & i)
			{
				res += 1.0 / v[j];
			}
		}
		if (res >= 0.99 && res <= 1.01)
			ans++;
	}
	cout << ans;

	return 0;
}