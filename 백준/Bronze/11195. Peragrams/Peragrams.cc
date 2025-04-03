#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	vector<int> letters(26, 0);
	for (auto c : s)
	{
		letters[c - 'a']++;
	}
	
	bool isOdd = false;
	int ans = 0;
	for (int i = 0; i < 26; i++)
	{
		if (letters[i] % 2 == 1)
		{
			if (isOdd == false) isOdd = true;
			else
			{ 
				ans++;
			}
		}
	}
	cout << ans;

	return 0;
}