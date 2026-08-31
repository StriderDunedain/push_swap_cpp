# push_swap 3.0

A modern C++ take on 42's `push_swap`, and a continuation of Maksim Trukhinov's
[`push_swap_v2.0`](https://github.com/StriderDunedain/push_swap_v2.0), built around
one idea:

> Describe the problem once, then let generic components decide how it is solved.

`push_swap` asks you to sort integers using two stacks and eleven allowed operations.
The original project is deliberately restricted C. Version 3.0 drops those restrictions
so Maksim can learn C++ by rebuilding the same problem for fun.

## Generic strategies

Version 2.0 made sorting strategies declarative and interchangeable. This version keeps
that design and plans to express the shared contract with concepts and templates.

A strategy should receive compatible stack and output types without knowing their
concrete storage or destination. Adding an algorithm should mean implementing the
contract and describing its metadata, not adding another special case throughout the
program.

```text
input
  -> validate and own values
  -> measure disorder
  -> select a compatible strategy
  -> emit operations through an output sink
```

## Ownership without surprises

Values own their resources, cleanup happens through RAII, and borrowed data remains
visibly borrowed. Components should compose without taking ownership of one another.
There are no global variables and no runtime hierarchy tying the algorithms together.

## Errors and output are values

The plan is to use no exceptions. Fallible operations return typed results, variants are
handled with exhaustive matching, and errors remain visible until the outer program
boundary.

Sorting operations, diagnostics, and benchmark data go through replaceable output
sinks. The algorithms therefore do not need to know about stdout, stderr, files, tests,
or any other destination.

## Why a third version?

The first version solved Push_swap. Version 2.0 explored interchangeable C strategies.
Version 3.0 is Maksim's C++ learning project: the same small problem, now used to play
with modules, concepts, templates, value semantics, RAII, and typed error handling
without the original subject restrictions.

The repository is only a compiling scaffold for now. Each module states the component
that could live there; the actual Push_swap implementation is still to come.

## Usage

```sh
mise run build
mise run run
```

Other development commands are available through `mise tasks`.
