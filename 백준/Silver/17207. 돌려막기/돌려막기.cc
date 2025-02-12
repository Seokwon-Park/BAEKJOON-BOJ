#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int A[5][5];
int B[5][5];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> A[i][j];
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> B[i][j];
		}
	}

	vector<int> v(5, 0);
	for (int i = 0; i < 5; i++)
	{
		for (int x = 0; x < 5; x++)
		{
			for (int y = 0; y < 5; y++)
			{
				v[x] += A[x][i] * B[i][y];
			}
		}
	}

	int ans = -1;
	int result = INF;
	for (int i = 4; i >= 0; i--)
	{
		if (result > v[i])
		{
			ans = i;
			result = v[i];
		}
	}

	vector<string> names = { "Inseo", "Junsuk", "Jungwoo", "Jinwoo", "Youngki" };
	cout << names[ans];



	return 0;
}



