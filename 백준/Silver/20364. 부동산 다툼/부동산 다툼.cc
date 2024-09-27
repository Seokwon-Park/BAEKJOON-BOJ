#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

bool v[(1 << 20) + 5];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	for (int i = 0; i < q; i++)
	{
		int x;
		cin >> x;
		int tmp = x;
		bool isArrive = true;
		int lastFind = -1;
		while (tmp)
		{
			if (v[tmp])
			{
				lastFind = tmp;
				isArrive = false;
			}
			tmp >>= 1;
		}
		if (isArrive) // 원하는 땅에 도착할 수 있는 경우 땅 목록에 입력
		{
			v[x] = true;
			cout << 0 << '\n';
		}
		else
		{
			cout << lastFind << '\n';
		}
	}



	return 0;
}

