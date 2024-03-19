#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;
template <typename T>
using vec = vector<T>;

int t[301];

ll w(int n)
{
	ll res = 0;
	for (int k = 1; k <= n; k++)
	{
		res += (k * t[k + 1]);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	const double PI = 3.1415927;

	int ix = 1;
	while (1)
	{
		double r, s, t;
		cin >> r >> s >> t;
		if (s == 0)break;
		//r = inch inch to feet -> feet to miles.
		// t is sec.
		//trip #n : 바퀴 이동거리, 바퀴이동거리 /걸린시간
		//지름을 줬기 때문에 그냥 PI * r;
		double itom = PI * r * s / 12 / 5280;
		double stoh = t / 3600;
		cout << fixed << setprecision(2);
		cout << "Trip #" << ix++ << ": " << itom << ' ' << itom / stoh << '\n';;

	}


	return 0;
}
