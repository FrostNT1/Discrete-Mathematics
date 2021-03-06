#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

enum {AND,OR,NOT,IMP,IFF,CONST};

struct node {
	int type;
	int val;
	struct node *left,*right;
};

int var[256]={0},mem[17]={0},nvars=0;
struct node *exp;

void init()
{
	int i;
	for(i=0;i<256;i++)
		var[i]=0;
	for(i=0;i<17;i++)
		mem[i]=0;
	nvars=0;
	return;
}

bool eval(struct node *exp)
{
	if (exp==0)
	{
		//cout<<"null"<<endl;
		return false;
	}
	if (exp->type==CONST)
	{
		//cout<<"var "<<char(exp->val)<<endl;
		return mem[var[exp->val]];
	}
	if (exp->type==AND)
	{
		//cout<<"and"<<endl;
		return eval(exp->left)&&eval(exp->right);
	}
	if (exp->type==OR)
	{
		//cout<<"or"<<endl;
		return eval(exp->left)||eval(exp->right);
	}
	if (exp->type==NOT)
	{
		//cout<<"not"<<endl;
		return !eval(exp->left);
	}
	if (exp->type==IMP)
	{
		//cout<<"implies"<<endl;
		return (!eval(exp->left))||eval(exp->right);
	}
	if (exp->type==IFF)
	{
		//cout<<"iff"<<endl;
		return (eval(exp->left)&&eval(exp->right))||(!eval(exp->left)&&!eval(exp->right));
	}
}

struct node* genexp(char s[120], int *n)
{
	int n1=0,n2=0;
	struct node *exp=new node;

	if(s[0]==0)
	{
		*n=0;
		return 0;
	}

	switch(s[0])
	{
		case 'C':
			exp->type=AND;
			exp->left=genexp(s+1,&n1);
			exp->right=genexp(s+1+n1,&n2);
			break;
		case 'D':
			exp->type=OR;
			exp->left=genexp(s+1,&n1);
			exp->right=genexp(s+1+n1,&n2);
			break;
		case 'I':
			exp->type=IMP;
			exp->left=genexp(s+1,&n1);
			exp->right=genexp(s+1+n1,&n2);
			break;
		case 'E':
			exp->type=IFF;
			exp->left=genexp(s+1,&n1);
			exp->right=genexp(s+1+n1,&n2);
			break;
		case 'N':
			exp->type=NOT;
			exp->left=genexp(s+1,&n1);
			break;
		default:
			exp->type=CONST;
			exp->val=s[0];
			if(var[s[0]]==0)
				var[s[0]]=++nvars;
			break;
	}
	*n=1+n1+n2;
	return exp;
}

bool check(int n)
{
	int i;

	if(n==0)
	{
		//for(i=1;i<=nvars;i++) printf("%d ",mem[i]);printf("\n");
		return eval(exp);
	}

	mem[nvars-n+1]=0;
	if(check(n-1)==false)
		return false;

	mem[nvars-n+1]=1;
	if(check(n-1)==false)
		return false;

	return true;
}
void clear()
{
    //deallocate space
}
main()
{
    cout << "-----------------------------------------CODE BY : SHIVAM TYAGI ____ 2019UCO1725----------------------------------------\n";
    cout << "AND - C \t OR - D \t IMPLIES - I \t IF - E \t NOT - N \n";
    cout << "Enter expression is prefix order \n";
	char t[120];
	int n,tmp;
	cout << "Enter number of expressions to be tested" << endl;
	cin>>n;

	while(n--)
	{
	    cout << "Enter your Expression:" <<endl;
		cin>>t;
		init();
		exp=genexp(t,&tmp);
		if(check(nvars))
			cout<<"Is a Tautology"<<endl;
		else
        {
            // start
            int size = strlen(t);
            for(int i = size-1;i>=0;i--){
                t[i+1] = t[i];
            }
            t[0] = 'N';
            t[size+1] = '\0';
            // if you wanna print cout << "new expression " << t << endl;
            // change end
            exp=genexp(t, &tmp);
            if(check(nvars))
                cout << "Is a Contradiction"<< endl;
            else
                cout<<"Is a Contingency"<<endl;
        }
        clear();
	}
	cout << "-----------------------------------------CODE BY : SHIVAM TYAGI ____ 2019UCO1725----------------------------------------\n";
	return 0;
}
/*
7
IIpqDpNp
NCNpp
Iaz
NNNNNNNp
IIqrIIpqIpr
NIpp
Ezz
*/

