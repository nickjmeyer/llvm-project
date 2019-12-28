// RUN: %clang_cc1 -std=c++2a -verify %s

#include <reflect>

struct A;

struct B;

template <class...>
struct C;

template <class... Ts>
using A_R = reflexpr(C<Ts...>);
using A_R_T = std::reflect<C<A, B>>;

template <class A, class B>
inline constexpr bool is_same_v{false};
template <class A>
inline constexpr bool is_same_v<A, A>{true};

static_assert(is_same_v<A_R<A, B>, A_R_T>);
