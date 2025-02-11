# Install script for directory: D:/myGitHub/C++/AwesomeC/CMake

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/CMake")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/Qt/Tools/mingw1310_64/bin/objdump.exe")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("D:/myGitHub/C++/AwesomeC/CMake/cmake-build-debug-mingw/lib/staticLibrary/cmake_install.cmake")
  include("D:/myGitHub/C++/AwesomeC/CMake/cmake-build-debug-mingw/lib/dynamicLibrary/cmake_install.cmake")
  include("D:/myGitHub/C++/AwesomeC/CMake/cmake-build-debug-mingw/lib/01.CLanguageEnvLib/cmake_install.cmake")
  include("D:/myGitHub/C++/AwesomeC/CMake/cmake-build-debug-mingw/lib/02.CTypeLib/cmake_install.cmake")
  include("D:/myGitHub/C++/AwesomeC/CMake/cmake-build-debug-mingw/lib/03.StatementsLib/cmake_install.cmake")
  include("D:/myGitHub/C++/AwesomeC/CMake/cmake-build-debug-mingw/lib/04.ArrLib/cmake_install.cmake")
  include("D:/myGitHub/C++/AwesomeC/CMake/cmake-build-debug-mingw/lib/05.FunLib/cmake_install.cmake")
  include("D:/myGitHub/C++/AwesomeC/CMake/cmake-build-debug-mingw/lib/06.PointerLib/cmake_install.cmake")
  include("D:/myGitHub/C++/AwesomeC/CMake/cmake-build-debug-mingw/lib/07.MemoryLib/cmake_install.cmake")
  include("D:/myGitHub/C++/AwesomeC/CMake/cmake-build-debug-mingw/lib/08.CompositeTypeLib/cmake_install.cmake")
  include("D:/myGitHub/C++/AwesomeC/CMake/cmake-build-debug-mingw/lib/09.FileLib/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_COMPONENT MATCHES "^[a-zA-Z0-9_.+-]+$")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
  else()
    string(MD5 CMAKE_INST_COMP_HASH "${CMAKE_INSTALL_COMPONENT}")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INST_COMP_HASH}.txt")
    unset(CMAKE_INST_COMP_HASH)
  endif()
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
  file(WRITE "D:/myGitHub/C++/AwesomeC/CMake/cmake-build-debug-mingw/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
