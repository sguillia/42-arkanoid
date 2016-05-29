git submodule add https://github.com/glfw/glfw
make -C arkanoid_src
ln -s arkanoid_src/arkanoid ./arkanoid
