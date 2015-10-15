cmake_minimum_required(VERSION 3.3)

project(SimpleChess)

# Find SFML
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/deps/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
if(WIN32)
	find_package(SFML 2 REQUIRED COMPONENTS graphics window system audio network main)
else()
	find_package(SFML 2 REQUIRED COMPONENTS graphics window system audio network)
endif()

# SimpleChess
if(APPLE) # Application bundle if on an apple machine
	# Optionally build application bundle
	set(BUILD_APPBUNDLE FALSE CACHE BOOL "Build into OS x Application Bundle.")
	if(BUILD_APPBUNDLE)
		# Set bundle properties
		set(MACOSX_BUNDLE_BUNDLE_NAME SimpleChess)
		set(MACOSX_BUNDLE_INFO_STRING SimpleChess)
		set(MACOSX_BUNDLE_SHORT_VERSION_STRING 3.0)
		set(MACOSX_BUNDLE_BUNDLE_VERSION 3.0)
		set(MACOSX_BUNDLE_GUI_IDENTIFIER com.cplusplus.chesspp)

		# Throw all the resource paths into a variable
		file(GLOB_RECURSE SIMPLECHESS_RESOURCES
			${PROJECT_SOURCE_DIR}/res/*
			${PROJECT_SOURCE_DIR}/config/*
		)

		# Make sure each resource file gets put in the right directory
		# in the application bundle
		FOREACH(file ${SIMPLECHESS_RESOURCES})
			file(RELATIVE_PATH relPath ${PROJECT_SOURCE_DIR} ${file})
			string(FIND ${relPath} "/" inSubDirectory REVERSE)
			if(${inSubDirectory} GREATER 0)
				string(SUBSTRING ${relPath} 0 ${inSubDirectory} relDir)
				set(PACKAGE_LOCATION Resources/${relDir})
			else()
				set(PACKAGE_LOCATION Resources)
			endif()
			set_source_files_properties(${file}
				PROPERTIES
					MACOSX_PACKAGE_LOCATION ${PACKAGE_LOCATION}
			)
		ENDFOREACH()
		add_executable(SimpleChess MACOSX_BUNDLE
			"src/main.cpp"
		)
	endif()
endif()
if(NOT APPLE OR NOT BUILD_APPBUNDLE)
	# Copy resources to build directory if build directory is different from source directory.
	if(NOT ${CMAKE_CURRENT_BINARY_DIR} STREQUAL ${PROJECT_SOURCE_DIR})
		file(COPY config/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/config/)
		file(COPY res/	  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/res/)
		file(COPY log/	  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/log/)
	endif()
	if(WIN32)
		add_executable(SimpleChess WIN32
			"src/main.cpp"
		)
	else()
		add_executable(SimpleChess
			"src/main.cpp"
		)
	endif()
endif()
set_property(TARGET SimpleChess PROPERTY CXX_STANDARD 14)
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	if(APPLE)
		# Building with Clang (on OS x at least) requires -stdlib=libc++ flag
		set(CMAKE_CXX_FLAGS "-stdlib=libc++ ${CMAKE_CXX_FLAGS}")
		set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
	endif()
endif()
target_include_directories(SimpleChess PUBLIC
	"src/"
	${SFML_INCLUDE_DIR}
)
target_link_libraries(SimpleChess ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
if(SFML_STATIC_LIBRARIES)
	target_link_libraries(SimpleChess z bz2)
endif()

# options
if(WIN32)
	set(SIMPLECHESS_REDIRECT_OUTPUT_DEFAULT ON)
else()
	set(SIMPLECHESS_REDIRECT_OUTPUT_DEFAULT OFF)
endif()
option(SIMPLECHESS_REDIRECT_OUTPUT "Redirects output to files instead of stdout and stderr" ${SIMPLECHESS_REDIRECT_OUTPUT_DEFAULT})
if(SIMPLECHESS_REDIRECT_OUTPUT)
	target_compile_definitions(SimpleChess
		PRIVATE SIMPLECHESS_REDIRECT_OUTPUT
	)
endif()
include(CMakeDependentOption)
CMAKE_DEPENDENT_OPTION(SIMPLECHESS_TRUNC_LOGS "Truncate the log files at the start of the program" ON
	"SIMPLECHESS_REDIRECT_OUTPUT" ON
)
if(SIMPLECHESS_TRUNC_LOGS)
	target_compile_definitions(SimpleChess
		PRIVATE SIMPLECHESS_TRUNC_LOGS
	)
endif()

# Divvy out work to subdirectories
#add_subdirectory("src/")
