#include <iostream>
using namespace std;

bool refl(const bool relation_matrix[10][10], const int &var)
{
	//The relation is reflexive if diagonals are 1
	for (int i = 0; i < var; ++i)
		if(relation_matrix[i][i]==0)
			return false;
    return true;
}

bool sym(const bool relation_matrix[10][10], const int &var)
{
	//The relation is symmetric if elements of R are equal to elements of R transpose
	for (int i = 0; i < var; ++i)
		for (int j = 0; j < var; ++j)
			if(relation_matrix[i][j] != relation_matrix[j][i])
                return false;
    return true;
}

bool trans(const bool relation_matrix[10][10], const int &var)
{
    //The relation is transitive if the squared matrix has 1 where the original had a 0
	bool sq_matx[10][10] = {};
	for (int i = 0; i < var; ++i)
		for (int j = 0; j < var; ++j)
		{
			sq_matx[i][j] = false;
			for (int k = 0; k < var; k++)
				sq_matx[i][j] += relation_matrix[i][k] * relation_matrix[k][j];
		}
	for (int i = 0; i < var; ++i)
		for (int j = 0; j < var; ++j)
			if(((relation_matrix[i][j])==false) and (sq_matx[i][j]==true))
				return false;
	return true;
}

int main()
{
    cout << "-----------------------------------------CODE BY : SHIVAM TYAGI ____ 2019UCO1725----------------------------------------\n";
	bool relation_matrix[10][10] = {};
	int var = 0;

	cout << "What is the number of elements in the set on which you have defined the relation R ?" << endl;
	cin >> var;

	cout << "Enter the matrix notation of the relation" << endl;
	for (int n = 0; n < var; n++)
		for (int m = 0; m < var ;m++)
			cin>>relation_matrix[n][m];

    bool reflexivity = refl(relation_matrix, var);
	bool transitivity = trans(relation_matrix, var);
	bool symmetry = sym(relation_matrix, var);

	if(reflexivity)
        cout << "The relation is reflexivity" <<endl;
    else
        cout << "The relation is not reflexivity"<< endl;

    if(transitivity)
        cout << "The relation is transitivity" <<endl;
    else
        cout << "The relation is not transitivity"<< endl;

	if(symmetry)
        cout << "The relation is symmetric" <<endl;
    else
        cout << "The relation is not symmetric"<< endl;

	if(symmetry and reflexivity and transitivity)
		cout<<"Thus, R is an Equivalence relation" ;
	else
        cout<<"Thus, R is not an Equivalence relation" ;
    cout << "\n-----------------------------------------CODE BY : SHIVAM TYAGI ____ 2019UCO1725----------------------------------------";
}
