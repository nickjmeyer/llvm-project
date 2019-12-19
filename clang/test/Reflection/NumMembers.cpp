// RUN: %clang_cc1 -std=c++2a -verify %s

struct A
{
};

using A_R = decltype(A{});
