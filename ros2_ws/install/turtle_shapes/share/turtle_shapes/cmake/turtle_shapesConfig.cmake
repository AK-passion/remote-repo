# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_turtle_shapes_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED turtle_shapes_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(turtle_shapes_FOUND FALSE)
  elseif(NOT turtle_shapes_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(turtle_shapes_FOUND FALSE)
  endif()
  return()
endif()
set(_turtle_shapes_CONFIG_INCLUDED TRUE)

# output package information
if(NOT turtle_shapes_FIND_QUIETLY)
  message(STATUS "Found turtle_shapes: 0.0.0 (${turtle_shapes_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'turtle_shapes' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${turtle_shapes_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(turtle_shapes_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${turtle_shapes_DIR}/${_extra}")
endforeach()
