#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;
template <typename T>
using vec = vector<T>;

double b[2][2];
double bc[2][2];

void rotate()
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			bc[i][j] = b[i][j];
		}

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			b[j][1-i] = bc[i][j];
		}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			cin >> b[i][j];

	int n = 4;
	vd res;
	while (n--)
	{
		double aa = b[0][0] / b[1][0];
		double bb = b[0][1] / b[1][1];
		res.push_back(aa + bb);
		rotate();
	}
	cout << max_element(res.begin(), res.end()) - res.begin();

	return 0;
}