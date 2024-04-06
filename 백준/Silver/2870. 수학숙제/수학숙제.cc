#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<string> ans;
	while (n--)
	{
		string s;
		cin >> s;
		string num = "";
		for (char c : s)
		{
			if (isdigit(c))
			{
				num += c;
			}
			else
			{
				if (!num.empty())
				{
					int ix = 0;
					while (num[ix] == '0')
					{
						ix++;
					}
					if (ix == num.size())
					{
						num = "0";
					}
					else
					{
						num = num.substr(ix);
					}
					ans.push_back(num);
					num = "";
				}
			}
		}
		if (!num.empty())
		{
			int ix = 0;
			while (num[ix] == '0')
			{
				ix++;
			}
			if (ix == num.size())
			{
				num = "0";
			}
			else
			{
				num = num.substr(ix);
			}
			ans.push_back(num);
		}
	}
	sort(ans.begin(), ans.end(), [](const string& a, const string& b) 
		{
			if (a.size() == b.size())
			{
				for (int i = 0; i < a.size(); i++)
				{
					if (a[i] == b[i]) continue;
					return a[i] < b[i];
				}
			}
			return a.size() < b.size();
		});
	for (string i : ans)
		cout << i << '\n';

	return 0;
}