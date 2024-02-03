#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a;

    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        a.push_back(input);
    }

    int ans1 = INT_MAX/2;
    int ans2 = INT_MAX/2;
    // 실수한부분 : INT_MAX끼리 더하면 오버 플로 나서 값이 이상해짐 ㅅㄱ;
    for (int i = 0; i < n; i++)
    {
        int lb = lower_bound(a.begin(), a.end(), -a[i]) - a.begin(); 
        if (lb + 1 < n && i != lb + 1 && abs(a[i] + a[lb + 1]) < abs(ans1 + ans2)) {
            ans1 = a[i];
            ans2 = a[lb + 1];
        }
        if (lb < n && i != lb && abs(a[i] + a[lb]) < abs(ans1 + ans2)) {
            ans1 = a[i];
            ans2 = a[lb];
        }
        if (lb != 0 && i != lb - 1 && abs(a[i] + a[lb - 1]) < abs(ans1 + ans2)) {
            ans1 = a[i];
            ans2 = a[lb - 1];
        }
    }
    if (ans1 > ans2)
    {
        swap(ans1, ans2);
    }

    cout << ans1 << ' ' << ans2;

    return 0;
}
