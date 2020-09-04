#include <bits/stdc++.h>
using namespace std;

bool chk_meet(int *p,int a,int b,int n)
{
    int meet[50];
    int i = 0, j = 0, k = 0;
    for(i; i<n; i++)
        if(a%p[i] == 0 && b%p[i] == 0 )
            meet[k++] = p[i];

    if(k == 0)
        return false;

    i = 0;
    for(i; i<k; i++)
    {
        int flag = 1;
        for(j; j<k; j++)
            if(meet[i]%meet[j]!=0)
                {
                    flag = 0;
                    break;
                }
        if(flag == 1)
            return true;
    }
    return false;
}
bool chk_join(int *p,int a,int b,int n)
{
    int join[50];
    int i = 0, j = 0, k = 0;
    for(i; i<n; i++)
        if(p[i]%a == 0 && p[i]%b == 0)
            join[k++] = p[i];

    if(k == 0 )
        return false;

    i = 0;
    for(i; i<k; i++)
    {
        int flag = 1;
        for(j; j<k; j++)
            if(join[j]%join[i]!=0)
                {
                    flag = 0;
                    break;
                }
        if(flag == 1)
            return true;
    }
    return false;
}



bool chk_lattice(int *p,int n)
{
    for(int i = 0 ;i<n;i++)
        for(int j = 0 ;j<n;j++)
            if(!chk_join(p,p[i],p[j],n) || !chk_meet(p,p[i],p[j],n))
                return false;
    return true;
}

int main()
{
    cout << "-----------------------------------------CODE BY : SHIVAM TYAGI ____ 2019UCO1725----------------------------------------\n";
    cout<<"Enter no of elements in the Poset - \t";
    int i, s;
    cin >> s;
    int *poset = new int[s];
    cout << "Enter the elements of the Poset" << endl;
    for(i = 0; i<s; i++)
        cin >> poset[i] ;
    if(chk_lattice(poset, s) == true)
        cout << "The given Poset is a lattice" << endl;
    else
        cout << "The given Poset is not a Lattice" << endl;
    cout << "-----------------------------------------CODE BY : SHIVAM TYAGI ____ 2019UCO1725----------------------------------------";
    return 0;
}
