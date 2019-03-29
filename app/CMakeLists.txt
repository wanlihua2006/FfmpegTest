# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

#set(distribution_DIR ${CMAKE_SOURCE_DIR}/libs)            # 文件夹为libs的情况下
set(distribution_DIR ${CMAKE_SOURCE_DIR}/src/main/jniLibs) # 文件夹为jniLibs的情况下
message("distribution_DIR:" ${distribution_DIR})

add_library( libavcodec
        SHARED
        IMPORTED )

add_library( libavdevice
        SHARED
        IMPORTED )

add_library( libavfilter
        SHARED
        IMPORTED )

add_library( libavformat
        SHARED
        IMPORTED )

add_library( libavutil
        SHARED
        IMPORTED )

add_library( libpostproc
        SHARED
        IMPORTED )

add_library( libswresample
        SHARED
        IMPORTED )

add_library( libswscale
        SHARED
        IMPORTED )

set_target_properties( libavcodec
        PROPERTIES IMPORTED_LOCATION
        ${distribution_DIR}/${ANDROID_ABI}/libavcodec.so)

set_target_properties( libavdevice
        PROPERTIES IMPORTED_LOCATION
        ${distribution_DIR}/${ANDROID_ABI}/libavdevice.so)

set_target_properties( libavfilter
        PROPERTIES IMPORTED_LOCATION
        ${distribution_DIR}/${ANDROID_ABI}/libavfilter.so)

set_target_properties( libavformat
        PROPERTIES IMPORTED_LOCATION
        ${distribution_DIR}/${ANDROID_ABI}/libavformat.so)

set_target_properties( libavutil
        PROPERTIES IMPORTED_LOCATION
        ${distribution_DIR}/${ANDROID_ABI}/libavutil.so)

set_target_properties( libpostproc
        PROPERTIES IMPORTED_LOCATION
        ${distribution_DIR}/${ANDROID_ABI}/libpostproc.so)

set_target_properties( libswresample
        PROPERTIES IMPORTED_LOCATION
        ${distribution_DIR}/${ANDROID_ABI}/libswresample.so)

set_target_properties( libswscale
        PROPERTIES IMPORTED_LOCATION
        ${distribution_DIR}/${ANDROID_ABI}/libswscale.so)

add_library(  # Sets the name of the library.
        native-lib
        SHARED
        ${CMAKE_SOURCE_DIR}/src/main/cpp/native-lib.c) 

find_library(
        log-lib
        log)

include_directories(src/main/cpp/include)

target_link_libraries( # Specifies the target library.
        native-lib
        libavcodec
        libavdevice
        libavfilter
        libavformat
        libavutil
        libpostproc
        libswresample
        libswscale
        android #如果我们在编写代码时使用了ANativeWindow相关的方法的话，需要在链接库文件的时候加入android这个库文件，不然会报undefined reference to的错
        ${log-lib} )
