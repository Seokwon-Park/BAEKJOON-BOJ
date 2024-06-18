#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int a = 1; a <= 100; a++)
		for (int b = 2; b <= 100; b++)
			for (int c = b + 1; c <= 100; c++)
				for (int d = c + 1; d <= 100; d++)
				{
					if (a * a * a == b * b * b + c * c * c + d * d * d)
						cout << "Cube = " << a << ", Triple = (" << b << ',' << c << ',' << d << ")\n";
				}



	return 0;
}
