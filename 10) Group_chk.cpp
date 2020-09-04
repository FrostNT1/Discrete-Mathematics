#include <iostream>
#include <climits>

using namespace std;

bool chk_closure(int grid[10][10],int size)
{
    for(int i =1 ;i<=size;i++)
        for(int j =1 ;j<=size;j++)
        {
            int c = grid[i][j];
            if(c<1 || c>size)
                return false;
        }
    return true;
}

bool chk_associative(int grid[10][10],int size)
{
    for(int i = 1;i<=size;i++)
        for(int j = 1 ;j<=size;j++)
            for(int k= 1 ;k<=size;k++)
                if(grid[i][grid[j][k]] != grid[grid[i][j]][k]) // grid[a][b] != grid[b][a]
                    return false;
    return true;
}

bool invert(int grid[10][10],int size,int &e)
{
    int startElem = 1;
    int inverseElemIndex = -99; // smallest int
    for(int i = 1 ; i<=size; i++)
        if(grid[1][i] == startElem)
            {
                inverseElemIndex = i;
                break;
            }

    if(inverseElemIndex == -99)
        return false;
    for(int i = 1; i<=size; i++)
    {
        if(grid[inverseElemIndex][i] == i && grid[i][inverseElemIndex] == i) // grid[a][b] != grid[b][a]
            continue;
        else
            return false;
    }
    e = inverseElemIndex;
    return true;

}

bool invertable(int grid[10][10],int size,int e)
{
    for(int i = 1 ; i<=size; i++)
        {
            int p1 = i;
            int ff  = 0 ;
            for(int j = 1 ; j<=size; j++)
                if(grid[p1][j] == e)
                    {
                        if(grid[j][p1]!=e) // maybe move in else line to return false
                            return false;
                        ff = 1;
                        break;
                    }
            if(ff == 0)
                return false;
        }
    return true;
}


int main()
{
    cout << "-----------------------------------------CODE BY : SHIVAM TYAGI ____ 2019UCO1725----------------------------------------\n";
    int n;
    char elem[100];
    int table[10][10];
    int arr[256];
    for(int i = 0 ;i<256;i++)
        arr[i] = -1;
    int k = 1;
    cout << "Enter the number of elements in set: " ;
    cin >> n;
    cout << "Enter the elements of the set G:\n";
    for(int i = 0 ;i<n;i++)
    {
        char c;
        cin >> c;
        elem[k-1] = c;
        arr[(int)c] = k++;
    }
    cout << "Fill the Cayley table" << endl;
    cout << "o " ;
    for(int i = 0 ; i<n; i++)
        cout << elem[i] << " ";
    cout << endl;
    for(int i =1;i<=n;i++)
    {
        cout << elem[i-1] << " ";
        for(int j = 1; j<=n; j++)
        {
            char temp;
            cin >> temp;
            table[i][j] = arr[(int)temp];
        }
    }

    if(chk_closure(table,n) && chk_associative(table,n))
        {
        int e;
        if(invert(table,n,e) == false)
            cout << "The given input is not a group ";
        if(invertable(table,n,e) == false)
            cout << "The given input is not a group ";
        else
            cout << "The given input is a group " ;
        }
    else
        cout << "The given input is not a group" ;
    cout << "\n-----------------------------------------CODE BY : SHIVAM TYAGI ____ 2019UCO1725----------------------------------------";
    return 0;
}
/*
o 0 1 2 3 4
0 0 1 2 3 4
1 1 2 3 4 0
2 2 3 4 0 1
3 3 4 0 1 2
4 4 0 1 2 3*/
