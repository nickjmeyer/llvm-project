// RUN: %clang_cc1 -std=c++2a -verify %s

#include <reflect>

struct A
{
};

using A_R = reflexpr(decltype(A{}));
using A_R_T = std::reflect<A>;

template <class A, class B>
inline constexpr bool is_same_v{false};
template <class A>
inline constexpr bool is_same_v<A, A>{true};

static_assert(is_same_v<A_R, A_R_T>);
