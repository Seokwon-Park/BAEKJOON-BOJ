#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

bool h, m, s;
int ans;
int times[3];

void fn(int k)
{
	if (k == 3)
	{
		ans++;
		return;
	}
	int val = times[k];
	if (h == false && val >= 1 && val <= 12)
	{
		h = true;
		fn(k + 1);
		h = false;
	}
	if (m == false && val >= 0 && val <= 59)
	{
		m = true;
		fn(k + 1);
		m = false;
	}
	if (s == false && val >= 0 && val <= 59)
	{
		s = true;
		fn(k + 1);
		s = false;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	for (int i = 0; i < 3; i++)
	{
		int n = stoi(s.substr(i * 3, 2));
		times[i] = n;
	}

	fn(0);

	cout << ans;

	return 0;
}