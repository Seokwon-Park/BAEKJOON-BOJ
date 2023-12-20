#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;

	vector<int> lv(n);

	int cnt = 0;
	
	for (int i = 0; i < n; i++)
	{
		cin >> lv[i];
	}

	if (n == 1)
	{
		cout << 0;
		return 0;
	}

	for (int i = n-1; i >= 1; i--)
	{
		if (lv[i] <= lv[i - 1])
		{
			cnt += lv[i - 1] - lv[i] + 1;
			lv[i - 1] = lv[i] - 1;
		}
	}

	cout << cnt;

	return 0;
}