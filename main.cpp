#include <format>
#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::format;
using std::invalid_argument;

const int MAX_FACTORIAL_INPUT = 20;

template <typename T> T factorial(T num) {

  if (num > MAX_FACTORIAL_INPUT) {
    throw invalid_argument(format(
        "Number {} is too large for factorial. Input must be between 0 and {}",
        num, MAX_FACTORIAL_INPUT));
  }

  if ((num == 0) || (num == 1)) {
    return 1;
  }

  T result = 1;
  for (T i = 2; i <= num; ++i) {
    result *= i;
  }
  return result;
}

int main() {
  try {
    auto num = 0;
    cout << "Please enter a positive number: ";
    cin >> num;

    if (num < 0) {
      throw invalid_argument("Number must be positive");
    }

    const auto result = factorial<int>(num);
    cout << format("The factorial of {} is: {}\n", num, result);
  } catch (const invalid_argument &e) {
    cout << "Error: " << e.what() << "\n";
  } catch (...) {
    cout << "Error: Unknown error\n";
  }

  return 0;
}