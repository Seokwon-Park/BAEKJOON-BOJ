#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

string books[16];
int price[16];
int curprice;
int n;
int ans = INF;

vector<int> word(26);

void func(int k, string cur)
{
	if (k == n)
	{
		vector<int> tmp(26);
		for (auto c : cur)
		{
			tmp[c - 'A']++;
		}
		bool isPoss = true;
		for (int i = 0; i < 26; i++)
		{
			if (word[i] > tmp[i])
			{
				isPoss = false;
				break;
			}
		}
		if (isPoss)
		{
			ans = min(ans, curprice);
		}

		return;
	}
	curprice += price[k];
	func(k + 1, cur + books[k]);
	curprice -= price[k];
	func(k + 1, cur);

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	for (auto c : s)
	{
		word[c - 'A']++;
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> price[i] >> books[i];
	}

	func(0, "");

	cout << (ans == INF? -1 : ans);

	return 0;
}
