#ifndef FLARE_BASE_OVERLOADED_H_
#define FLARE_BASE_OVERLOADED_H_

namespace flare {

// This class helps you to create a functor that accepts different argument
// types, effectively create a "overloaded" version of lambda.
//
// Usage:
//
// std::visit(Overloaded{[](int) {},
//                       [](const std::string&) {},
//                       [](auto&&) { /* Catch all. */}},
//            some_variant);
//
// Note that you can only construct `Overloaded` with parentheses in C++20, in
// C++17 you need to use curly brackets to construct it.
template <class... Ts>
struct Overloaded : Ts... {
  using Ts::operator()...;
};

template <class... Ts>
Overloaded(Ts...) -> Overloaded<Ts...>;

}  // namespace flare

#endif  // FLARE_BASE_OVERLOADED_H_
