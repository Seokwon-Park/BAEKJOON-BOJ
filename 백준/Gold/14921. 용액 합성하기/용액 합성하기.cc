#include <bits/stdc++.h>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int ans = INT_MAX;

	for (int i = 0; i < n; i++)
	{
		int lb = lower_bound(a.begin(), a.end(), -a[i])- a.begin();

		if (lb + 1 < n && lb + 1 != i && abs(a[lb+1] + a[i]) < abs(ans))
		{
			ans = a[lb+1] + a[i];
		}
		if (lb < n && lb != i && abs(a[lb] + a[i]) < abs(ans))
		{
			ans = a[lb] + a[i];
		}
		if (lb - 1 >=0 && lb - 1 != i && abs(a[lb-1] + a[i]) < abs(ans))
		{
			ans = a[lb-1] + a[i];
		}
	}

	cout << ans;

	return 0;
}
