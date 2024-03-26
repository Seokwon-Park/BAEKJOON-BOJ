#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	ll sn = stoll(s);
	int n = s.size();
	ll ans = 0;
	for (int i = 1; i < n; i++) // n자리 이전까지는 그냥 펠린드롬 만들 수 있음
	{
		if (i == 1)
		{
			ans += 9;
		}
		else if (i % 2 == 1)
		{
			ll tmp = 9;
			for (int j = 0; j < i/2; j++)
			{
				tmp *= 10;
			}
			ans += tmp;
		}
		else if (i == 2)
		{
			ans += 9;
		}
		else
		{
			ll tmp = 9;
			for (int j = 0; j < i / 2 - 1; j++)
			{
				tmp *= 10;
			}
			ans += tmp;
		}
	}

	if (n == 1)
	{
		for (int i = 1; i <= sn; i++)
			ans++;
	}
	else if (n % 2 == 0)
	{
		int half = 1;
		for (int i = 0; i < n / 2 - 1; i++)
			half *= 10;
		
		while (1)
		{
			string s1 = to_string(half);
			string s2 = s1;
			reverse(s2.begin(), s2.end());
			s1 += s2;
			if (stoll(s1) <= sn)
			{
				ans++;
				half++;
			}
			else
				break;
		}
	}
	else if(n %2 == 1)
	{
		int half = 1;
		for (int i = 0; i < n / 2 -1; i++)
			half *= 10;
		int mid = 0;
		while (1)
		{
			string s1 = to_string(half);
			string s2 = s1;
			reverse(s2.begin(), s2.end());
			s1 = s1 + (char)(mid + '0') + s2;
			if (stoll(s1) <= sn)
			{
				ans++;
				mid++;
				if (mid > 9)
				{
					mid = 0;
					half++;
				}
			}
			else
			{
				break;
			}
		}
	}

	cout << ans;

	return 0;
}