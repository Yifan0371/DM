# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/yifan/桌面/CHPS_M1/TD_CHALEUR/12_22/DM/build/_deps/googletest-src"
  "/home/yifan/桌面/CHPS_M1/TD_CHALEUR/12_22/DM/build/_deps/googletest-build"
  "/home/yifan/桌面/CHPS_M1/TD_CHALEUR/12_22/DM/build/_deps/googletest-subbuild/googletest-populate-prefix"
  "/home/yifan/桌面/CHPS_M1/TD_CHALEUR/12_22/DM/build/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/home/yifan/桌面/CHPS_M1/TD_CHALEUR/12_22/DM/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/home/yifan/桌面/CHPS_M1/TD_CHALEUR/12_22/DM/build/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/home/yifan/桌面/CHPS_M1/TD_CHALEUR/12_22/DM/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/yifan/桌面/CHPS_M1/TD_CHALEUR/12_22/DM/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/yifan/桌面/CHPS_M1/TD_CHALEUR/12_22/DM/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
