cmake_minimum_required(VERSION 3.5)

project(GoTikZ LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
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
        Widgets/RightSideBar.cpp Widgets/RightSideBar.h
        Drawable/Drawable.h Drawable/Line.cpp Drawable/Line.h Drawable/StreamDrawable.h Drawable/LineStream.cpp Drawable/LineStream.h Drawable/CircleStream.cpp Drawable/CircleStream.h Drawable/Circle.cpp Drawable/Circle.h Widgets/LeftSideBar.cpp Widgets/LeftSideBar.h Drawable/Point.cpp Drawable/Point.h Drawable/PolyLineStream.cpp Drawable/PolyLineStream.h Drawable/PolyLine.cpp Drawable/PolyLine.h Drawable/StreamDrawableFactory.cpp Drawable/StreamDrawableFactory.h Math/Math.h Math/Math.cpp Widgets/ColorWidget.cpp Widgets/ColorWidget.h Drawable/Drawable.cpp Actions/ActionHandler.cpp Actions/ActionHandler.h Actions/UndoableAction.cpp Actions/UndoableAction.h Actions/AddPrimitiveAction.cpp Actions/AddPrimitiveAction.h Widgets/MousePointerTypeSelectWidget.cpp Widgets/MousePointerTypeSelectWidget.h Widgets/ActionWidget.cpp Widgets/ActionWidget.h Actions/ChangeMousePointerTypeAction.cpp Actions/ChangeMousePointerTypeAction.h Widgets/GridSettingWidget.cpp Widgets/GridSettingWidget.h States/GridState.cpp States/GridState.h Actions/Action.h Actions/ChangeGridAction.cpp Actions/ChangeGridAction.h Widgets/PenWidget.cpp Widgets/PenWidget.h Actions/PenChangeAction.cpp Actions/PenChangeAction.h Widgets/GroupBoxContainer.cpp Widgets/GroupBoxContainer.h  MainWindow.cpp MainWindow.h Model/Model.cpp Model/Model.h Drawable/DrawableHandler.cpp Drawable/DrawableHandler.h Model/MousePointerTypeEnum.h Model/MousePointerTypeEnum.cpp Widgets/DrawableEditWidgets/CircleEditWidget.cpp Widgets/DrawableEditWidgets/CircleEditWidget.h Widgets/DrawableEditWidgets/LineEditWidget.cpp Widgets/DrawableEditWidgets/LineEditWidget.h Widgets/DrawableEditWidgets/PointEditWidget.cpp Widgets/DrawableEditWidgets/PointEditWidget.h Widgets/DrawableEditWidgets/PolyLineEditWidget.cpp Widgets/DrawableEditWidgets/PolyLineEditWidget.h Widgets/AuxWidgets/XyWidget.cpp Widgets/AuxWidgets/XyWidget.h States/Transform.cpp States/Transform.h Actions/DeletePrimitiveAction.cpp Actions/DeletePrimitiveAction.h)

target_link_libraries(GoTikZ PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
