import std;
import defer;

auto main() -> int {
  auto fd = Defer{[](){ std::println("Printed after"); }};
  std::println("befor");

  return 0;
}
