#include <iostream>
using namespace std;

template <typename T>
class Set
{
private:
	T elem[50];
	int card;
public:
	Set();
	void insert(const T data);
    void del(const T data);
    int in_set(const T data) const;
	int cardinality() const;
	void display() const;
	const T* get_elem() const
	{
		const T* ptr = &elem[0];
		return ptr;
	}
};

template <typename T>
Set<T>::Set()
{
	for (int i = 0; i < 50; ++i)
		elem[i] = 0;
	card = 0;
}

template <typename T>
int Set<T>::in_set(const T data) const
{
	for (int i = 0; i < (card); ++i)
		if(elem[i]==data)
			return i;
	return -1;
}

template <typename T>
void Set<T>::insert(const T data)
{
	if (in_set(data)==-1)
	{
		elem[card] = data;
	    card++;
	}
}

template <typename T>
void Set<T>::del(const T data)
{
	if(card!=0)
	{
		int index = in_set(data);
		if(index!=-1)
		{
			for(int i = index; i< (card-2); ++i)
				elem[i] = elem[i+1];
			printf("%d successfully deleted from the set\n", data);
		}
		else
			printf("Element %d not present in set!\n", data);
	}

	else
		printf("Set is already empty!\n");
}


template <typename T>
int Set<T>::cardinality() const
{
	return card;
}

template <typename T>
void Set<T>::display() const
{
	if(card==0)
	{
		printf("\n");
		return;
	}
	for (int i = 0; i < card; ++i)
		cout<<elem[i]<<" ";
	printf("\n");
}

template <typename T>
Set<T> set_union(const Set<T> &set1, const Set<T> &set2)
{
	const T*ptr1 =nullptr, *ptr2 = nullptr;
	ptr1 = set1.get_elem();
	ptr2 = set2.get_elem();

	Set<T> set3;

	int n1 = set1.cardinality(), n2 = set2.cardinality();
	for (int i = 0; i < n1; ++i)
		set3.insert(ptr1[i]);

	for (int i = 0; i < n2; ++i)
		if(set3.in_set(ptr2[i])==-1)
			set3.insert(ptr2[i]);
	return set3;
}

template <typename T>
Set<T>intersection(const Set<T> &set1, const Set<T> &set2)
{
	const T*ptr1 =nullptr;
	ptr1 = set1.get_elem();

	Set<T> set3;

	int n1 = set1.cardinality();
	for (int i = 0; i < n1; ++i)
		if(set2.in_set(ptr1[i])!=-1)
			set3.insert(ptr1[i]);
	return set3;
}

template <typename T>
Set<T> difference(const Set<T> &set1, const Set<T> &set2)
{
	const T*ptr1 =nullptr;
	ptr1 = set1.get_elem();
	Set<T> set3;

	int n1 = set1.cardinality();

	for (int i = 0; i < n1; ++i)
		if(set2.in_set(ptr1[i])==-1)
			set3.insert(ptr1[i]);

	return set3;
}

template <typename T>
Set<T> sym_dif(const Set<T> &set1, const Set<T> &set2)
{
	Set<T> s1 = difference(set1, set2);
	Set<T> s2 = difference(set2, set1);
	return set_union(s1, s2);
}

template <typename T>
Set<T> set_add(const Set<T> &set1, const Set<T> &set2)
{
	const T*ptr1 =nullptr, *ptr2 = nullptr;
	ptr1 = set1.get_elem();
	ptr2 = set2.get_elem();

	Set<T> set3;

	int n1 = set1.cardinality(), n2 = set2.cardinality();

	for (int i = 0; i < n1; ++i)
		for (int j = 0; j < n2; ++j)
		{
			T temp = ptr1[i]+ptr2[j];
			set3.insert(temp);
		}
	return set3;
}

template <typename T>
Set<T> set_sub(const Set<T> &set1, const Set<T> &set2)
{
	const T*ptr1 =nullptr, *ptr2 = nullptr;
	ptr1 = set1.get_elem();
	ptr2 = set2.get_elem();

	Set<T> set3;

	int n1 = set1.cardinality(), n2 = set2.cardinality();

	for (int i = 0; i < n1; ++i)
		for (int j = 0; j < n2; ++j)
		{
			T temp = ptr1[i]-ptr2[j];
			set3.insert(temp);
		}
	return set3;
}

int main()
{
    cout << "-----------------------------------------CODE BY : SHIVAM TYAGI ____ 2019UCO1725----------------------------------------\n";
	Set<char> s1;
	Set<char> s2;
/*	char in;
	do
    {
        cout << "Enter characters for set1 \n";
        cin >> in;
        s1.insert(in);
    }
    while (in == -1);*/
    s1.insert('S');
	s1.insert('h');
	s1.insert('i');
	s1.insert('v');
	cout<<"Set 1 : ";
	s1.display();

	s2.insert('a');
	s2.insert('m');
	s2.insert('i');
	cout<<"Set 2 : ";
	s2.display();

	Set<char> s3 =intersection(s1, s2);
	cout << "The intersection of  set 1 and 2 is \n";
	s3.display();

	Set<char> s4 = set_union(s1, s2);
		cout << "The union of  set 1 and 2 is \n";
	s4.display();

	Set<char> s5 = difference(s1, s2);
		cout << "The difference of  set 1 and 2 is \n";
	s5.display();

	Set<char> s6 = sym_dif(s1, s2);
			cout << "The difference of  set 2 and 1 is \n";
	s6.display();

	Set<int> s7;
	s7.insert(1);
	s7.insert(2);
	s7.insert(3);
	cout << "Numeric set 1 \n";
	s7.display();

	Set<int> s8;
	s8.insert(99);
	s8.insert(100);
	s8.insert(0);
	cout << "Numeric set 2 \n";
	s8.display();

	Set<int> s9 = set_add(s7, s8);
	printf("\n");
	cout << "The addition of the sets given above is \n";
	s9.display();
	s9 = set_sub(s8, s7);
    cout << "The subtraction of the sets given above is (larger subtracted by smaller) \n";
	s9.display();
	cout << "-----------------------------------------CODE BY : SHIVAM TYAGI ____ 2019UCO1725----------------------------------------\n";
    return 0;
}
