#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int dpi[1000005];
int dpd[1000005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
		
	vector<int> v(n+1);
	int mx = -1;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		mx = max(mx, v[i]);
		dpi[i] = mx;
	}

	mx = -1;
	for (int i = n; i >= 1; i--)
	{
		mx = max(mx, v[i]);
		dpd[i] = mx;
	}
	
	for(int i = 1; i<=n ;i++)
	{
		cout << dpi[i] << ' ' << dpd[i] << '\n';
	}


	return 0;
}