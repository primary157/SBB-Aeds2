cmake_minimum_required(VERSION 3.7)
project(sbb)
set(SBB_FILES SBB.c SBBComArquivo.c SBBTrab.c )
add_library(sbb SBB.c SBBComArquivo.c SBBTrab.c )
add_executable(runsbb main.c)
target_link_libraries(runsbb sbb)

install(TARGETS runsbb RUNTIME DESTINATION bin)
