#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int calc(string first, string last)
{
	int fh = stoi(first.substr(0, 2));
	int fs = stoi(first.substr(3, 2));
	int lh = stoi(last.substr(0, 2));
	int ls = stoi(last.substr(3, 2));

	int h, s;
	int carry = 0;
	if (ls - fs < 0)
	{
		s = ls - fs + 60;
		carry = 1;
	}
	else
		s = ls - fs;

	h = lh - fh - carry;
	
	return s + h * 60;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int as = 0, bs = 0;
	int awin = 0, bwin = 0;
	int state = 0; // 1 : a win 2: b win
	int curstate = 0;
	string prevtime;
	while (n--)
	{
		int t;
		string ms;
		cin >> t >> ms;

		if (t == 1)as++;
		else bs++;

		if (state == 0)
		{
			// 무승부 상태였는데 균형이 깨지면 상태를 변경하고 그 시간을 기록
			if (as > bs)
				state = 1;
			else if (bs > as)
				state = 2;
			prevtime = ms; // 그 순간을 기록
		}
		else // 어떤 한팀이 이기고 있는데
		{
			if (as == bs) // 만약 균형이 같아지면
			{
				int tmp = calc(prevtime, ms);
				if (state == 1)
					awin += tmp;
				else
					bwin += tmp;
				state = 0;
			}
		}
	}
	if (state != 0) // 만약 종료시간까지 한쪽이 이기고 있으면..
	{
		int tmp = calc(prevtime, "48:00");
		if (state == 1)
			awin += tmp;
		else
			bwin += tmp;
		state = 0;
	}

	cout << setw(2) << setfill('0') << awin / 60 << ':' << setw(2) << setfill('0') << awin % 60 << '\n';
	cout << setw(2) << setfill('0') << bwin / 60 << ':' << setw(2) << setfill('0') << bwin % 60 << '\n';


	return 0;
}
