module;

#include <push_swap/macros.h>

export module push_swap.stack;

import std;

export template <class T> class Stack {
  public:
    using value_type = T;
    using size_type = std::size_t;

    Stack() = default;
    explicit Stack(std::deque<T> values);

    [[nodiscard]] fn empty() const noexcept -> bool;
    [[nodiscard]] fn size() const noexcept -> size_type;

    fn top() -> T &;
    fn top() const -> const T &;

    fn push(T value) -> void;
    fn pop() -> std::optional<T>;
    fn swap_top() -> void;
    fn rotate() -> void;
    fn reverse_rotate() -> void;

    fn values() const noexcept -> const std::deque<T> &;

  private:
    std::deque<T> values_;
};
