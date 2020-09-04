#include <iostream>
#include <math.h>

using namespace std;

float r1,r2, d;
float x,y;

void quadratic(int a, int b, int c)
{

    float d=(b*b)-4*a*c;
    cout<<"d is: "<<d<<endl;
    if (d>=0)
    {
		r1=((-b)+(sqrt(d)))/(2*a);
	    r2=((-b)-(sqrt(d)))/(2*a);
    }
    else
    {
		r1=sqrt(b*b + d*(-1))/2;
		r2= atan(abs(sqrt(abs(d))/b));
	}
	cout<< "r1 and r2  "<<r1<<" "<<r2<<endl;
}

void initial_cond(int a, int b)
{
    //x+y=a
    //x*r1 + y*r2=b
    if((d>=0)&&(a!=b))
    {
        x=(b- a*r2)/(r1-r2);
        y=(a*r1-b)/(r1-r2);
	}
	else if(d>0)
	{
		x=a;
		y= (b-a*r1)/r1;
	}
	else
	{
		x=a;
		y=(b-(r1*a*cos(r2)))/(r1*(sin(r2)));
	}

}

void initial_one(int a, int b)
{
    //an=(a1+a2n)r0
    //a=xr
    //b=(xry)r
    x=a;
    y=(b/r1)-a;
}
int main()
{
    cout << "-----------------------------------------CODE BY : SHIVAM TYAGI ____ 2019UCO1725----------------------------------------\n";
    int f1,f2,d;
    int c1,c2;
    cout << "The recurrence relation is: F(n) = c1 * F(n - 1) + c2 * F(n - 2)\n";
    cout << "Enter c1 and c2\n";
    cin >> c1 >> c2;
    cout << "Enter initial conditions F(0) and F(1):\n";
    cin >> f1 >> f2;
    cout << "The recurrence relation is: F(n)= "<<c1<<" * F( n - 1) + "<<c2<<" * F(n-2)"<<endl;
    cout << "The initial condition is F(0) = "<<f1<< " and F(1) = "<<f2<<endl;
    cout << "Its characteristic equation is: r^2-("<< c1 <<") r-("<<c2<<")=0"<<endl;
    c1*=-1;
    c2*=-1;
    quadratic(1,c1,c2);
    d= c1*c1-4*c2;
    cout << "d is "<< d <<endl;
    if(d>=0)
    {
	    cout << "The roots of the characteristic equation are: r1 = "<<r1<<" and r2 = "<<r2<<endl;
	    cout << "The recursion patter stands if F(n) = a * (r1^n) + b * (r2^n)  for some n"<<endl;
	    cout << "The recursive function is: "<<endl;
	    if(r1!=r2)
	    {
	          initial_cond(f1,f2);
	          cout << "F(n) =  "<< x <<" * "<< r1 <<"^n + "<< y <<" * "<< r2 <<"^n\n";
	    }

	    else
	    {
	        initial_one(f1,f2);
	        cout <<" F(n) = ("<< x <<"*n + "<< y <<")* "<< r2 <<"^n\n";
		}
	}
	else
	{
    	cout << "The recursion patter stands if F(n)=a(r^n)cosx+b(r^n)sinx  for some n"<<endl;
    	cout << "The recursive function is: "<<endl;
    	initial_one(f1,f2);
    	cout<<"F(n) = "<< x <<" * "<<r1<<"^n * cos("<<r2<<") + "<< y <<" * "<< r1 <<"^n * sin("<< r2 <<")";
	}
	cout << "\n-----------------------------------------CODE BY : SHIVAM TYAGI ____ 2019UCO1725----------------------------------------";
    return 0;
}

