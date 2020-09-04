#include <iostream>
using namespace std;

template <typename T>
struct element
{
	T data;
	int multiplicity;
};

template <typename T>
class MultiSet
{
private:
	element<T> elements[100];
	int cardinality;
public:
	MultiSet()
	{
        for (int i = 0; i < 100; ++i)
        {
            elements[i].data = 0;
            elements[i].multiplicity=0;
        }
        cardinality = 0;
    }


    void insert(const T d)
    {
        int index = in_set(d);
        if(index==-1)
        {
            elements[cardinality].data = d;
            elements[cardinality].multiplicity=1;
            cardinality++;
        }
        else
            elements[index].multiplicity++;
    }


	void insert(const T d, const int mltplcty)
	{
        if(mltplcty==0)
            return;

        int index = in_set(d);
        if(index==-1)
        {
            elements[cardinality].data = d;
            elements[cardinality].multiplicity = mltplcty;
            cardinality++;
        }
        else
            elements[index].multiplicity+= mltplcty;
    }


	int in_set(const T d) const;


	int card() const
	{
	    return cardinality;
	}


	void display() const
	{
        for (int i = 0; i < cardinality; i++)
            for (int j = 0; j < elements[i].multiplicity; j++)
                cout<<elements[i].data<<" ";
        printf("\n");
    }


	const element<T>* elem() const //return the address to the array of elements
	{
        const element<T>* ptr = elements;
        return ptr;
    }


	const int get_multiplicity(const T d) const //return multiplicity of d
        {
            int index = in_set(d);
            if(index==-1)
                return 0;
            else
                return elements[index].multiplicity;
        }


};
template <typename T>
int MultiSet<T>::in_set(const T d) const
{
	for (int i = 0; i < (cardinality); ++i)
		if(elements[i].data==d)
			return i;
	return -1;
}
template <typename T>
MultiSet<T> set_union(const MultiSet<T> &set1, const MultiSet<T> &set2)
{
	const element<T>*ptr1 =nullptr, *ptr2 = nullptr;
	ptr1 = set1.elem();
	ptr2 = set2.elem();

	MultiSet<T> set3;

	int n1 = set1.card(), n2 = set2.card();
	for (int i = 0; i < n1; i++)
	{
		int temp_mult= max(ptr1[i].multiplicity, set2.get_multiplicity(ptr1[i].data));
		set3.insert(ptr1[i].data, temp_mult);
	}
	for (int i = 0; i < n2; ++i)
		if(set3.in_set(ptr2[i].data)==-1)
			set3.insert(ptr2[i].data, ptr2[i].multiplicity);
	return set3;
}

template <typename T>
MultiSet<T> set_intersection(const MultiSet<T> &set1, const MultiSet<T> &set2)
{
	const element<T>*ptr1 =nullptr, *ptr2 = nullptr;
	ptr1 = set1.elem();
	ptr2 = set2.elem();

	MultiSet<T> set3;

	int n1 = set1.card();
	for (int i = 0; i < n1; ++i)
	{
		int temp_mult= min(ptr1[i].multiplicity, set2.get_multiplicity(ptr1[i].data));
		set3.insert(ptr1[i].data, temp_mult);
	}
	return set3;
}

template <typename T>
MultiSet<T> mset_add(const MultiSet<T> &set1, const MultiSet<T> &set2)
{
	const element<T>*ptr1 =nullptr, *ptr2 = nullptr;
	ptr1 = set1.elem();
	ptr2 = set2.elem();

	MultiSet<T> set3;

	int n1 = set1.card(), n2 = set2.card();
	for (int i = 0; i < n1; ++i)
	{
		int temp_mult= ptr1[i].multiplicity + set2.get_multiplicity(ptr1[i].data);
		set3.insert(ptr1[i].data, temp_mult);
	}
	for (int i = 0; i < n2; ++i)
		if(set3.in_set(ptr2[i].data)==-1)
			set3.insert(ptr2[i].data, ptr2[i].multiplicity);
	return set3;
}

template <typename T>
MultiSet<T> mset_dif(const MultiSet<T> &set1, const MultiSet<T> &set2)
{
	const element<T>*ptr1 =nullptr, *ptr2 = nullptr;
	ptr1 = set1.elem();
	ptr2 = set2.elem();

	MultiSet<T> set3;

	int n1 = set1.card(), n2 = set2.card();
	for (int i = 0; i < n1; ++i)
	{
		int temp_mult= max((ptr1[i].multiplicity-set2.get_multiplicity(ptr1[i].data)), 0);
		set3.insert(ptr1[i].data, temp_mult);
	}
	return set3;
}



int main()
{
    cout << "-----------------------------------------CODE BY : SHIVAM TYAGI ____ 2019UCO1725----------------------------------------\n";
	MultiSet<int> set1, set2, set3;
	set1.insert(1);
	set1.insert(1);
	set1.insert(1);
	set1.insert(3);
	set1.insert(4);
	set1.insert(4);
	cout << "The first multiset is \n";
	set1.display();

	set2.insert(1);
	set2.insert(1);
	set2.insert(3);
	set2.insert(3);
	set2.insert(2);
	cout << "The second multiset is \n";
	set2.display();

	set3 = set_union(set1, set2);
	cout << "The union of sets is \n";
	set3.display();
	set3 = set_intersection(set1, set2);
    cout << "The intersection of sets is \n";
	set3.display();
	set3 = mset_add(set1, set2);
	cout << "The set addition of the sets is \n";
	set3.display();
	set3 = mset_dif(set1, set2);
	cout << "The set difference of the sets is \n";
	set3.display();
	cout << "-----------------------------------------CODE BY : SHIVAM TYAGI ____ 2019UCO1725----------------------------------------\n";
	return 0;
}
