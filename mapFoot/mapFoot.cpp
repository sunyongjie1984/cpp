#include <map>
#include <string>
#include <iostream>
int main()
{
    std::map< std::string, int > word_count;
    // insert default initialzed element with key Anna; then assign 1 to its value
    std::map< std::string, int >::const_iterator itor = word_count.begin();
    itor = word_count.find( "Anna" );
    if ( word_count.end( ) == itor ) {
        std::cout << "can not find Anna" << std::endl;
    } else {
        std::cout << "Anna is found" << std::endl;
    }

    // we visit word_count[ "Anna" ], means we insert that element!!!!!
    std::cout << "the value of key Anna is " << word_count[ "Anna" ] << std::endl;;

    itor = word_count.find( "Anna" );
    if ( word_count.end( ) == itor ) {
        std::cout << "can not find Anna" << std::endl;
    } else {
        std::cout << "Anna is found" << std::endl;
    }
    word_count[ "Anna" ] = 1;
    std::cout << "the value of key Anna is " << word_count[ "Anna" ] << std::endl;;
    return 0;
}
