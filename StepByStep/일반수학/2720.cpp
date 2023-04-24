#include <bits/stdc++.h>

using namespace std;

vector<int> answer(4);
int cent[4] = { 25, 10,5, 1 };
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int money;		
		cin >> money;
		for (int i = 0; i < 4; i++)
		{
			answer[i] = money / cent[i];
			money %= cent[i];
		}
		for (auto a : answer)
			cout << a << ' ';
		cout << '\n';
	}
	return 0;
}
