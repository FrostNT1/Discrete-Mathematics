#include <iostream>
using namespace std;

void Swap(char* a, char* b)
{
    // Swap the two characters found
    if (*a == *b)
        return;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
void rev(string& s, int l, int r)
{
    while (l < r)
        Swap(&s[l++], &s[r--]);
}

int bsearch(string& s, int l, int r, int key)
{
    //then find the smallest character on right of this character, which is greater than it
    int index = 0;
    while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (s[mid] <= key)
                r = mid - 1;
            else
            {
                l = mid + 1;
                if (index == 0 || s[index] >= s[mid])
                    index = mid;
            }
        }
    return index;
}

bool nxt_perm(string& s)
{
    //find the rightmost character, which is smaller than its next character
    //then find the smallest character on right of this character, which is greater than it
    int len = s.length(), i = len - 2;
    while (i >= 0 && s[i] >= s[i + 1])
        i--;
    if (i < 0)
        return false;
    else {
        int index = bsearch(s, i + 1, len - 1, s[i]);
        Swap(&s[i], &s[index]);
        //swapping swapped the whole index post; reverse the elements after the index swapped
        rev(s, i + 1, len - 1);
        return true;
    }
}

int main()
{
    cout << "-----------------------------------------CODE BY : SHIVAM TYAGI ____ 2019UCO1725----------------------------------------\n";
    string s;
    cout<<"Enter lexicographic order:\t";
    cin>>s;
    while(true)
    {
        bool val = nxt_perm(s);
    if (val == false)
    {
        cout << "No Word Possible" << endl;
        cout << "-----------------------------------------CODE BY : SHIVAM TYAGI ____ 2019UCO1725----------------------------------------\n";
        return 0;
    }
    else
        cout << s << endl;
    }

}
