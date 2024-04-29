#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	
	sort(s.begin(), s.end());
	int ans = 0;
	do
	{
		int prev = s[0];
		bool flag = true;
		for (int i = 1; i < s.size(); i++)
		{
			if (prev == s[i])
			{
				flag = false;
				break;
			}
			else
				prev = s[i];
		}
		if(flag)
			ans++;
	} while (next_permutation(s.begin(), s.end()));

	cout << ans;

	return 0;
}