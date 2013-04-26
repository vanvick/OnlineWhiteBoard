/*************************************************************************
     ** File Name: HBHandlerTest.cc
    ** Author: vanvick
    ** Mail: vanvick@163.com
    ** Created Time: Wed Apr 10 16:46:51 2013
    **Copyright [2013] <Copyright vanvick>  [legal/copyright]
 ************************************************************************/

#include "./HBHandler.h"


namespace Kingslanding {
namespace OnlineWhiteBoard {
namespace Server {
namespace Monitor {
class HBHandlerTest: public ::testing::Test {
protected:
  HBHandler * hbhandler;
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
    hbhandler = new HBHandlerTest();
  }
  virtual void TearDown() {
    delete hbhandler;
  }
};
TEST_F(HBHandlerTest, GetUserState) {
  HeartBeatSendPackage* h = new HeartBeatSendPackage();
  h->set_meeting_id("405");
  h->set_user_name("abc");
  HeartReturnPackage heart_retrun_package =hbhandler->GetUserState(h);
  EXPECT_EQ(1, heart_retrun_package.identity());
}
}  // Monitor
}  // Server
}  // OnlineWhiteBoard
}  // Kingslanding

int main(int argc, char **argv) {
  std::cout << "Running main() from gtest_main.cc\n";
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}