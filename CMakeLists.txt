cmake_minimum_required(VERSION 3.16)
project(cevns_sim)

find_package(Geant4 REQUIRED ui_all vis_all)

include(${Geant4_USE_FILE})

message("HI")


# Include geant4 files
include_directories(${PROJECT_SOURCE_DIR}/src/DetectorGeometry)
include_directories(${PROJECT_SOURCE_DIR}/src/EventTypeHandler)
include_directories(${PROJECT_SOURCE_DIR}/src/EventTypes)
include_directories(${PROJECT_SOURCE_DIR}/src/PhysicalProcesses)

include_directories(${Geant4_INCLUDE_DIR})


# Add executable and link to Geant4 libraries
file(GLOB_RECURSE headers ${PROJECT_SOURCE_DIR}/src/*.hh)
file(GLOB_RECURSE sources ${PROJECT_SOURCE_DIR}/src/*.cc)

message("Headers are ${headers}")
message("Sources are ${sources}")

add_executable(cevns_sim cevns_sim.cc ${sources} ${headers})
target_link_libraries(cevns_sim ${Geant4_LIBRARIES})

# Copy scripts to build directory
set(cevns_sim_SCRIPTS
        vis.mac)

foreach(_script ${cevns_sim_SCRIPTS})
    message(_script)
    configure_file(
        ${PROJECT_SOURCE_DIR}/${_script}
        ${PROJECT_BINARY_DIR}/${_script}
        COPYONLY
    )
endforeach()

# install executable to bin
install(TARGETS cevns_sim DESTINATION bin)
