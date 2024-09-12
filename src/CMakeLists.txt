link_directories(
    ${GTKMM_LIBRARY_DIRS}  )

include_directories(
    ${GTKMM_INCLUDE_DIRS}  )

set(SOURCE_FILES main.cpp data.cpp database.cpp)

# Un-comment to compile with debug sybols
# set(CMAKE_BUILD_TYPE Debug)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} sqlite3)
target_link_libraries(${PROJECT_NAME} ${GTKMM_LIBRARIES})
