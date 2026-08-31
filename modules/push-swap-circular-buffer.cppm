module;

#include <push_swap/macros.h>

export module push_swap.circular_buffer;

import std;

import push_swap.error;

export template <class T> class CircularBuffer {
  public:
    using value_type = T;
    using size_type = std::size_t;

    CircularBuffer() = default;
    explicit CircularBuffer(size_type capacity);

    [[nodiscard]] fn empty() const noexcept -> bool;
    [[nodiscard]] fn size() const noexcept -> size_type;
    [[nodiscard]] fn capacity() const noexcept -> size_type;

    fn front() -> T &;
    fn front() const -> const T &;
    fn back() -> T &;
    fn back() const -> const T &;

    fn push_front(T value) -> void;
    fn push_back(T value) -> void;
    fn pop_front() -> Result<T>;
    fn pop_back() -> Result<T>;

  private:
    fn grow() -> void;

    std::vector<std::optional<T>> slots_;
    size_type head_{};
    size_type size_{};
};
