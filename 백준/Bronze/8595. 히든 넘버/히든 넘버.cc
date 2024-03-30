#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	cin >> s;
	string digit= "";
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (isdigit(s[i]))
		{
			digit += s[i];
		}
		else if (isalpha(s[i]))
		{
			if (!digit.empty())
			{
				ans += stoll(digit);
				digit = "";
			}
		}
	}
	if (!digit.empty())
	{
		ans += stoll(digit);
	}
	cout << ans;

	return 0;
}