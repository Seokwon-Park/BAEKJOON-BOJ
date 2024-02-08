#include <bits/stdc++.h>

using namespace std;

pair<int, int> coord[5][5]; // dir/order


pair<int, int> func(int n, int m)
{
	if (n == 2)
	{
		if (m == 1)
			return { 1,1 };
		if (m == 2)
			return { 1,2 };
		if (m == 3)
			return { 2,2 };
		if (m == 4)
			return { 2,1 };
	}
	int sq = n * n / 4;
	pair<int, int> res;
	if (m <= sq)
	{
		res = func(n / 2, m);
		swap(res.first, res.second); //  / 을 기준으로 대칭
		return res;
	}
	else if (m <= sq * 2)
	{
		res = func(n / 2, m - sq);
		res.second += n / 2;
		return res;
	}
	else if (m <= sq * 3)
	{
		res = func(n / 2, m - sq * 2);
		res.first += n / 2;
		res.second += n / 2;
		return res;
	}
	else // rotated..
	{
		res = func(n / 2, m - sq * 3);
		//  \ 을 기준으로 대칭
		int tmp = res.first;
		res.first = n / 2 - res.second + 1;
		res.second = n / 2 - tmp+1;
		// 4분면(?)에 대한 x, y offset
		res.first += n / 2;
		return res;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	pair<int,int> ans = func(n, m);
	
	cout << ans.first << ' ' << ans.second;

	return 0;
}