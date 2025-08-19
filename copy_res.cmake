file(GLOB_RECURSE _files LIST_DIRECTORIES false RELATIVE "${SRC}" "${SRC}/*")

foreach(_file ${_files})
    set(_src "${SRC}/${_file}")
    set(_dst "${DST}/${_file}")
    get_filename_component(_dir "${_dst}" DIRECTORY)

    if(NOT EXISTS "${_dir}")
        file(MAKE_DIRECTORY "${_dir}")
    endif()

    if(NOT EXISTS "${_dst}" OR "${_src}" IS_NEWER_THAN "${_dst}")
        message(STATUS "Updating: ${_file}")
        file(COPY "${_src}" DESTINATION "${_dir}")
    endif()
endforeach()