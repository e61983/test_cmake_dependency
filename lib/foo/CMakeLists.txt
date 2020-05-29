cmake_minimum_required(VERSION 3.5)

project( foo VERSION 1.0.0 LANGUAGES C DESCRIPTION "Foo library")

include(CMakePackageConfigHelpers)
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
    $<INSTALL_INTERFACE:inc/${prefix}>
    PRIVATE
        src
    )

configure_package_config_file(cmake/foo-config.cmake.in
    ${PROJECT_BINARY_DIR}/foo-config.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
    )

write_basic_package_version_file(${PROJECT_BINARY_DIR}/foo-config-version.cmake
    COMPATIBILITY SameMajorVersion
  )

install(TARGETS foo
    EXPORT foo-targets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/${prefix}/${CMAKE_BUILD_TYPE}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}/${prefix}/${CMAKE_BUILD_TYPE}/static
    )

install(FILES ${header_files} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${prefix}/foo)

install(FILES ${PROJECT_BINARY_DIR}/foo-config.cmake
    ${PROJECT_BINARY_DIR}/foo-config-version.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
    )

install(EXPORT foo-targets
    FILE foo-targets.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/${prefix}/cmake
    )

export(EXPORT foo-targets
    FILE ${CMAKE_CURRENT_BINARY_DIR}/foo-targets.cmake
    )

export(PACKAGE foo)
