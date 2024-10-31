# Install script for directory: /home/edsiper/c/cprofiles/lib/cfl/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "headers" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/include/cfl/cfl.h;/usr/local/include/cfl/cfl_array.h;/usr/local/include/cfl/cfl_checksum.h;/usr/local/include/cfl/cfl_compat.h;/usr/local/include/cfl/cfl_found.h;/usr/local/include/cfl/cfl_hash.h;/usr/local/include/cfl/cfl_info.h;/usr/local/include/cfl/cfl_kv.h;/usr/local/include/cfl/cfl_kvlist.h;/usr/local/include/cfl/cfl_list.h;/usr/local/include/cfl/cfl_log.h;/usr/local/include/cfl/cfl_object.h;/usr/local/include/cfl/cfl_sds.h;/usr/local/include/cfl/cfl_time.h;/usr/local/include/cfl/cfl_utils.h;/usr/local/include/cfl/cfl_variant.h;/usr/local/include/cfl/cfl_version.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/include/cfl" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "/home/edsiper/c/cprofiles/lib/cfl/include/cfl/cfl.h"
    "/home/edsiper/c/cprofiles/lib/cfl/include/cfl/cfl_array.h"
    "/home/edsiper/c/cprofiles/lib/cfl/include/cfl/cfl_checksum.h"
    "/home/edsiper/c/cprofiles/lib/cfl/include/cfl/cfl_compat.h"
    "/home/edsiper/c/cprofiles/lib/cfl/include/cfl/cfl_found.h"
    "/home/edsiper/c/cprofiles/lib/cfl/include/cfl/cfl_hash.h"
    "/home/edsiper/c/cprofiles/lib/cfl/include/cfl/cfl_info.h"
    "/home/edsiper/c/cprofiles/lib/cfl/include/cfl/cfl_kv.h"
    "/home/edsiper/c/cprofiles/lib/cfl/include/cfl/cfl_kvlist.h"
    "/home/edsiper/c/cprofiles/lib/cfl/include/cfl/cfl_list.h"
    "/home/edsiper/c/cprofiles/lib/cfl/include/cfl/cfl_log.h"
    "/home/edsiper/c/cprofiles/lib/cfl/include/cfl/cfl_object.h"
    "/home/edsiper/c/cprofiles/lib/cfl/include/cfl/cfl_sds.h"
    "/home/edsiper/c/cprofiles/lib/cfl/include/cfl/cfl_time.h"
    "/home/edsiper/c/cprofiles/lib/cfl/include/cfl/cfl_utils.h"
    "/home/edsiper/c/cprofiles/lib/cfl/include/cfl/cfl_variant.h"
    "/home/edsiper/c/cprofiles/lib/cfl/include/cfl/cfl_version.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "headers" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/include/xxh3.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/include" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES "/home/edsiper/c/cprofiles/lib/cfl/lib/xxhash/xxh3.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "headers" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/include/xxhash.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/include" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES "/home/edsiper/c/cprofiles/lib/cfl/lib/xxhash/xxhash.h")
endif()

