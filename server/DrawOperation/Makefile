# The Makefile to build DrawOperation and it's test

CXX = g++

# System Header
SYSTEM_HEADER_DIR = /usr/include

# The root dir
ROOT_DIR = ../..

#The 3rdparty dir
THRIDPARTY_DIR = $(ROOT_DIR)/thridparty

# To find the gtest
GTEST_DIR = $(THRIDPARTY_DIR)/gtest-1.6.0

#All Google Test headers. Usually you shouldn't change this
#definition
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

# Flags passed to the preprocessor
CPPFLAGS += -I$(GTEST_DIR)/include

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

#Flags passed to the C++ compiler
CXXFLAGS += -g -Wall -Wextra

# Test
TESTS = ../test/DrawOperation.test

# DrawOperation sources
DRAW_OPERATION_SRCS_ = DrawOperation.cc
DRAW_OPERATION_TEST_SRCS_ = DrawOperationTest.cc
DRAW_CLASS_SRCS_ = DrawClass.cc
DRAW_CIRCLE_SRCS_ = DrawCircle.cc
DRAW_TRANSCIRCLE_SRCS_ = DrawTransCircle.cc
DRAW_RECT_SRCS_ = DrawRect.cc
DRAW_TRANSRECT_SRCS_ = DrawTransRect.cc
DRAW_ECLIPSE_SRCS_ = DrawEclipse.cc
DRAW_TRANSECLIPSE_SRCS_ =DrawTransEclipse.cc
DRAW_LINE_SRCS_ = DrawLine.cc
DRAW_POINT_SRCS_ = DrawPoint.cc
DRAW_ERASER_SRCS_ = DrawEraser.cc
MESSAGE_PB_SRCS_ = ../message.pb.cc
DRAW_CIRCLE_TEST_SRCS_ = DrawCircleTest.cc
DRAW_TRANSCIRCLE_TEST_SRCS_ = DrawTransCircleTest.cc
DRAW_TRANSRECT_TEST_SRCS_ = DrawTransRectTest.cc
DRAW_RECT_TEST_SRCS_ = DrawRectTest.cc
DRAW_LINE_TEST_SRCS_ = DrawLineTest.cc
DRAW_POINT_TEST_SRCS_ = DrawPointTest.cc
DRAW_ERASER_TEST_SRCS_ = DrawEraserTest.cc

all : $(TESTS)

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^


$(TESTS) : DrawOperationTest.o DrawCircleTest.o DrawTransCircleTest.o \
           DrawRectTest.o DrawTransRectTest.o DrawLineTest.o \
           DrawPointTest.o DrawEraserTest.o DrawOperation.o DrawClass.o \
           DrawLine.o DrawPoint.o DrawEraser.o DrawRect.o \
           DrawTransRect.o DrawCircle.o DrawTransCircle.o message.pb.o\
           DrawEclipse.o DrawTransEclipse.o gtest.a 
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) DrawOperationTest.o \
           DrawOperation.o DrawClass.o DrawLine.o DrawPoint.o \
           DrawEraser.o DrawRect.o DrawTransRect.o DrawCircle.o \
           DrawTransCircle.o DrawEclipse.o DrawTransEclipse.o  message.pb.o \
	   DrawCircleTest.o DrawTransCircleTest.o DrawRectTest.o \
           DrawTransRectTest.o DrawLineTest.o DrawPointTest.o DrawEraserTest.o \
           gtest.a `pkg-config --cflags opencv`  \
           `pkg-config --libs opencv` -lglog -lgflags \
           -lprotobuf -o $@
         

DrawOperationTest.o : $(DRAW_OPERATION_TEST_SRCS_) $(GTEST_HEADERS)
	$(CXX) $(CXXFLAGS) -c $(DRAW_OPERATION_TEST_SRCS_)

DrawOperation.o : $(DRAW_OPERATION_SRCS_) $(GTEST_HEADERS)
	$(CXX) $(CXXFLAGS) -c $(DRAW_OPERATION_SRCS_)

DrawCircle.o : $(DRAW_CIRCLE_SRCS_) $(GTEST_HEADERS)
	$(CXX) $(CXXFLAGS) -c $(DRAW_CIRCLE_SRCS_)

DrawCircleTest.o : $(DRAW_CIRCLE_TEST_SRCS_) $(GTEST_HEADERS)
	$(CXX) $(CXXFLAGS) -c $(DRAW_CIRCLE_TEST_SRCS_)

DrawTransCircle.o : $(DRAW_TRANSCIRCLE_SRCS_) $(GTEST_HEADERS)
	$(CXX) $(CXXFLAGS) -c $(DRAW_TRANSCIRCLE_SRCS_)

DrawTransCircleTest.o : $(DRAW_TRANSCIRCLE_TEST_SRCS_) $(GTEST_HEADERS)
	$(CXX) $(CXXFLAGS) -c $(DRAW_TRANSCIRCLE_TEST_SRCS_)

DrawRect.o : $(DRAW_RECT_SRCS_) $(GTEST_HEADERS)
	$(CXX) $(CXXFLAGS) -c $(DRAW_RECT_SRCS_)

DrawRectTest.o : $(DRAW_RECT_TEST_SRCS_) $(GTEST_HEADERS)
	$(CXX) $(CXXFLAGS) -c $(DRAW_RECT_TEST_SRCS_)

DrawTransRect.o : $(DRAW_TRANSRECT_SRCS_) $(GTEST_HEADERS)
	$(CXX) $(CXXFLAGS) -c $(DRAW_TRANSRECT_SRCS_)

DrawTransRectTest.o : $(DRAW_TRANSRECT_TEST_SRCS_) $(GTEST_HEADERS)
	$(CXX) $(CXXFLAGS) -c $(DRAW_TRANSRECT_TEST_SRCS_)

DrawEclipse.o : $(DRAW_ECLIPSE_SRCS_) $(GTEST_HEADERS)
	$(CXX) $(CXXFLAGS) -c $(DRAW_ECLIPSE_SRCS_)

DrawTransEclipse.o : $(DRAW_TRANSECLIPSE_SRCS_) $(GTEST_HEADERS)
	$(CXX) $(CXXFLAGS) -c $(DRAW_TRANSECLIPSE_SRCS_)

DrawLine.o : $(DRAW_LINE_SRCS_) $(GTEST_HEADERS)
	$(CXX) $(CXXFLAGS) -c $(DRAW_LINE_SRCS_)

DrawLineTest.o : $(DRAW_LINE_TEST_SRCS_) $(GTEST_HEADERS)
	$(CXX) $(CXXFLAGS) -c $(DRAW_LINE_TEST_SRCS_)

DrawPoint.o : $(DRAW_POINT_SRCS_) $(GTEST_HEADERS)
	$(CXX) $(CXXFLAGS) -c $(DRAW_POINT_SRCS_)

DrawPointTest.o : $(DRAW_POINT_TEST_SRCS_) $(GTEST_HEADERS)
	$(CXX) $(CXXFLAGS) -c $(DRAW_POINT_TEST_SRCS_)

DrawEraser.o : $(DRAW_ERASER_SRCS_) $(GTEST_HEADERS)
	$(CXX) $(CXXFLAGS) -c $(DRAW_ERASER_SRCS_)

DrawEraserTest.o : $(DRAW_ERASER_TEST_SRCS_) $(GTEST_HEADERS)
	$(CXX) $(CXXFLAGS) -c $(DRAW_ERASER_TEST_SRCS_)

DrawClass.o : $(DRAW_CLASS_SRCS_) $(GTEST_HEADERS)
	$(CXX) $(CXXFLAGS) -c $(DRAW_CLASS_SRCS_)

message.pb.o : $(MESSAGE_PB_SRCS_) $(GTEST_HEADERS)
	$(CXX) $(CXXFLAGS) -c $(MESSAGE_PB_SRCS_)

clean :
	rm -rf $(TESTS) *.a *.o test/*.o 
