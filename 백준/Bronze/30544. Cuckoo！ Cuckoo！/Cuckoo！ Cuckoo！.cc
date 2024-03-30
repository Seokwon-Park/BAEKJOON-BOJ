#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string t;
	cin >> t;
	int n;
	cin >> n;
	int curh = stoi(t.substr(0, 2));
	int curm = stoi(t.substr(3));
	int cooks = 0;
	if (curm == 0) // 현재시간이 정각인경우 
	{
		cooks += curh;
	}
	else
	{
		curm += 15 - (curm % 15 == 0? 15: curm%15); // 현재 시간을 15, 30, 45, 60으로 맞춘다.
		if (curm == 60)
		{
			curh = curh + 1 > 12 ? 1 : curh + 1;
			cooks += curh;
			curm = 0;
		}
		else
		{
			cooks++;
		}
	}
	
	while (cooks < n)
	{
		curm += 15;
		if (curm == 60)
		{
			curh = curh + 1 > 12 ? 1 : curh + 1;
			cooks += curh;
			curm = 0;
		}
		else
		{
			cooks++;
		}
	}
	
	string h(to_string(curh)), m(to_string(curm));

	cout << (h.size() == 1 ? '0' + h : h) << ':' << (m.size() == 1 ? '0' + m : m);

	return 0;
}