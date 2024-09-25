#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

string str[10];
int change[10];
bool isUsed[10];
int n;
int ans = INF;
int cur = 0;

void func(int k, char last)
{
	if (k == n)
	{
		ans = min(ans, cur);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (isUsed[i])continue;
		cur += change[i];
		isUsed[i] = true;
		if (cur > ans)
		{
			cur -= change[i];
			isUsed[i] = false;
			continue;
		}
		if (k != 0)
		{
			if (last == str[i][0])
			{
				func(k + 1, str[i][str[i].size() - 1]);
			}
			else
			{
				cur += 1;
				func(k + 1, str[i][str[i].size() - 1]);
				cur -= 1;
			}
		}
		else
		{
			func(k + 1, str[i][str[i].size() - 1]);
		}
		isUsed[i] = false;
		cur -= change[i];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
		char prev = 'x';
		int changed = 0;
		for (auto c : str[i])
		{
			if (prev == 'x')
			{
				prev = c;
			}
			else if (prev != c)
			{
				changed++;
				prev = c;
			}
		}
		change[i] = changed;
	}
	func(0, '\0');

	cout << ans;


	return 0;
}

