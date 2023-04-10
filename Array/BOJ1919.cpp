#include <bits/stdc++.h>

using namespace std;

int arr1[26];
int arr2[26];
int res;

void fill_arr(string s, int *arr)
{
	for (auto c : s)
		arr[c - 'a']++;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s1, s2;
	cin >> s1 >> s2;
	
	fill_arr(s1, arr1);
	fill_arr(s2, arr2);

	for (int i = 0; i < 26; i++)
	{
		if (arr1[i] != arr2[i])
			res += abs(arr1[i] - arr2[i]);
	}

	cout << res;
		
	return 0;
}


