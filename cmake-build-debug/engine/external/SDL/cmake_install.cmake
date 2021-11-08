# Install script for directory: /Users/paulmauviel/mauville/gamejam01/engine/external/SDL

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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/paulmauviel/mauville/gamejam01/cmake-build-debug/engine/external/SDL/libSDL2d.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2d.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2d.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2d.a")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/paulmauviel/mauville/gamejam01/cmake-build-debug/engine/external/SDL/libSDL2-2.0d.dylib")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2-2.0d.dylib" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2-2.0d.dylib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -x "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2-2.0d.dylib")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/paulmauviel/mauville/gamejam01/cmake-build-debug/engine/external/SDL/libSDL2maind.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2maind.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2maind.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2maind.a")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2/SDL2Targets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2/SDL2Targets.cmake"
         "/Users/paulmauviel/mauville/gamejam01/cmake-build-debug/engine/external/SDL/CMakeFiles/Export/lib/cmake/SDL2/SDL2Targets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2/SDL2Targets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2/SDL2Targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2" TYPE FILE FILES "/Users/paulmauviel/mauville/gamejam01/cmake-build-debug/engine/external/SDL/CMakeFiles/Export/lib/cmake/SDL2/SDL2Targets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2" TYPE FILE FILES "/Users/paulmauviel/mauville/gamejam01/cmake-build-debug/engine/external/SDL/CMakeFiles/Export/lib/cmake/SDL2/SDL2Targets-debug.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2" TYPE FILE FILES
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/SDL2Config.cmake"
    "/Users/paulmauviel/mauville/gamejam01/cmake-build-debug/SDL2ConfigVersion.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/SDL2" TYPE FILE FILES
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_assert.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_atomic.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_audio.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_bits.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_blendmode.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_clipboard.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_config_android.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_config_emscripten.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_config_iphoneos.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_config_macosx.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_config_minimal.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_config_os2.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_config_pandora.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_config_psp.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_config_windows.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_config_winrt.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_config_wiz.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_copying.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_cpuinfo.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_egl.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_endian.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_error.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_events.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_filesystem.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_gamecontroller.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_gesture.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_haptic.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_hidapi.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_hints.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_joystick.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_keyboard.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_keycode.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_loadso.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_locale.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_log.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_main.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_messagebox.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_metal.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_misc.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_mouse.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_mutex.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_name.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_opengl.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_opengl_glext.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_opengles.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_opengles2.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_opengles2_gl2.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_opengles2_gl2ext.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_opengles2_gl2platform.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_opengles2_khrplatform.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_pixels.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_platform.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_power.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_quit.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_rect.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_render.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_rwops.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_scancode.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_sensor.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_shape.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_stdinc.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_surface.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_system.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_syswm.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_test.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_test_assert.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_test_common.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_test_compare.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_test_crc32.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_test_font.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_test_fuzzer.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_test_harness.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_test_images.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_test_log.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_test_md5.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_test_memory.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_test_random.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_thread.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_timer.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_touch.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_types.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_version.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_video.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/SDL_vulkan.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/begin_code.h"
    "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/include/close_code.h"
    "/Users/paulmauviel/mauville/gamejam01/cmake-build-debug/engine/external/SDL/include/SDL_config.h"
    "/Users/paulmauviel/mauville/gamejam01/cmake-build-debug/engine/external/SDL/include/SDL_revision.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  
          execute_process(COMMAND /Users/paulmauviel/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/212.5457.51/CLion.app/Contents/bin/cmake/mac/bin/cmake -E create_symlink
            "libSDL2-2.0d.dylib" "libSDL2d.dylib"
            WORKING_DIRECTORY "/Users/paulmauviel/mauville/gamejam01/cmake-build-debug/engine/external/SDL")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "/Users/paulmauviel/mauville/gamejam01/cmake-build-debug/engine/external/SDL/libSDL2d.dylib")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/Users/paulmauviel/mauville/gamejam01/cmake-build-debug/engine/external/SDL/sdl2.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM FILES "/Users/paulmauviel/mauville/gamejam01/cmake-build-debug/engine/external/SDL/sdl2-config")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/aclocal" TYPE FILE FILES "/Users/paulmauviel/mauville/gamejam01/engine/external/SDL/sdl2.m4")
endif()

