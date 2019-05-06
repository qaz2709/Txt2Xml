file(GLOB hdrs_base "*.h")
file(GLOB src_base "*.c*")
file(GLOB hdrs ${hdrs_base})
file(GLOB srcs ${src_base})

ADD_LIBRARY(Ticpp ${srcs})
SET(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE "Debug")
#ADD_DEFINITIONS(-DTIXML_USE_TICPP)
