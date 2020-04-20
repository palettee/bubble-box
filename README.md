# bubble-box

    git submodule init
    git submodule update

    cd googletest
    git checkout release-1.8.1

    cd googletest
    mkdir build
    cd build
    cmake ..
    make

    cd ../
    cd googlemock
    mkdir build
    cd build
    camke ..
    make

    cd ../../
    make unit_test

    make all
