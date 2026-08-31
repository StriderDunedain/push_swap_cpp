export module push_swap.operation;

import std;

export enum class Operation : std::uint8_t {
    sa,
    sb,
    ss,
    pa,
    pb,
    ra,
    rb,
    rr,
    rra,
    rrb,
    rrr,
};

export inline constexpr auto operation_count = std::size_t{11};

export struct OperationLog {
    std::vector<Operation> sequence;
    std::array<std::size_t, operation_count> counts{};
};
