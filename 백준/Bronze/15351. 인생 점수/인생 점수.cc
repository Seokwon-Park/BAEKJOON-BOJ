#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string s;
		getline(cin, s);
		int score = 0;
		for (auto c: s)
		{
			if (isalpha(c))
			{
				score += c - 'A' + 1;
			}
		}
		if (score == 100)
			cout << "PERFECT LIFE";
		else
			cout << score;
		cout << '\n';
	}

	return 0;
}