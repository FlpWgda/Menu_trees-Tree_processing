# cmake_minimum_required(VERSION <specify CMake version here>)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp CTable.cpp CTable.h CMenuItem.cpp CMenuItem.h CMenu.cpp CMenu.h CMenuCommand.cpp CMenuCommand.h CCommand.cpp CCommand.h CreateDefault.cpp CreateDefault.h CreateCustom.cpp CreateCustom.h CreateCopy.cpp CreateCopy.h DeleteOne.cpp DeleteOne.h DeleteAll.cpp DeleteAll.h ChangeName.cpp ChangeName.h ChangeCell.cpp ChangeCell.h ShowInfo.cpp ShowInfo.h)