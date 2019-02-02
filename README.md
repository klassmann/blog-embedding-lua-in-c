# Blog Post - Embedding Lua in C
Here are all examples explained in my blog post.


## Requirements
- C Compiler (GCC or Clang)
- [CMake >= 2.8](https://gitlab.kitware.com/cmake/community/wikis/home)
- [Lua Development Library](https://www.lua.org/start.html#installing)


## How to Use

Inside the repository, create a `build` directory and change to the directory:
```sh
mkdir build
cd build
```

Inside `build` directory use `cmake` to generate de project files:

```sh
cmake ..
```

Inside build folder you will find the projects for your IDE ou building tools, in my case there is a `Makefile`:
```sh
make
```

After compiling you will find inside `build/examples` all examples ready for use.

You can find other `cmake` options [here](https://www.mankier.com/7/cmake-generators).


## License
MIT.