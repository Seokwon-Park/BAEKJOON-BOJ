#include <bits/stdc++.h>

using namespace std;

int sosu[1000005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;

	vector<int> nums(t);
	for (int i = 0; i < t; i++)
	{
		cin >> nums[i];
	}

	int range = *max_element(nums.begin(), nums.end());

	fill(sosu, sosu + range + 1, 1);
	sosu[0] = 0;
	sosu[1] = 0;
	for (long long i = 2; i <= range; i++)
	{
		if (!sosu[i]) continue;
		for (long long j = i * i; j <= range; j += i)
		{
			sosu[j] = 0;
		}
	}

	for (auto i : nums)
	{
		int answer = 0;
 		for (int j = 0; j <= i / 2; j++)
		{
			if (sosu[j])
			{
				if (sosu[i - j])
				{
					answer++;
				}
			}
		}
		cout << answer << '\n';
	}

	return 0;
}