cmake_minimum_required(VERSION 2.8)
 
PROJECT(RelabSim)
 
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})
 
add_executable(RelabSim test.cpp Animate_poly.cpp Rx_vtk.cpp interactor.cpp make_cells.cpp new_vtk.cpp slice_chart.cpp)
 
if(VTK_LIBRARIES)
  target_link_libraries(RelabSim ${VTK_LIBRARIES})
else()
  target_link_libraries(RelabSim vtkHybrid)
endif()