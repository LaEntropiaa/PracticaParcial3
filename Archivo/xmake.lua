add_rules("mode.debug", "mode.release")
set_languages("cxx23")

target("main")
set_kind("binary")
add_files("main.cpp")
