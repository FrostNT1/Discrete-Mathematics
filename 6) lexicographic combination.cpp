#include <iostream>
using namespace std;

void comb(char c[],int x)
{
    static char res[6];
    static int A[6]={0};

    res[x]='\0';
    for(int i=0; c[i]!='\0'; i++)
        if(A[i]==0)
        {
            cout << res <<endl;
            res[x]=c[i];
            A[i]=1;
            comb(c,x+1);
            A[i]=0;
        }
}
int main()
{
    char flg;
    cout << "-----------------------------------------CODE BY : SHIVAM TYAGI ____ 2019UCO1725----------------------------------------\n";
    cout << "initiate pre-run? (y/n)"<< endl;
    cin >> flg;
    if (flg == 'n')
    {
        char s[10];
        cout << "Enter character set: \n";
        cin >> s;
        comb(s, 0);
    }
    else
    {
        char pre[]="Shivam";
        comb(pre,0);
    }
    cout << "-----------------------------------------CODE BY : SHIVAM TYAGI ____ 2019UCO1725----------------------------------------\n";
    return 0;
}
