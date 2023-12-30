#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string max_name;
	int max_poke = -1;
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		string name;
		cin >> name;
		int k, m;
		cin >> k >> m;
			
		int cnt = 0;
		while (k <= m)
		{
			m -= k; // 진화 1번
			cnt++; // 횟수 카운트
			m += 2; // 사탕 2개 돌려줌.
		}
		total += cnt;
		if (max_poke < cnt)
		{
			max_poke = cnt;
			max_name = name;
		}
	}

	cout << total << '\n';
	cout << max_name;

	return 0;
}