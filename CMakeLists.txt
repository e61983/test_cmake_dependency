cmake_minimum_required(VERSION 2.8)

include(GNUInstallDirs)

project(Hello)
set(source_files
    main.c
    )

add_subdirectory(lib)

find_package(bar CONFIG REQUIRED)

add_executable(hello ${source_files})
target_link_libraries(hello PRIVATE bar)

install(TARGETS hello
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    )
