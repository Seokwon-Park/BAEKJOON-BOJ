#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

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

	// 홀수를 왼쪽으로 밀때
	int res1 = 0;
	int needtomove = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i] % 2)
		{
			res1 += needtomove;
		}
		else
		{
			needtomove++;
		}
	}
    
    // 홀 오른쪽
	int res2 = 0;
	needtomove = 0;
	for (int i = n-1; i >=0; i--)
	{
		if (v[i] % 2)
		{
			res2 += needtomove;
		}
		else
		{
			needtomove++;
		}
	}

	cout << min(res1, res2);

	return 0;
}