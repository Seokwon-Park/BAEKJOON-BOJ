#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;
template <typename T>
using vec = vector<T>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string n;
	cin >> n;
	bool isFive = true;
	for (int i = 0; i < 3; i++)
	{
		if (n[i] != '5')
		{
			isFive = false;
			break;
		}
	}
	if (isFive)
		cout << "YES";
	else
		cout << "NO";


	return 0;
}