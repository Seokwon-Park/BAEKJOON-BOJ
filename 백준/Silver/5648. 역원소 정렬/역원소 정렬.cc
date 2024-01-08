
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<long long> arr;
	for (int i = 0; i < n; i++)
	{
		string num;
		cin >> num;
		reverse(num.begin(), num.end());
		arr.push_back(stoll(num));
	}

	sort(arr.begin(), arr.end());

	for (auto i : arr)
	{
		cout << i << '\n';
	}

	return 0;
}