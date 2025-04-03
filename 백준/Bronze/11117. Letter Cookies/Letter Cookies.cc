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

	int t;
	cin >> t;
	while (t--)
	{
		vector<int> letters(26, 0);
		string s;
		cin >> s;
		for (auto c : s)
		{
			letters[c - 'A']++;
		}

		int w;
		cin >> w;
		for (int i = 0; i < w; i++)
		{
			string s;
			cin >> s;
			vector<int> word(26, 0);
			for (auto c : s)
			{
				word[c - 'A']++;
			}

			bool canMake = true;
			for (int j = 0; j < 26; j++)
			{
				if (word[j] > letters[j])
				{
					canMake = false;
					break;
				}
			}
			if (canMake)
			{
				cout << "YES";
			}
			else
			{
				cout << "NO";
			}
			cout << '\n';
		}
	}



	return 0;
}