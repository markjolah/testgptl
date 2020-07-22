# GPTL CMake Test Program

This is a test repository to debug the ECBuild FindGPTL.cmake.

There is a standard `CMakeLists.txt` which finds GPTL and links against the `GPTL::GPTL` imported interface target, which should provide all of the appropriate target properties for linking against GPTL.

To build and test you will require ECBuild branch [JCSDA/ecbuild/feature/find-gptl](https://github.com/JCSDA/ecbuild/tree/feature/find-gptl).

```
$ <path-to-ecbuild-repo>/bin/ecbuild -H. -B_build
$ cd _build
$ VERBOSE=1 make
$ ./testgptl
```

The `CMakeLists.txt` will print out the IMPORTED INTERFACE properties of the `GPTL::GPTL` target for debugging during
the CMake configure step.  For example:

```
-- [TARGET: GPTL::GPTL Interface Properties]
--   >GPTL::GPTL INTERFACE_INCLUDE_DIRECTORIES: /usr/include;/usr/include
--   >GPTL::GPTL INTERFACE_LINK_LIBRARIES: -lgptlf;-lgptl;-lunwind
--   >GPTL::GPTL INTERFACE_LINK_DIRECTORIES:
--   >GPTL::GPTL INTERFACE_LINK_OPTIONS: -Wl,-O1;-Wl,--as-needed;-rdynamic
--   >GPTL::GPTL INTERFACE_COMPILE_FEATURES:
--   >GPTL::GPTL INTERFACE_COMPILE_OPTIONS:
--   >GPTL::GPTL INTERFACE_COMPILE_DEFINITIONS:
```

