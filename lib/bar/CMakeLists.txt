cmake_minimum_required(VERSION 3.5)

project( bar VERSION 1.0.0 LANGUAGES C DESCRIPTION "Bar library")

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

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

configure_package_config_file(cmake/bar-config.cmake.in
    ${PROJECT_BINARY_DIR}/bar-config.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
    )

write_basic_package_version_file(${PROJECT_BINARY_DIR}/bar-config-version.cmake
    COMPATIBILITY SameMajorVersion
  )

install(TARGETS bar
    EXPORT bar-targets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/${prefix}/${CMAKE_BUILD_TYPE}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}/${prefix}/${CMAKE_BUILD_TYPE}/static
    )

install(FILES ${header_files} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${prefix}/bar)

install(EXPORT bar-targets
    FILE bar-targets.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/${prefix}/cmake
    )

export(EXPORT bar-targets
    FILE ${CMAKE_CURRENT_BINARY_DIR}/bar-targets.cmake
    )

export(PACKAGE bar)
