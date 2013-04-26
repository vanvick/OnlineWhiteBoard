/*************************************************************************
     ** File Name: UserHandlerTest.cc
    ** Author: vanvick
    ** Mail: vanvick@163.com
    ** Created Time: Wed Apr 10 16:46:51 2013
    **Copyright [2013] <Copyright vanvick>  [legal/copyright]
 ************************************************************************/

#include "./UserHandler.h"


namespace Kingslanding {
namespace OnlineWhiteBoard {
namespace Server {
namespace DrawOperation {
class UserHandlerTest: public ::testing::Test {
protected:
  UserHandler *u ;
  MeetingHandler *m;
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
    m = new MeetingHandler();
    u = new UserHandler(m);
  }
  virtual void TearDown() {
    delete u;
    delete m;
  }
};

TEST_F(UserHandlerTest, TransferAuth) {
  std::string meeting_id = "405";
  std::string user_name = "abc";
  bool temp = u->TransferAuth(meeting_id, user_name);
  EXPECT_EQ(true, temp);
}
TEST_F(UserHandlerTest, RequestAuth) {
  std::string meeting_id = "396";
  std::string user_name = "abc";
  bool temp = u->RequestAuth(meeting_id, user_name);
  EXPECT_EQ(true, temp);
}

/*TEST_F(UserHandlerTest, GetCurrentUserList) {
  
}*/
}  // DrawOperation
}  // Server
}  // OnlineWhiteBoard
}  // Kingslanding

int main(int argc, char **argv) {
  std::cout << "Running main() from gtest_main.cc\n";
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}