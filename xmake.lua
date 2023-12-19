toolchain("ZennityLang_Toolchain")
    set_kind("standalone")

    set_toolset("cc", "clang")
    set_toolset("cxx", "clang++", "clang")
    set_toolset("ld", "clang", "clang++")
toolchain_end()

target("ZennityLang")
    set_targetdir("build")
    set_filename("prompt")

    set_kind("binary")

    -- TODO: In future, is better using globbing instead file to file
    add_includedirs("include")

    add_files("sources/conditionals.c")
    add_files("sources/doge_code.c")
    add_files("sources/mpc.c")
    add_files("sources/prompt.c")

    set_optimize("fastest")

    -- Add dependencies, if you're using 'editline'
    add_packages("libedit")

    -- Set C language standard, if needed (e.g., c99, c11)
    set_languages("c99")

    -- Add any necessary compile flags, if specific flags are needed
    add_cflags("-Wall", "-g")

    -- Add link flags if there are any specific requirements
    add_links("edit", "m")
