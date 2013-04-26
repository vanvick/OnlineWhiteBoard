/*************************************************************************
     ** File Name: DrawPointTest.cc
    ** Author: vanvick
    ** Mail: vanvick@163.com
    ** Created Time: Wed Apr 10 16:46:51 2013
    **Copyright [2013] <Copyright vanvick>  [legal/copyright]
 ************************************************************************/

#include "./DrawPoint.h"

namespace Kingslanding {
namespace OnlineWhiteBoard {
namespace Server {
namespace DrawOperation {
class DrawPointTest: public ::testing::Test {
protected:
  DrawPoint * point ;
  static void SetUpTestCase() {
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    google::InitGoogleLogging("LOG");
    FLAGS_log_dir = "../LOG";
  }
  static void TearDownTestCase() {
    google::protobuf::ShutdownProtobufLibrary();
    google::ShutdownGoogleLogging();
  }
  virtual void SetUp() {
    point = new DrawPoint();
  }
  virtual void TearDown() {
    delete point;
  }
};

TEST_F(DrawPointTest, set) {
    point->set(2, 1, 50, 50);
    EXPECT_EQ(2, point->color_);
    EXPECT_EQ(1, point->thinkness_);
    EXPECT_EQ(50, point->xa_);
    EXPECT_EQ(50, point->ya_);
}
}  // DrawOperation
}  // Server
}  // OnlineWhiteBoard
}  // Kingslanding

  