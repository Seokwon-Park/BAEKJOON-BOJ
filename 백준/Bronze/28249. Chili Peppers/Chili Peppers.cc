#include<iostream>
#include<unordered_map>


using namespace std;

using ll = long long;

int a[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	unordered_map<string, int> um;
	um["Poblano"] = 1500;
	um["Mirasol"] = 6000;
	um["Serrano"] = 15500;
	um["Cayenne"] = 40000;
	um["Thai"] = 75000;
	um["Habanero"] = 125000;

	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		ans += um[s];
	}
	cout << ans;

	return 0;
}