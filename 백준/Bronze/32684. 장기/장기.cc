#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> score = { 13,7,5,3,3,2 };
	float c = 0.0f;
	float e = 1.5f;
	for (int i = 0; i < 6; i++)
	{
		int x;
		cin >> x;
		c += score[i] * x;
	}
	for (int i = 0; i < 6; i++)
	{
		int x;
		cin >> x;
		e += score[i] * x;
	}

	if (c > e)
	{
		cout << "cocjr0208";
	}
	else
	{
		cout << "ekwoo";
	}




	return 0;
}
