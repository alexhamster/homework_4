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
    struct is_one_of<T,T,0,V> : std::true_type {};

    template <typename T, size_t S, typename V>
    struct is_one_of<T,T,S,V> : is_one_of<typename std::tuple_element<0,V>::type,
            typename std::tuple_element<S,V>::type, S-1, V> {};
}

template<typename T, size_t S, bool is_integral, bool is_object, bool is_tuple, bool is_valid_tuple>
struct print // default case
{
    const static int method = 0;
};

template<typename T, size_t S>
struct print<T, S, true, false, false, false> // integral types
{
    const static int method = 1;
};

template<typename T, size_t S>
struct print<T, S, false, true, false, false> // object types
{
    const static int method = 2;
};

template<typename T, size_t S>
struct print<T, S, false, true, true, true> // valid tuple types
{
    const static int method = 3;
};

template <typename T, size_t len>
void do_print()
{
    bool is_integral = std::is_integral<T>::value;
    bool is_object = std::is_object<T>::value;
    bool is_tuple = myFunc::is_tuple<T>();
    bool is_valid_tuple = myFunc::is_one_of<
            typename std::tuple_element<0,T>::type,
            typename std::tuple_element<len,T>::type,
            len,
            T>::value;

    std::cout << is_tuple << std::endl;
    std::cout << is_valid_tuple << std::endl;
}

int main()
{
    auto t1 = std::make_tuple(1,2,3,4);
    auto t2 = std::make_tuple('1',"hello","hello","hello");
    std::vector<int> t = {1,2,3,4};

    do_print<decltype(t2),3>();

    //todo вызывать валидацию для тьюплов только для тьюплов

}
