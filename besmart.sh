#!/bin/bash
# Created by Parker Cranfield 24/12/2023

PROJECT_NAME="RayLibTemplate"

while getopts 'sbrh' OPTION; do
  case "$OPTION" in
    s)
        echo "Attempting to installing dependancies..."
        sudo apt install build-essential git
        sudo apt install cmake
        sudo apt install libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev
        echo "Attempting to setup up Raylib..."
        git clone https://github.com/raysan5/raylib.git raylib
        cd raylib
        mkdir build && cd build
        cmake -DBUILD_SHARED_LIBS=OFF ..
        make
        sudo make install
        cd ../..
        echo "Setup complete!"
        echo "Do you want to remove the repo? (Y/n)"
        read input
        if [ "$input" = "Y" ] || [ "$input" = "y" ] || [ "$input" = "" ]; then
            rm -rf raylib
        fi
        ;;
    b)
        echo "Attempting to build/rebuild..."
        if [ ! -d "build" ]; then
            mkdir build
        else 
            rm -rf build
            mkdir build
        fi
        cd build
        cmake ..
        make
        cd ..
        ;;
    r)
        echo "Attempting to run..."

        ./build/$PROJECT_NAME
        ;;
    h)
        echo "script usage: $(basename $0) [-s] (Setup dependancies/raylib) [-b] (Build/rebuild) [-r] (Run)" >&2
        exit 1
        ;;
    ?)
        echo "script usage: $(basename $0) [-s] (Setup dependancies/raylib) [-b] (Build/rebuild) [-r] (Run)" >&2
        exit 1
        ;;
  esac
done
shift "$(($OPTIND -1))"