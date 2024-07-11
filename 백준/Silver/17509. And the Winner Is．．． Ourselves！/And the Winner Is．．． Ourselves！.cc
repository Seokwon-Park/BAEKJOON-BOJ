#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 0;
	int ans = 0;
	vector<int> vec(11);
	for (int i = 0; i < 11; i++)
	{
		int d, v;
		cin >> d >> v;	
		vec[i] = d;
		ans += v * 20;
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < 11; i++)
	{
		t += vec[i];
		ans += t;
	}
	cout << ans;


	return 0;
}