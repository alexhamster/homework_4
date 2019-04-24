#include <iostream>
#include <vector>
#include <list>
#include <type_traits>
#include <tuple>

namespace myFunc {

// IsTuple<T>()
    template<typename T>
    struct IsTupleImpl : std::false_type {
    };

    template<typename... U>
    struct IsTupleImpl<std::tuple<U...>> : std::true_type {
    };

    template<typename T>
    constexpr bool is_tuple() {
        return IsTupleImpl<std::decay_t<T>>::value;
    }

    template <typename T, typename U, size_t S, typename V>
    struct is_one_of : std::false_type {};

    template <typename T, typename V>
    struct is_one_of<T,T,1,V> : std::true_type {};

    template <typename T, typename V>
    struct is_one_of<T,T,0,V> : std::true_type {};

    template <typename T, size_t S, typename V>
    struct is_one_of<T,T,S,V> : is_one_of<typename std::tuple_element<0,V>::type,
            typename std::tuple_element<S,V>::type, S-1, V> {};


}

template<typename T, size_t S, bool is_integral, bool is_object, bool is_tuple>
struct print // default case
{
    const static int method = 0;
    void operator()(T t)
    {
        std::cout << "Printing NOTHING" << std::endl;
    }
};

template<typename T, size_t S>
struct print<T, S, true, false, false> // integral types
{
    const static int method = 1;
    void operator()(T t)
    {
        std::cout << "Printing integral" << std::endl;
    }
};

template<typename T, size_t S>
struct print<T, S, false, true, false> // object types
{
    const static int method = 2;
    void operator()(T t)
    {
        std::cout << "Printing object" << std::endl;
    }
};

template<typename T, size_t len>
struct print<T, len, false, true, true> // valid tuple types
{
    const static int method = 3;
    std::enable_if_t <myFunc::is_one_of<
            typename std::tuple_element<0,T>::type,
            typename std::tuple_element<len-1,T>::type,
            len-1,
            T>::value, void> operator()(T t)
    {
        std::cout << "Printing valid tuple" << std::endl;
    }
};

template <typename T, size_t len>
void do_print(T t)
{
    static const bool is_integral = std::is_integral<T>::value;
    static const bool is_compound = std::is_compound<T>::value;
    static const bool is_tuple = myFunc::is_tuple<T>();

    /*
    bool is_valid_tuple = myFunc::is_one_of<
            typename std::tuple_element<0,T>::type,
            typename std::tuple_element<len,T>::type,
            len,
            T>::value;
    */

    print<T, len, is_integral, is_compound, is_tuple>{}(t);
}

int main()
{
    auto t1 = std::make_tuple(1,2,3,4);
    auto t2 = std::make_tuple('1',4.5,"he43lo","hl23lo");
    std::vector<int> t = {1,2,3,4};

    int a = 12345;
    std::cout << sizeof(decltype(t2)) << std::endl;
    do_print<decltype(t1),sizeof(t1)/ sizeof(int)>(t1);



}
