#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int n, k;
vector<int> cor;
vector<int> my;
int ans = 0;

void func(int x, vector<int> cur)
{
	if (x == k)
	{
		int m = 0;
		for (int i = 0; i < n; i++)
		{
			if (cor[i] == cur[i])
			{
				m++;
			}
		}
		ans = max(ans, m);
		return;
	}

	vector<int> temp;
	// pull
	for (int i = 0; i < n-1; i++)
	{
		temp = cur;
		for (int j = i; j < n - 1; j++)
		{
			temp[j] = temp[j + 1];
		}
		temp[n - 1] = 0;
		func(x + 1, temp);
	}

	//push
	for (int i = 0; i < n; i++)
	{
		temp = cur;
		for(int j = n-1; j > i; j--)
		{
			temp[j] = temp[j - 1];
		}
		temp[i] = 0;
		func(x + 1, temp);
	}


	// do nothing
	func(x + 1, cur);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		cor.push_back(x);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> x;
		my.push_back(x);
	}

	func(0, my);

	cout << ans;


	return 0;
}
