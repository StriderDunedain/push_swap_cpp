# push_swap 3.0

An unrestricted C++23 reimplementation of 42's `push_swap`.

This continues my
[`push_swap_v2.0`](https://github.com/StriderDunedain/push_swap_v2.0). Version 2.0
made sorting strategies declarative and interchangeable. I am using version 3.0 to
learn modern C++ without the restrictions of the original C subject.

## Generic strategies

Each sorting strategy will implement the same concept. A strategy receives compatible
stack and output types without depending on their concrete implementations.

Strategy metadata will contain the selector, name, complexity, and implementation.
Adding a strategy should only require implementing the concept and registering its
metadata.

The adaptive strategy will measure input disorder and select another registered
strategy. Selection and sorting remain separate.

## Data flow

```text
parse and validate input
  -> own the values
  -> measure disorder
  -> select a strategy
  -> emit operations through an output sink
```

## C++ design

- C++23 modules
- concepts for component contracts
- templates for stacks, strategies, and sinks
- explicit ownership and value semantics
- RAII for resource cleanup
- typed results instead of exceptions
- variants with exhaustive matching
- no global state
- no runtime class hierarchy

Input parsing produces an owning validated configuration. Borrowed data stays visibly
borrowed. Components do not take ownership of one another unless their type says so.

Sorting operations, diagnostics, and benchmark data use separate output sinks. The
sorting algorithms do not depend directly on stdout, stderr, files, or test collectors.

## Status

This is currently a compiling scaffold. The modules define the planned component
boundaries. Push_swap is not implemented yet.

## Usage

```sh
mise run build
mise run dev
mise run run
mise run format
mise run compiledb
mise run clean
```
