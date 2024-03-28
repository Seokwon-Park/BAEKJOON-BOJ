#include<iostream>
#include<string>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	ll ab = stoll(to_string(a) + to_string(b));
	ll cd = stoll(to_string(c) + to_string(d));
	cout << ab + cd;

	return 0;
}
