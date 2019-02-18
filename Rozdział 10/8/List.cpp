#include "pch.h"
#include "List.h"

using namespace std;

List::List () {
	size_of_ar = 0;
	arr [MaxSize] = 0;
}
void List::add (int Index, const int& newItem) {
	//for (int i =size_of_ar; i>= Index; i--)
	//arr[i]= arr[i-1];

	//for(int i= Index+1; i<= size_of_ar-1; i++ )
		//arr[i+1] = arr[i];

	arr [Index - 1] = newItem;
	size_of_ar++;
}
void List::remove (int index) {
	for ( int i = index + 1; i <= size_of_ar; i++ )
		arr [i - 2] = arr [i - 1];
	size_of_ar--;

}
void List::size ()const {
	cout << " wielkosc: " << size_of_ar << endl;
}
void List::show () const {

	cout << "Poczatek tablicy: ";
	for ( int i = 0; i < size_of_ar; i++ )
		cout << arr [i] << "->";
	cout << " : koniec tablicy.\n";
}