cmake_minimum_required(VERSION 3.14)
project(Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project PlaylistLinkedQueue.cpp SongsLinkedNode.cpp CollectLinkedNode.cpp CollectLinkedList.cpp ArrayLib.cpp TestLib.cpp CollectPlaylistsTest.cpp)