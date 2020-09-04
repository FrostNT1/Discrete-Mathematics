#include<bits/stdc++.h>
using namespace std;
int grid[10][10];

void path(int node,bool visited[100],int n,int size,char c[100])
{
    c[size] = node + '0';
    size++;
    c[size] = '\0';
    for(int i = 0 ;i<size;i++)
        cout << c[i] << " ";
    cout << endl;
    visited[node] = 1;
    for(int i = 0;i<n;i++)
    {
        if(visited[i] == 0 && grid[node][i] == 1)
            {
                grid[node][i] = -1;
                path(i,visited,n,size,c);
                grid[node][i] = 1;
            }
    }
    size--;
    c[size] = '\0';
    visited[node] = 0;

}

void cycle(int node,bool visited[100],int n,int size,char c[100],int var)
{
    if(var == node && size!=0)
        {
            for(int i = 0;i<size;i++)
                cout << c[i] << " ";
            cout << var << endl;
            return ;
        }
    c[size] = node + '0';
    size++;
    c[size] = '\0';
    visited[node] = 1;
    for(int i = 0;i<n;i++)
        if((i == var || visited[i] == 0) && grid[node][i] == 1)
            {
                grid[node][i] = -1;
                cycle(i,visited,n,size,c,var);
                grid[node][i] = 1;
            }
    size--;
    c[size] = '\0';
    visited[node] = 0;

}


void pt_n_cy(int n)
{
    bool visited[100];
    char c[100];
    for(int i =0 ;i<100;i++)
        visited[i] = false;
    cout << "The paths are:" << endl;
    for(int i = 0;i<n;i++)
        path(i,visited,n,0,c);
    cout << "\nThe cycles are:" << endl;
    for(int i = 0 ; i<n; i++)
        {
            cycle(i,visited,n,0,c,i);
            visited[i] = 1;
        }
}

int main()
{
    cout << "-----------------------------------------CODE BY : SHIVAM TYAGI ____ 2019UCO1725----------------------------------------\n";
    int n;
    cout << "Enter the number of vertices in the graph ~ ";
    cin >> n;
    cout << "Fill in the matrix representation of the graph:" << endl;
    for(int i = 0 ;i<n;i++)
        for(int j =0 ;j<n;j++)
            cin >> grid[i][j];
    pt_n_cy(n);
    cout << "-----------------------------------------CODE BY : SHIVAM TYAGI ____ 2019UCO1725----------------------------------------\n";
    return 0;
}
