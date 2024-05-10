#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int n;

int parse(string s)
{
	vector<int> nums;
	vector<char> ops;
	string tmp = "";
	for (auto c : s)
	{
		if (c <= '9' && c >= '0')
			tmp += c;
		else
		{
			if (c == ' ')
			{
				continue;
			}
			else
			{
				ops.push_back(c);
				nums.push_back(stoi(tmp));
				tmp = "";
			}
		}
	}
	nums.push_back(stoi(tmp));

	int ret = nums[0];
	for (int i = 0; i < ops.size(); i++)
	{
		if (ops[i] == '+')
		{
			ret += nums[i + 1];
		}
		else
		{
			ret -= nums[i + 1];
		}
	}

	return ret;
}

void func(string s, int k, vector<string>& ans)
{
	if (k == n - 1)
	{
		if (parse(s) == 0)
			ans.push_back(s);
		return;
	}

	char num = (k + 2) + '0';
	func(s + '+' + num, k + 1, ans);
	func(s + '-' + num, k + 1, ans);
	func(s + ' ' + num, k + 1, ans);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		cin >> n;
		vector<string> v;
		func("1", 0, v);
		sort(v.begin(), v.end());
		for (string s : v)
			cout << s << '\n';
		cout << '\n';
	}

	return 0;
}