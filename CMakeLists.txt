cmake_minimum_required(VERSION 3.5)

project(GoTikZ LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic")

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

add_executable(GoTikZ
        main.cpp
        View/Widgets/MainWidget.cpp
        View/Widgets/MainWidget.h
        View/Widgets/DrawWidget.cpp
        View/Widgets/DrawWidget.h
        View/Widgets/RightSideBar.cpp View/Widgets/RightSideBar.h
        Drawable/Drawable.h Drawable/Line.cpp Drawable/Line.h Drawable/StreamDrawable.h Drawable/LineStream.cpp Drawable/LineStream.h Drawable/CircleStream.cpp Drawable/CircleStream.h Drawable/Circle.cpp Drawable/Circle.h View/Widgets/LeftSideBar.cpp View/Widgets/LeftSideBar.h Drawable/Point.cpp Drawable/Point.h Drawable/PolyLineStream.cpp Drawable/PolyLineStream.h Drawable/PolyLine.cpp Drawable/PolyLine.h Drawable/StreamDrawableFactory.cpp Drawable/StreamDrawableFactory.h Math/Math.h Math/Math.cpp View/Widgets/ColorWidget.cpp View/Widgets/ColorWidget.h Drawable/Drawable.cpp Controller/Controller.cpp Controller/Controller.h Controller/Actions/UndoableAction.cpp Controller/Actions/UndoableAction.h Controller/Actions/AddPrimitiveAction.cpp Controller/Actions/AddPrimitiveAction.h View/Widgets/PrimitiveTypeSelectWidget.cpp View/Widgets/PrimitiveTypeSelectWidget.h View/Widgets/ActionWidget.h Controller/Actions/ChangePrimitiveTypeAction.cpp Controller/Actions/ChangePrimitiveTypeAction.h View/Widgets/GridSettingWidget.cpp View/Widgets/GridSettingWidget.h View/GridState.cpp View/GridState.h Controller/Actions/Action.h Controller/Actions/ChangeGridAction.cpp Controller/Actions/ChangeGridAction.h View/Widgets/PenWidget.cpp View/Widgets/PenWidget.h Controller/Actions/PenChangeAction.cpp Controller/Actions/PenChangeAction.h View/Widgets/AuxWidgets/GroupBoxContainer.cpp View/Widgets/AuxWidgets/GroupBoxContainer.h MainWindow.cpp MainWindow.h Model/Model.cpp Model/Model.h Drawable/DrawableHandler.cpp Drawable/DrawableHandler.h Model/PrimitiveTypeEnum.h Model/PrimitiveTypeEnum.cpp View/Widgets/DrawableEditWidgets/CircleEditWidget.cpp View/Widgets/DrawableEditWidgets/CircleEditWidget.h View/Widgets/DrawableEditWidgets/LineEditWidget.cpp View/Widgets/DrawableEditWidgets/LineEditWidget.h View/Widgets/DrawableEditWidgets/PointEditWidget.cpp View/Widgets/DrawableEditWidgets/PointEditWidget.h View/Widgets/DrawableEditWidgets/PolyLineEditWidget.cpp View/Widgets/DrawableEditWidgets/PolyLineEditWidget.h View/Widgets/AuxWidgets/XyWidget.cpp View/Widgets/AuxWidgets/XyWidget.h View/Transform.cpp View/Transform.h Controller/Actions/DeletePrimitiveAction.cpp Controller/Actions/DeletePrimitiveAction.h View/Widgets/DrawableEditWidgets/DrawableEditWidget.h Controller/Actions/TranslatePrimitiveAction.cpp Controller/Actions/TranslatePrimitiveAction.h Controller/ModifierState.cpp Controller/ModifierState.h Controller/MouseHandler.cpp Controller/MouseHandler.h View/Widgets/DrawableEditWidgets/DrawableEditWidgetFactory.cpp View/Widgets/DrawableEditWidgets/DrawableEditWidgetFactory.h Drawable/ControlPoint/ControlPoint.cpp Drawable/ControlPoint/ControlPoint.h Drawable/ControlPoint/ControlPointFactory.cpp Drawable/ControlPoint/ControlPointFactory.h Drawable/ControlPoint/PointLinkFunctor.cpp Drawable/ControlPoint/PointLinkFunctor.h View/ColorPresets.cpp View/ColorPresets.h)

target_link_libraries(GoTikZ PRIVATE Qt::Widgets)
target_link_libraries(GoTikZ PRIVATE Qt::Core)
target_link_libraries(GoTikZ PRIVATE Qt::Gui)