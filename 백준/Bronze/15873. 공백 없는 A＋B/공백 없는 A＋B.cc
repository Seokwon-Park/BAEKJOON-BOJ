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
	
	string ab;
	cin >> ab;
	if (ab.size() == 2)
	{
		cout << ab[0] + ab[1] - '0' + -'0';
	}
	else if(ab.size() == 3)
	{
		if (ab[1] == '0')
		{
			cout << 10 + ab[2] - '0';
		}
		else
		{
			cout << ab[0] - '0' + 10;
		}
	}
	else
	{
		cout << 20;
	}


	return 0;
}