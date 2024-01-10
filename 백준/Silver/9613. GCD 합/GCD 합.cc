#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;

		vector<int> nums(n);
		for (int i = 0; i < n; i++)
		{
			cin >> nums[i];
		}
		sort(nums.begin(), nums.end());

		if (n > 1)
		{
			vector<int> ncr(n, 0);
			fill(ncr.end() - 2, ncr.end(), 1);

			long long sum = 0;
			do
			{
				vector<int> gcdvec;
				for (int i = 0; i < n; i++)
				{
					if (ncr[i] == 1)
					{
						gcdvec.push_back(nums[i]);
					}
				}
				sum += gcd(gcdvec[0], gcdvec[1]);
			} while (next_permutation(ncr.begin(), ncr.end()));
			cout << sum << '\n';
		}
		else
		{
			cout<<  nums[n - 1] << '\n';
		}
	}

	return 0;
}