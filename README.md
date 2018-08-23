# meson-cpp-skel
Skeleton :skull: project for C++ (or C) using [Meson](https://github.com/mesonbuild/meson)

### Build for current machine
 - Make build directory ```mkdir build``` and ```cd build```
 - Run Meson on parent dir/project root ```meson ..```
 - Run Ninja to actually build the project ```ninja```
 
### Build for Win32 through Linux
 - Make build directory ```mkdir build``` and ```cd build```
 - Run Meson while providing a cross-compilation conf ```meson .. --cross-file ../cross_file.txt```
 - Run Ninja to actually build the project ```ninja```

### Installing new Meson Wraps
 - Install the wrap (for example Lua): ```meson wrap install lua```
 - Reference the subproject/dependency inside meson.build, like:
   ```Meson
   lua = subproject('lua')
   lua_dep = lua.get_variable('lua_dep')
   ```
 - Add ```lua_dep``` in the array of common dependencies, like:
   ```Meson
   lib_common_dep = [lua_dep, thread_dep]
   ```
