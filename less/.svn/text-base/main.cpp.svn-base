// functional_less.cpp
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <iostream>

int main( )
{
    using namespace std;
    vector <int> v1;
    vector <int>::iterator Iter1;
    vector <int>::reverse_iterator rIter1;

    int i;
    for ( i = 0 ; i < 7 ; i++ )
    {
        v1.push_back( rand( ) );
    }

    cout << "Original vector v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")" << endl;

    // To sort in ascending order,
    // use the (default) binary predicate less<int>( )
    sort( v1.begin( ), v1.end( ), less<int>( ) );
    // could have written simply: sort( v1.begin( ), v1.end( ) );
    cout << "Sorted vector v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")" << endl;
    return 0;
}
