#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

bool find(int target, vector<int>& vec, int k)
{
	queue<int> q;
	q.push(0);
	int dist = 0;
	vector<bool> v(10000, false);
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			int cur = q.front();
			q.pop();
			for (int j = 0; j < vec.size(); j++)
			{
				int nxt = cur + vec[j];
				if (nxt > target || v[nxt])continue;
				if (nxt == target)
				{
					return true;
				}
				q.push(nxt);
				v[nxt] = true;
			}
		}
		dist++;
		if (dist >= k)
			return false;
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int k;
	cin >> k;

	int num = 1;
	while (1)
	{
		bool res = find(num, v, k);
		if (!res)
		{
			if (num % 2 == 0)
				cout << "holsoon win at " << num;
			else
				cout << "jjaksoon win at " << num;
			break;
		}
		num++;
	}


	return 0;
}