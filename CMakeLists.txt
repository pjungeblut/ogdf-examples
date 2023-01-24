cmake_minimum_required (VERSION 3.16)

project("OGDF Examples" LANGUAGES CXX)

# Compilation settings.
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "-Wall -O2")

# Paths to libraries for linker.
set(LIB_OGDF_PATH ${CMAKE_SOURCE_DIR}/../ogdf/libOGDF.a)
set(LIB_COIN_PATH ${CMAKE_SOURCE_DIR}/../ogdf/libCOIN.a)

# Where to find the includes.
include_directories(../ogdf/include)

# Needed for upward planar drawings.
find_package(Threads)

add_executable(edge source/edge.cpp)
target_link_libraries(edge ${LIB_OGDF_PATH})

add_executable(random_graph source/random_graph.cpp)
target_link_libraries(random_graph ${LIB_OGDF_PATH})

add_executable(tree source/tree.cpp)
target_link_libraries(tree ${CMAKE_SOURCE_DIR}/../ogdf/libOGDF.a)

add_executable(labeled_tree source/labeled_tree.cpp)
target_link_libraries(labeled_tree ${CMAKE_SOURCE_DIR}/../ogdf/libOGDF.a)

add_executable(shift_schnyder source/shift_schnyder.cpp)
target_link_libraries(shift_schnyder ${LIB_OGDF_PATH})

add_executable(embed source/embed.cpp)
target_link_libraries(embed ${LIB_OGDF_PATH})

add_executable(combinatorial_embedding source/combinatorial_embedding.cpp)
target_link_libraries(combinatorial_embedding ${LIB_OGDF_PATH})

add_executable(dual source/dual.cpp)
target_link_libraries(dual ${LIB_OGDF_PATH})

add_executable(stacked_triangulation source/stacked_triangulation.cpp)
target_link_libraries(stacked_triangulation ${LIB_OGDF_PATH})

add_executable(cubic_stellated source/cubic_stellated.cpp)
target_link_libraries(cubic_stellated ${LIB_OGDF_PATH})



# The OGFD methods for upward planarity use SAT solvers.
# Therefore COIN (a library related and shipped with OGDF) needs to be linked
# to the target as well. Moreover, COIN uses parallelism, so we have to link
# the threads library, too.
# If needed, uncomment the following line.
# target_link_libraries(upward ${LIB_OGDF_PATH} ${LIB_COIN_PATH} Threads::Threads)
