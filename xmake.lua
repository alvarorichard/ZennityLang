-- Define a target for your application
target("your_app_name")
    -- Set the kind of target, 'binary' for executable
    set_kind("binary")

    -- Add the source files
    -- If you have multiple source files, list them all separated by spaces,
    -- or use add_files("src/*.c") to include all .c files in the src directory
    add_files("your_program.c")

    -- Add dependencies, if you're using 'editline'
    add_packages("libedit")

    -- Set C language standard, if needed (e.g., c99, c11)
    set_languages("c99")

    -- Add any necessary compile flags, if specific flags are needed
    -- add_cflags("-Wall", "-Wextra", "-O2")

    -- Add link flags if there are any specific requirements
    -- add_ldflags("-ledit", {force = true})
