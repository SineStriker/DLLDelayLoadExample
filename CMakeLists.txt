cmake_minimum_required(VERSION 3.17)

project(DelayLoad)

macro(add_delayloab_flags flagsVar)    
    set(dlls "${ARGN}")
    foreach(dll ${dlls})
        get_filename_component(_name ${dll} NAME)
        set(${flagsVar} "${${flagsVar}} /DELAYLOAD:${_name}")
    endforeach()
endmacro()

add_executable(DelayLoad main.cpp)
target_include_directories(DelayLoad PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_compile_definitions(DelayLoad PRIVATE _UNICODE UNICODE)

# file(GLOB _libs ${CMAKE_CURRENT_SOURCE_DIR}/lib/*.lib)
# target_link_libraries(DelayLoad PRIVATE ${_libs})

# file(GLOB _dlls ${CMAKE_CURRENT_SOURCE_DIR}/lib/*.dll)
# add_delayloab_flags(CMAKE_EXE_LINKER_FLAGS ${_dlls})
add_delayloab_flags(CMAKE_EXE_LINKER_FLAGS avcodec-59.dll)