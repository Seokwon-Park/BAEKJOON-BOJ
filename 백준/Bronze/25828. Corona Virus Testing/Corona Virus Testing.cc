#include<iostream>
#include<unordered_map>
#include<climits>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int g, p, t;
	cin >> g >> p >> t;
	int indiv = g * p;
	int group = g + p * t;
	if (indiv < group)
		cout << 1;
	else if (indiv > group)
		cout << 2;
	else
		cout << 0;

	return 0;
}