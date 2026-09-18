module;
#include <concepts>
export module defer;

export template<std::invocable FUNC> class Defer {
  public:
    static constexpr Defer<FUNC> operator()(FUNC f) {
      return Defer{ f };
    }
    constexpr void cancel() {
      canceled = true;
    }
    constexpr ~Defer() { if(!canceled) f(); }
    
    Defer(FUNC f) : f(f) {};
    Defer(const Defer&) = delete;
    Defer(Defer&&) = default;
  private:
    FUNC f;
    bool canceled = false;
};
