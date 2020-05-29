cmake_minimum_required(VERSION 3.5)

project( bar VERSION 1.0.0 LANGUAGES C DESCRIPTION "Bar library")

include(GNUInstallDirs)

set(header_files
    inc/bar.h
    )

set(source_files
    src/bar.c
    )

find_package(foo 1.0.0 REQUIRED)

add_library(bar ${source_files} ${header_files})

target_link_libraries(bar PUBLIC foo)

set(prefix bar-${bar_VERSION})

target_include_directories( bar
    PUBLIC
    $<BUILD_INTERFACE:${bar_SOURCE_DIR}/inc>
    $<INSTALL_INTERFACE:inc/${prefix}>
    PRIVATE
        src
    )

install(TARGETS bar
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/${prefix}/${CMAKE_BUILD_TYPE}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}/${prefix}/${CMAKE_BUILD_TYPE}/static
    )

install(FILES ${header_files} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${prefix}/bar)
