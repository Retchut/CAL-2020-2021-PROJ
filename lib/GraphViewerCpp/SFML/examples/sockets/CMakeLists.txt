
set(SRCROOT ${PROJECT_SOURCE_DIR}/example/sockets)

# all source files
set(SRC ${SRCROOT}/Sockets.cpp
        ${SRCROOT}/TCP.cpp
        ${SRCROOT}/UDP.cpp)

# define the sockets target
sfml_add_example(sockets
                 SOURCES ${SRC}
                 DEPENDS sfml-network)
