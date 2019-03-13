# MIRANDA

Web server multithreading with Qt library

## BUILD

- clone in package directory
```
cd charonplatform
git clone git@github.com:charonplatform/miranda.git packages/miranda
Cloning into 'packages/miranda'...
remote: Enumerating objects: 30, done.
remote: Counting objects: 100% (30/30), done.
remote: Compressing objects: 100% (22/22), done.
remote: Total 30 (delta 10), reused 25 (delta 5), pack-reused 0
Receiving objects: 100% (30/30), 65.68 KiB | 0 bytes/s, done.
Resolving deltas: 100% (10/10), done.
Checking connectivity... done.
```

- build  project

```
mkdir build
cd build
cmake ..
make -j4 (4 is number of cores)

CHARON BACKEND embedded
CHARON BASE64 embedded
CHARON DIGEST embedded
CHARON MVM CONTAINER deque-stack
etc, etc
PACKAGE: miranda
-- Configuring done
-- Generating done
-- Build files have been written to: /home/ariveira/projetos/charon/build

Building CXX object packages/miranda/CMakeFiles/miranda.dir/main.cpp.o
Building CXX object packages/miranda/CMakeFiles/miranda.dir/mirandaserver.cpp.o
Building CXX object packages/miranda/CMakeFiles/miranda.dir/mirandatask.cpp.o
Linking CXX executable ../../../bin/miranda
Built target miranda

```

### Config
config/miranda.json

```
{
  "address" : "localhost",
  "port"    : 2345,
  "threads" : 15,
  "pid"     : "tmp/pid/miranda.pid"
}

```

## LICENSE
This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
