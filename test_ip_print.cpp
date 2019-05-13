#define BOOST_TEST_MODULE test_module
#include <boost/test/unit_test.hpp>
#include "print_ip.cpp"

BOOST_AUTO_TEST_SUITE(print_test_suite)

BOOST_AUTO_TEST_CASE(print_test_0)
{

    auto s1 = do_print(long(8875824491850138409));
    BOOST_CHECK(s1.compare("123.45.67.89.101.112.131.41") == 0);
}

BOOST_AUTO_TEST_CASE(print_test_1)
{
    std::vector<char> v2 = {1, 3, 7, 8, 2};
    auto s2 = do_print<std::vector<char>>(v2);
    BOOST_CHECK(s2.compare("1.3.7.8.2") == 0);
}

BOOST_AUTO_TEST_CASE(print_test_2)
{
    std::list<int> v2 = {13,54,34,64,344};
    auto s2 = do_print<std::list<int>>(v2);
    BOOST_CHECK(s2.compare("13.54.34.64.344") == 0);
}

BOOST_AUTO_TEST_CASE(print_test_3)
{
    std::vector<std::string> v2 = {"Hello, World!"};
    auto s2 = do_print<std::vector<std::string>>(v2);
    BOOST_CHECK(s2.compare("Hello, World!") == 0);
}

BOOST_AUTO_TEST_SUITE_END()