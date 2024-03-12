#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c;
	int d, e, f;
	cin >> a >> b >> c;
	cin >> d >> e >> f;
	int Max = a * 3 + b * 20 + c * 120;
	int Mel = d * 3 + e * 20 + f * 120;

	if (Max == Mel)
		cout << "Draw";
	else if (Max < Mel)
		cout << "Mel";
	else
		cout << "Max";
	return 0;
}