#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> v(n);
	for (int& i : v)
		cin >> i;
	sort(v.begin(), v.end());
	int ans = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		int offset = 1;
		int cnt = 1; // v[i]~v[i]+4 범위에 포함된 숫자가 몇개인가
		while (i + offset < n)
		{
			if (v[i + offset] < v[i] + 5)
			{
				cnt++;
				offset++;
			}
			else
				break;
		}
		ans = min(5 - cnt, ans);
	}
	cout << ans;

	return 0;
}