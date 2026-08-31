module;

#include <push_swap/macros.h>

export module push_swap.state;

import std;

import push_swap.operation;
import push_swap.stack;
import push_swap.strategy;

export struct Options {
    StrategyId strategy{StrategyId::adaptive};
    bool benchmark{};
    bool checker{};
};

export class PushSwap {
  public:
    explicit PushSwap(std::vector<int> values, Options options = {});

    fn apply(Operation operation) -> void;

    [[nodiscard]] fn sorted() const -> bool;
    [[nodiscard]] fn disorder() const noexcept -> double;
    [[nodiscard]] fn strategy() const noexcept -> const StrategyInfo &;
    [[nodiscard]] fn operations() const noexcept -> const OperationLog &;

    fn stack_a() noexcept -> Stack<int> &;
    fn stack_a() const noexcept -> const Stack<int> &;
    fn stack_b() noexcept -> Stack<int> &;
    fn stack_b() const noexcept -> const Stack<int> &;

  private:
    Stack<int> a_;
    Stack<int> b_;
    StrategyInfo strategy_;
    OperationLog operations_;
    double disorder_{};
    Options options_;
};
