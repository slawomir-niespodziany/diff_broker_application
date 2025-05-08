# Example application *Broker*
This repo consists of main module for the application *Broker*. Full example description can be found in *[diff_broker](https://github.com/slawomir-niespodziany/diff_broker)* repo, which aggregates this module and all the other components required by it. 

## Description
Main module links to other components within the example and composes an executable. Its internal implementation is minimalistic. It executes several framework functionalities to load topology from a json file and instantiate components. It accesses selected components via the framework to perform selected operations on the components themselves - process all the processable components in this examples case.

See the *[main.cpp](src/main.cpp)* file for more details.

## Prerequisites
The example has been prepared and tested on Ubuntu 22.04 and Ubuntu 24.04. That being said, you only need *gcc* and *cmake* to build and install this component. The recent versions (incl. *cmake 4.0.1*) can be downloaded using following commands. 
```
sudo apt -y install build-essential
sudo snap install cmake --classic
```

## Build, Installation, Testing
The binary requires all the components of *[diff_broker](https://github.com/slawomir-niespodziany/diff_broker)* to be installed in CMake registry. Please refer to its repo for installation guide.

#### Install & run by script
Run the following command from component directory to build and run the binary.
```
./build.sh
```

#### Build & install by hand
Run the following commands from component directory to build the binary. 
```
cmake -Bbuild
cmake --build build
```

#### Run by hand
Execute the following command from component directory to run the binary. 
```
./build/application
```
*Search path for the topology file is relative. For this reason the binary needs to be run from the main component directory.*
