#include <vector>
#include <list>
#include "ip_print.cpp"

int main()
{

    do_print<char>(char(-1));
    do_print<short>(short(0));
    do_print<int>(int(2130706433));
    do_print<long>(8875824491850138409);

    std::vector<int> v1 = {1,2,3,4,5};
    do_print<std::vector<int>>(v1);

    std::vector<char> v2 = {'1','3','7','8','2'};
    do_print<std::vector<char>>(v2);

    std::list<char> v3 = {'1','3','7','8','2'};
    do_print<std::list<char>>(v3);

    std::list<long> v4 = {213,324,654,346,546,234};
    do_print<std::list<long>>(v4);

    // the simplest way to print a string is a containing it like a first vector element
    std::vector<std::string> vstr1 = {"192.168.20.10"};
    do_print<std::vector<std::string>>(vstr1);

    std::list<std::string> vstr2 = {"10.0.0.1"};
    do_print<std::list<std::string>>(vstr2);

    auto tup1 = std::make_tuple<int>(192,168,20,10);
    do_print<decltype(tup1)>(tup1);

    auto tup2 = std::make_tuple<char>('h', 'e', 'l', 'l', 'o', '!');
    do_print<decltype(tup2)>(tup2);

    //auto tup3 = std::make_tuple<char, int, double, char>('h', 1, 4.5, 'l');
    //do_print<decltype(tup3)>(tup3);

    //auto tup4 = std::make_tuple<char, char, char, long>('f',1,3,4);
    //do_print<decltype(tup4)>(tup4);

    return 0;

}
