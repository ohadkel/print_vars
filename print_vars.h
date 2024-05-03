#pragma once
// PRINT_VARS: See usage example below.

#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/stringize.hpp>
#include <boost/preprocessor/tuple/to_seq.hpp>
#include <iostream>

#define PRINT_VAR(r, sep, elem) << (r == 2 ? "" : sep) << BOOST_PP_STRINGIZE(elem) << "=" << elem
#define PRINT_VARS(...) "" BOOST_PP_SEQ_FOR_EACH_R(1, PRINT_VAR, ", ", BOOST_PP_TUPLE_TO_SEQ((__VA_ARGS__)))

// int main() {
//     size_t a = 5;
//     auto b = 3.14;
//     auto c = 2.2;
//
//     // std::cout << PRINT_VARS() << std::endl; // Does not compile
//     std::cout << PRINT_VARS(a) << std::endl;
//     std::cout << PRINT_VARS(a, b) << std::endl;
//     std::cout << PRINT_VARS(a, b, c) << std::endl;
//     // output:
//     // a=5
//     // a=5, b=3.14
//     // a=5, b=3.14, c=2.2
//
//     return 0;
// }