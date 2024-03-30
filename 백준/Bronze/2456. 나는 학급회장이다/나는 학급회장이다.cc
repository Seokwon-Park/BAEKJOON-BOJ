#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int cnd[4];
int v[4][4]; // i번 후보 j점표 갯수.

int vs(int a, int b)
{
	for (int i = 3; i >= 2; i--)
	{
		if (v[a][i] == v[b][i]) continue;
		if (v[a][i] > v[b][i])
			return a;
		else
			return b;
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		cnd[1] += a;
		cnd[2] += b;
		cnd[3] += c;
		v[1][a]++;
		v[2][b]++;
		v[3][c]++;
	}

	auto mx = max_element(cnd + 1, cnd + 4);
	int unic = count(cnd + 1, cnd + 4, *mx);
	if (unic == 1)
	{
		cout << mx - (cnd+1) +1 << ' ' << *mx;
	}
	else if(unic == 2)
	{
		int winner;
		if (cnd[1] == cnd[2])
			winner = vs(1, 2);
		else if (cnd[2] == cnd[3])
			winner = vs(2, 3);
		else
			winner = vs(1, 3);
		cout << winner << ' ' << *mx;

	}	
	else
	{
		int winner = vs(1, 2);
		if (winner == 0)
			winner = vs(1, 3);
		else
			winner = vs(winner, 3);
		cout << winner << ' ' << *mx;
	}

	return 0;
}