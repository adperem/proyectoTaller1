cmake_minimum_required(VERSION 3.23)
project(proyectoTaller1)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(proyectoTaller1
        include/AccelPointMass.h
        include/angl.h
        include/AzElPa.h
        include/Cheb3D.h
        include/EccAnom.h
        include/Frac.h
        include/LTC.h
        include/Matrix.h
        include/R_x.h
        include/R_y.h
        include/R_z.h
        src/Accel.cpp
        src/AccelPointMass.cpp
        src/angl.cpp
        src/AzElPa.cpp
        src/Cheb3D.cpp
        src/EccAnom.cpp
        src/Frac.cpp
        src/LTC.cpp
        src/Matrix.cpp
        src/R_x.cpp
        src/R_y.cpp
        src/R_z.cpp
        #test/Main.cpp
        #test/testFrac.cpp
        #test/testR_x.cpp
        #test/testR_y.cpp)
