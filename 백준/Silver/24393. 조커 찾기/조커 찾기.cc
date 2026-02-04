#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

vector<int> adj[15];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> deck(28);
	for (int i = 1; i <= 27; i++)
	{
		deck[i] = i;
	}
	cin.ignore();
	while (n--)
	{
		vector<int> a;
		string s;
		getline(cin, s);

		istringstream iss(s);
		string tmp;
		while (getline(iss, tmp, ' '))
		{
			a.push_back(stoi(tmp));
		}

		int l = 1;
		int r = 14;

		int cur = 1;
		vector<int> newdeck(28);
		for (int i = 0; i < a.size(); i++)
		{
			for (int j = 0; j < a[i]; j++)
			{
				if (i % 2 == 0)
				{
					newdeck[cur++] = deck[r + j];
				}
				else
				{
					newdeck[cur++] = deck[l + j];
				}
			}
			if (i % 2 == 0)
			{
				r += a[i];
			}
			else
			{
				l += a[i];
			}
		}
		deck.swap(newdeck);
	}

	cout << find(deck.begin(), deck.end(), 1) - deck.begin();

	return 0;
}