#include <iostream>
#include <climits>
using namespace std;

int add_table[10][10];
int multi_table[10][10];



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
    int invertElemIndex = -99; // smallest int
    for(int i = 1 ; i<=size; i++)
        if(grid[1][i] == startElem)
            {
                invertElemIndex = i;
                break;
            }

    if(invertElemIndex == -99)
        return false;
    for(int i = 1; i<=size; i++)
    {
        if(grid[invertElemIndex][i] == i && grid[i][invertElemIndex] == i) // grid[a][b] != grid[b][a]
            continue;
        else
            return false;
    }
    e = invertElemIndex;
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
bool abl_grp(int n) //abelian group
{
    if(!chk_closure(add_table,n) || !chk_associative(add_table,n)) // can't be abelian unless closure and associative
        return false;
    int e;
    if(!invert(add_table,n,e)) // needs to be invert
        return false;
    if(!invertable(add_table,n,e))
        return false;
    for(int i =1 ;i<=n;i++)
        for(int j =1 ;j<=n;j++)
            if(add_table[i][j]!=add_table[j][i])
                return false;
    return true;

}

bool smi_grp(int n)
{
    if(!chk_closure(multi_table,n) || !chk_associative(multi_table,n))
        return false;
    return true;
}


bool chk_dis(int n)
{   // compare elements from the multi table from opposite index
    for(int i =1 ;i<=n;i++)
        for(int j= 1;j<=n;j++)
            for(int k = 1 ;k<=n;k++)
                if(multi_table[i][add_table[j][k]]!=add_table[multi_table[i][j]][multi_table[i][k]])
                    return false;
    return true;
}

bool is_ring(int n){
    if(!abl_grp(n))
        return false;
    if(!smi_grp(n))
        return false;
    if(!chk_dis(n))
        return false;
    return true;
}

int main()
{
    cout << "-----------------------------------------CODE BY : SHIVAM TYAGI ____ 2019UCO1725----------------------------------------\n";
    int n;
    int arr[256];
    char elem[100];
    for(int i = 0 ;i<256;i++) arr[i] = -1;
    int k = 1;
    cout << "Enter number of elements in set G ~ " ;
    cin >> n;
    cout << "Enter the elements of the set G ~ ";
    for(int i = 0; i<n; i++)
        {
            char c;
            cin >> c;
            elem[k-1] = c;
            arr[(int)c] = k++;
        }


    cout << "Fill the Cayley table as per addition:" << endl;
    cout << "+ " ;
    for(int i = 0; i<n; i++)
        cout << elem[i] << " ";
    cout << endl;
    for(int i =1; i<=n; i++){
        cout << elem[i-1] << " ";
        for(int j = 1; j<=n; j++) {
            char temp;
            cin >> temp;
            add_table[i][j] = arr[(int)temp];
        }
    }


    cout << "Fill the Cayley table as per multiplication:" << endl;
    cout << "* ";
    for(int i = 0 ;i<n;i++)
        cout << elem[i] << " ";
    cout << endl;
    for(int i =1;i<=n;i++)
    {
        cout << elem[i-1] << " ";
        for(int j = 1;j<=n;j++)
        {
            char temp;
            cin >> temp;
            multi_table[i][j] = arr[(int)temp];
        }
    }
    if(is_ring(n))
        cout << "The given input is a ring";
    else
        cout << "The given input is not a ring";
    cout << "\n-----------------------------------------CODE BY : SHIVAM TYAGI ____ 2019UCO1725----------------------------------------";
    return 0;
}
