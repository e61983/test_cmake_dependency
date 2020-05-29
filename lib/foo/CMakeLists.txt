cmake_minimum_required(VERSION 3.5)

project( foo VERSION 1.0.0 LANGUAGES C DESCRIPTION "Foo library")

include(GNUInstallDirs)

set(header_files
    inc/foo.h
    )

set(source_files
    src/foo.c
    )

add_library(foo ${source_files} ${header_files})

set(prefix foo-${foo_VERSION})

target_include_directories( foo
    PUBLIC
    $<BUILD_INTERFACE:${foo_SOURCE_DIR}/inc>
    $<INSTALL_INTERFACE:inc/${prefix}
    PRIVATE
        src
    )

install(TARGETS foo
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/${prefix}/${CMAKE_BUILD_TYPE}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}/${prefix}/${CMAKE_BUILD_TYPE}/static
    )

install(FILES ${header_files} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${prefix}/foo)
