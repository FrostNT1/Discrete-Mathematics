// program to count the number of numbers that are strictly divisible
#include <bits/stdc++.h>
using namespace std;

int count(int a[], int m, int n)
{
	int odd = 0, even = 0;
	int flag, i, j, p = 1;
	int pow = (1 << n);

	// from flag 000..0 to 111..1
	for (flag = 1; flag < pow; flag++)
	{
		p = 1;
		for (j = 0; j < n; j++)
		{
			// Checking if j bit in the flag is set
			// if set then point j element from set
			if (flag & (1 << j))
			{
				p *= a[j];
			}
		}
		// if set bits is odd, then add to
		// the number of multiples
		if (__builtin_popcount(flag) & 1)
			odd += ( m / p );
		else
			even += ( m / p );
	}

	return odd - even;
}
int main()
{
    cout << "-----------------------------------------CODE BY : SHIVAM TYAGI ____ 2019UCO1725----------------------------------------\n";
	int m, x, p;
    cout << "Enter number on which inclusion exclusion will be applied\n";
	cin >> m;
	cout << "Enter number of divisors\n";
	cin >> x;
    int a[x];
    while(x!=0)
    {
        x--;
        cout << "Enter divisors\n";
        cin >> p;
        a[x] =p;
    }
	int n = sizeof(a) / sizeof(a[0]);
	cout << count(a, m, n) << endl;
	cout << "-----------------------------------------CODE BY : SHIVAM TYAGI ____ 2019UCO1725----------------------------------------\n";
	return 0;
}
