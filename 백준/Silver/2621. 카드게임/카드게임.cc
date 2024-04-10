#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

set<char>color;
map<int, int> num;
vector<int> nums(5);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 5; i++)
	{
		char c;
		int n;
		cin >> c >> n;
		color.insert(c);
		num[n]++;
		nums[i] = n;
	}

	sort(nums.begin(), nums.end());
	int ans = 0;
	bool isCont = true;
	for (int i = 1; i < 5; i++)
	{
		if (nums[i] - nums[i - 1] != 1)
		{
			isCont = false;
			break;
		}
	}

	int mxval = nums[nums.size() - 1];
	if (color.size() == 1) // 같은색
	{
		ans = mxval;
		if (isCont) // 연속
		{
			ans += 900;
		}
		else // 색깔만 같을때
			ans += 600;
	}
	else if (num.size() == 2)
	{
		pair<int, int> mx = *max_element(num.begin(), num.end(), [](const auto& a, const auto& b)
			{
				return a.second < b.second;
			});

		pair<int, int> mn = *min_element(num.begin(), num.end(), [](const auto& a, const auto& b)
			{
				return a.second < b.second;
			});
		if (mx.second == 4)
		{
			ans = mx.first + 800;
		}
		else if (mx.second == 3) // 3 / 2 왜냐하면 set의 size가 2이기 때문에
		{
			ans = mx.first * 10 + mn.first + 700;
		}
		else
			ans = mxval + 100;
	}
	else if (num.size() == 3)
	{
		pair<int, int> mx = *max_element(num.begin(), num.end(), [](const auto& a, const auto& b)
			{
				return a.second < b.second;
			});
		if (mx.second == 3) // 3/1/1 일때
		{
			ans = mx.first + 400;
		}
		if (mx.second == 2)
		{
			vector<int> v;
			for (auto [a, b] : num)
			{
				if (b == 2) v.push_back(a);
			}
			if (v[0] > v[1])
				ans = v[0] * 10 + v[1] + 300;
			else
				ans = v[1] * 10 + v[0] + 300;
		}
	}
	else if (num.size() == 4)
	{
		for (auto [a, b] : num)
		{
			if (b == 2)
			{
				ans = a + 200;
				break;
			}
		}
	}
	else if (isCont)
	{
		ans = mxval + 500;
	}
	else
	{
		ans = mxval + 100;
	}

	cout << ans;

	return 0;
}