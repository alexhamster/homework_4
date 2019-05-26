#include <iostream>
#include <type_traits>
#include <tuple>
#include <string>

namespace std {

    template<typename T >
    constexpr bool is_integral_v = is_integral<T>::value;

    template<typename T >
    constexpr bool is_compound_v = is_compound<T>::value;
}


namespace myFunc {

    // Using to check if the type is tuple or not
    template<typename T>
    struct IsTupleImpl : std::false_type {
    };

    template<typename... U>
    struct IsTupleImpl<std::tuple<U...>> : std::true_type {
    };

    template<typename T>
    constexpr bool is_tuple_v() {
        return IsTupleImpl<std::decay_t<T>>::value;
    }


    // Using to check, that tuple consists of the same types
    // Compare all types with the first one
    template <typename T, typename U, size_t i, typename V>
    struct is_one_of : std::false_type {};

    template <typename T, typename V>
    struct is_one_of<T, T, 1, V> : std::true_type {};

    template <typename T, size_t i, typename V>
    struct is_one_of<T, T, i, V> : is_one_of<typename std::tuple_element_t <0, V>,
            typename std::tuple_element_t<i, V>, i - 1, V> {};

    template <typename T, typename U, size_t i, typename V>
    constexpr bool is_one_of_v = is_one_of<T, U, i, V>::value;


    // Here i am trying to (write a bicycle) find out if the type is a std::string or not,
    // because std::to_string() can't work with std::string
    template <typename T>
    std::enable_if_t<std::is_compound_v<T>, std::string> all_to_sting (T t)
    {
        return t;
    }

    template <typename T>
    std::enable_if_t<std::is_integral_v<T>, std::string> all_to_sting (T t)
    {
        return std::to_string(t);
    }

    // Printing tuple (https://stackoverflow.com/a/31116392/11405954)
    template<class Tuple, std::size_t N>
    struct TuplePrinter {
        static void tuple_print(const Tuple& t)
        {
            TuplePrinter<Tuple, N-1>::tuple_print(t);
            std::cout << "." << std::get<N-1>(t);
        }
    };

    template<class Tuple>
    struct TuplePrinter<Tuple, 1> {
        static void tuple_print(const Tuple& t)
        {
            std::cout << std::get<0>(t);
        }
    };

    template<class... Args>
    void tuple_print(const std::tuple<Args...>& t)
    {
        TuplePrinter<decltype(t), sizeof...(Args)>::tuple_print(t);
        std::cout << "\n";
    }
}

template<typename T, bool is_integral, bool is_object, bool is_tuple>
struct print {}; // default case

template <typename T>
union byteview
{
    unsigned char b[sizeof(T)];
    T i;
};

template<typename T>
struct print<T, true, false, false> // integral types
{
    std::string operator()(const T& t)
    {
        byteview<T> bi;
        bi.i = t;

        std::string out_str = "";
        for(int i = sizeof(T)-1; i >= 0; --i)
        {
            out_str.append(std::to_string(bi.b[i]));
            if(i != 0)
                out_str.append(".");
        }
        std::cout << out_str << std::endl;
        return out_str;
    }
};

template<typename T>
struct print<T,false, true, false> // object types
{
    std::string operator()(const T& t)
    {
        std::string out_str = "";

        for (auto i = t.cbegin(); i != t.cend(); i++)
        {
            out_str.append(myFunc::all_to_sting(*i));
            if (i != t.cend())
                out_str.append(".");
        }
        out_str.pop_back(); // remove last '.'
        std::cout << out_str << std::endl;
        return out_str;
    }
};

template<typename T>
struct print<T, false, true, true> // valid tuple types
{
    using first_element_type = typename std::tuple_element_t<0,T>;
    using n_element_type = typename std::tuple_element_t<std::tuple_size<T>()-1,T>;
    constexpr static size_t n = std::tuple_size<T>() - 1;

    constexpr static bool is_valid_tuple = myFunc::is_one_of_v<
            first_element_type,
            n_element_type,
            n,
            T>;

    std::enable_if_t <is_valid_tuple, std::string> operator()(const T& t)
    {
        myFunc::tuple_print(t);
        return "";
    }
};

template <typename T>
std::string do_print(const T& t)
{
    static const bool is_integral = std::is_integral_v<T>;
    static const bool is_compound = std::is_compound_v<T>;
    static const bool is_tuple = myFunc::is_tuple_v<T>();
    return print<T, is_integral, is_compound, is_tuple>{}(t);
}
