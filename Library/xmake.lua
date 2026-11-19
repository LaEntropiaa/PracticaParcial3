add_rules("mode.debug", "mode.release")
set_languages("cxx23")

add_requires("nlohmann_json")

target("main")
set_kind("binary")
add_files("main.cpp")
add_packages("nlohmann_json")
