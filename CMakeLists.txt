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
        include/Geodetic.h
        include/Globals.h
        include/SAT_Const.h
        include/Legendre.h
        include/IERS.h
        include/MeanObliquity.h
        include/Mjday.h
        include/Mjday_TDB.h
        include/NutAngles.h
        include/Position.h




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
        src/Geodetic.cpp
        src/EKF_GEOS3.cpp
        src/Globals.cpp
        src/IERS.cpp
        src/Legendre.cpp
        src/MeanObliquity.cpp
        src/Mjday.cpp
        src/Mjday_TDB.cpp
        src/NutAngles.cpp
        src/Position.cpp


        #test/testAzElPa.cpp
        #test/testCheb3D.cpp
        #test/testEccAnom.cpp
        #test/testAccelPointMass.cpp
        #test/Main.cpp
        #test/testFrac.cpp
        #test/testR_x.cpp
        #test/testR_y.cpp
        #test/testR_z.cpp
        #test/testGeodetic.cpp
        #test/testIERS.cpp
        #test/testLegendre.cpp
        #test/testMeanObliquity.cpp
        #test/testMjday.cpp
        #test/testMjday_TDB.cpp
        test/testPosition.cpp
        include/sign_.h
        src/sign_.cpp
        test/testSign_.cpp
        src/timediff.cpp
        include/timediff.h
        src/testTimediff.cpp


)
