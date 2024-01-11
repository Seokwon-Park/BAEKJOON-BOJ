#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int c;
	cin >> c;
	while (c--)
	{
		int n, l;
		cin >> n >> l;

		vector<int> arr(n+1);
		vector<int> prefsum(n+1, 0); // 1~i번째 수까지의 합
		double min_val = 10000;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			prefsum[i] = prefsum[i - 1] + arr[i];
		}
		for (int i = 0; i <= n-l; i++) //0번째 ~ n번째 수까지의 합
		{
			for (int j = i+l; j <= n; j++) // prefsum[j] = 1~j번째 수까지의 합
			{
				double res = prefsum[j] - prefsum[i];
				min_val = min(min_val, res / (j - i));
			}
		}
		cout << fixed;
		cout.precision(11);
		cout << min_val << '\n';
		
	}

	return 0;
}
