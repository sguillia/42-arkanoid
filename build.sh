git submodule add https://github.com/glfw/glfw
make -C arkanoid_src
echo "cd arkanoid_src && ./arkanoid" > ./arkanoid && chmod +x arkanoid &> /dev/null
