#global compile options

add_compile_options(-Wall -g -Werror -Wl,-whole-archive)
set(LINK_FLAGS ${LINK_FLAGS} "-Wl,-whole-archive")