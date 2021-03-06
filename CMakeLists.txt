set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake/modules )

# search packages used by KDE
find_package(KDE4 REQUIRED)
find_package(Akonadi REQUIRED)
find_package(KdepimLibs REQUIRED)

include(KDE4Defaults)
include(MacroLibrary)
include(MacroOptionalAddSubdirectory)
include(FindKdepimLibs)

SET (CMAKE_REQUIRED_DEFINITIONS ${_KDE4_PLATFORM_DEFINITIONS})
ADD_DEFINITIONS (${QT_DEFINITIONS} ${KDE4_DEFINITIONS} -DQT_USE_FAST_CONCATENATION -DQT_USE_FAST_OPERATOR_PLUS)

IF (HAS_AKONADI_PIM)
    ADD_DEFINITIONS (-DHAS_AKONADI_PIM)
    MESSAGE ("-- Compiling for KDE PIM 4.6")
ENDIF (HAS_AKONADI_PIM)

INCLUDE_DIRECTORIES (${QDBUS_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}
    ${KDE4_INCLUDES}
    ${AKONADI_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}/akonadi
    ${CMAKE_SOURCE_DIR}/libkdepim
    ${KDEPIMLIBS_INCLUDE_DIRS}
)

add_subdirectory(src/applet)
# add_subdirectory(src/dataengine)

add_subdirectory(po)
