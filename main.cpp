#include <vector>
#include <list>
#include "print_ip.cpp"

int main()
{

    do_print(char(-1));
    do_print(short(0));
    do_print(int(2130706433));
    do_print(long(8875824491850138409));

    std::vector<int> v1 = {1,2,3,4,5};
    do_print(v1);

    std::vector<char> v2 = {22,3,7,8,2};
    do_print(v2);

    std::list<char> v3 = {4,7,45,124,12};
    do_print(v3);

    std::list<long> v4 = {23,32,64,34,56,2};
    do_print(v4);

    // the simplest way to print a string is a containing it like a first vector element
    std::vector<std::string> vstr1 = {"192.168.20.10"};
    do_print(vstr1);

    std::list<std::string> vstr2 = {"10.0.0.1"};
    do_print(vstr2);

    auto tup1 = std::make_tuple<int>(192,168,20,10);
    do_print(tup1);

    auto tup2 = std::make_tuple<char>('h', 'e', 'l', 'l', 'o', '!');
    do_print(tup2);

    //auto tup3 = std::make_tuple<char, int, double, char>('h', 1, 4.5, 'l');
    //do_print<decltype(tup3)>(tup3);

    //auto tup4 = std::make_tuple<char, char, char, long>('f',1,3,4);
    //do_print<decltype(tup4)>(tup4);

    return 0;

}
