export module push_swap.error;

import std;

export struct InvalidInteger {
    std::string argument;
};

export struct IntegerOutOfRange {
    std::string argument;
};

export struct DuplicateValue {
    int value;
};

export struct UnknownOption {
    std::string option;
};

export struct EmptyBuffer {};

export struct OutputError {
    std::error_code cause;
};

export using Error =
    std::variant<InvalidInteger, IntegerOutOfRange, DuplicateValue,
                 UnknownOption, EmptyBuffer, OutputError>;

export template <class T> using Result = std::expected<T, Error>;
