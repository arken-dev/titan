set(SRCS
    Channel.cpp
    Epoll.cpp
    EventLoop.cpp
    EventLoopThread.cpp
    EventLoopThreadPool.cpp
    HttpData.cpp
    Main.cpp
    Server.cpp
    #ThreadPool.cpp
    Timer.cpp
    Util.cpp
)

find_package(Qt5Core)
find_package(Qt5Network)


include_directories(${PROJECT_SOURCE_DIR}/base)
include_directories(/home/ariveira/projetos/charon/include)
include_directories(/home/ariveira/projetos/charon/deps/include)

link_directories( "/home/ariveira/projetos/charon/deps" )

set(EXECUTABLE_OUTPUT_PATH /home/ariveira/projetos/charon/bin)

add_executable(titan ${SRCS})
target_link_libraries(titan libserver_base charon lua)
target_link_libraries(titan Qt5::Core)
target_link_libraries(titan Qt5::Network)

add_subdirectory(base)
add_subdirectory(tests)
