# fetch the library
sudo apt-get install libgtest-dev

# mark current workspace directory
PROJ_DIR=$PWD

# install and unpack gtest files
sudo apt-get install cmake # install cmake
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
 
# copy or symlink libgtest.a and libgtest_main.a to your /usr/lib folder
sudo cp *.a /usr/lib

# navigate back to workspace
cd $PROJ_DIR

# Lets see if it works
make test