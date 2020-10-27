cmake_minimum_required(VERSION 3.5)

project(GoTikZ LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic")

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)


add_executable(GoTikZ
        main.cpp
        Widgets/MainWidget.cpp
        Widgets/MainWidget.h
        Widgets/DrawWidget.cpp
        Widgets/DrawWidget.h
        Drawable/Drawable.h Drawable/Line.cpp Drawable/Line.h Drawable/StreamDrawable.h Drawable/Line_Stream.cpp Drawable/Line_Stream.h Drawable/Circle_Stream.cpp Drawable/Circle_Stream.h Drawable/Circle.cpp Drawable/Circle.h Widgets/LeftSideBar.cpp Widgets/LeftSideBar.h Drawable/Point.cpp Drawable/Point.h Drawable/PolyLine_Stream.cpp Drawable/PolyLine_Stream.h Drawable/PolyLine.cpp Drawable/PolyLine.h Drawable/StreamDrawableFactory.cpp Drawable/StreamDrawableFactory.h Math/Math.h Math/Math.cpp Widgets/ColorWidget.cpp Widgets/ColorWidget.h Drawable/Drawable.cpp Actions/ActionHandler.cpp Actions/ActionHandler.h Actions/UndoableAction.cpp Actions/UndoableAction.h Actions/AddPrimitiveAction.cpp Actions/AddPrimitiveAction.h Widgets/PrimitiveSelectWidget.cpp Widgets/PrimitiveSelectWidget.h Widgets/ActionWidget.cpp Widgets/ActionWidget.h Actions/ChangePrimitiveAction.cpp Actions/ChangePrimitiveAction.h Widgets/GridSettingWidget.cpp Widgets/GridSettingWidget.h States/GridState.cpp States/GridState.h Actions/Action.cpp Actions/Action.h Actions/ChangeGridAction.cpp Actions/ChangeGridAction.h Widgets/PenWidget.cpp Widgets/PenWidget.h Actions/PenChangeAction.cpp Actions/PenChangeAction.h Widgets/GroupBoxContainer.cpp Widgets/GroupBoxContainer.h Widgets/RightSideBar.cpp Widgets/RightSideBar.h Controller.cpp Controller.h)

target_link_libraries(GoTikZ PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
