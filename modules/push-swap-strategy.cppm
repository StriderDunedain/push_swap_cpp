export module push_swap.strategy;

import std;

export enum class StrategyId : std::uint8_t {
    simple,
    medium,
    complex,
    adaptive,
};

export struct StrategyInfo {
    StrategyId id;
    std::string_view flag;
    std::string_view name;
    std::string_view complexity;
};
