set_project("push_swap_cpp")
set_version("3.0.0")
set_languages("c++23")
set_toolchains("clang")

add_rules("mode.debug", "mode.release")
set_policy("build.across_targets_in_parallel", true)

set_warnings("all", "extra")
add_cxxflags("-Wpedantic", "-Wconversion", "-Wshadow", { tools = { "gcc", "clang" } })

target("push_swap")
set_kind("binary")
set_targetdir(".")
add_files("modules/*.cppm", { public = true })
add_files("src/main.cpp")
add_includedirs("include")
add_headerfiles("include/(push_swap/*.h)")
