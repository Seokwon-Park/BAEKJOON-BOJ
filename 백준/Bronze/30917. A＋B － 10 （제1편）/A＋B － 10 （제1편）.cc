#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    int resp;
    for (int a = 1; a <= 9; a++) {
        cout << "? A " << a << endl;

        cin >> resp;

        if (resp == 1) {
            for (int b = 1; b <= 9; b++) {
                cout << "? B " << b << endl;

                cin >> resp;
                if (resp == 1)
                {
                    std::cout << "! " << a + b;
                    return 0;
                }
            }
            
        }
    }


	return 0;
}
