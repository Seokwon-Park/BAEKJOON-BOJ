#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;


int n;
vector<int> ans;
vector<int> pos(17, -1);
bool isClosed[8];

void func(int k, vector<int> v)
{
	if (k == n * 2)
	{
		for (int i : ans)
			cout << i << ' ';
		exit(0);
	}

	for (int i = 0; i < n; i++)
	{
		if (isClosed[i]) continue;
		int num = v[i];
		if (pos[num] == -1)
		{
			pos[num] = k;
			ans.push_back(num);
			func(k + 1, v);
			ans.pop_back();
			pos[num] = -1;
		}
		else
		{
			if (k - pos[num] == num + 1)
			{
				isClosed[i] = true;
				ans.push_back(num);
				func(k + 1, v);
				ans.pop_back();
				isClosed[i] = false;
			}
			else
				continue;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	func(0, v);
	cout << -1;

	return 0;
}