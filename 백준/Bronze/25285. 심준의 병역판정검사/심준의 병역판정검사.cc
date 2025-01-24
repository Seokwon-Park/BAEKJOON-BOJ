#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int Result(double h, double w)
{
	double bmi = w / (h * h / 10000.0);
	if (h < 140.1)
		return 6;
	else if (h < 146.0)
		return 5;
	else if (h < 159.0)
		return 4;
	else if (h < 161.0)
	{
		if (bmi >= 16.0 && bmi < 35.0)
			return 3;
		else
			return 4;
	}
	else if (h < 204.0)
	{
		if (bmi >= 20.0 && bmi < 25.0) return 1;
		else if ((bmi >= 18.5 && bmi < 20.0) || (bmi >= 25.0 && bmi < 30.0)) return 2;
		else if ((bmi >= 16.0 && bmi < 18.5) || (bmi >= 30.0 && bmi < 35.0)) return 3;
		else  return 4;
	}
	else
	{
		return 4;
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		double a, b;
		cin >> a >> b;
		cout << Result(a, b) << '\n';
	}

	return 0;
}



