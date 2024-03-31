#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool isPelin(string s)
{
	int n = s.size();
	for (int i = 0; i < n / 2; i++)
	{
		if (s[n - i - 1] != s[i])
			return false;
	}
	return true;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		int tmp = n;
		int rev = 0;
		while (tmp)
		{
			rev = rev * 10 + tmp % 10;
			tmp /= 10;
		}
		if (isPelin(to_string(n + rev)))
			cout << "YES";
		else
			cout << "NO";
		cout << '\n';

	}

	return 0;
}