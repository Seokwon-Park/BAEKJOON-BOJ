#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int v[10];
vector<int> bt;
int ans;

void func(int n,int cont, int prev)
{
	if (n == 10)
	{
		int score = 0;
		for (int i = 0; i < 10; i++)
		{
			if (v[i] == bt[i])
				score++;
		}
		if (score >= 5)
			ans++;
		return;
	}
	for (int i = 1; i <= 5; i++)
	{
		if (cont == 2 && i == prev)continue;
		bt.push_back(i);
		if (prev == -1)
		{
			func(n + 1, 1, i);
		}
		else if (prev == i)
			func(n + 1, cont + 1, i);
		else
			func(n + 1, 1, i);
		bt.pop_back();
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 10; i++)
	{
		cin >> v[i];
	}

	func(0, 0, -1);
	cout << ans;

	return 0;
}