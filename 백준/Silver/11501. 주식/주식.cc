#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> max;

	int tc;
	cin >> tc;
	while (tc--)
	{
		long long earn = 0; // 얼마 벌었나
		int n = 0;
		cin >> n;
		vector<int> vec;
		for (int i = 0; i < n; i++)
		{
			int price;
			cin >> price;
			vec.push_back(price);
		}

		int max = vec[n-1];
		for (int i = n-2; i >= 0; i--)
		{
			if (vec[i] < max)
			{
				earn += max - vec[i];
			}
			else if (vec[i] > max)
			{
				max = vec[i];
			}
		}

		cout << earn << '\n';
	}


	return 0;
}