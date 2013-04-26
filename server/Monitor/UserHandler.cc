/*************************************************************************
     ** File Name: UserHandler.cc
    ** Author: vanvick
    ** Mail: vanvick@163.com
    ** Created Time: Wed Apr 10 16:46:51 2013
    **Copyright [2013] <Copyright fl570>  [legal/copyright]
 ************************************************************************/

#include "./UserHandler.h"

namespace Kingslanding {
namespace OnlineWhiteBoard {
namespace Server {
namespace Monitor {
UserHandler::UserHandler(MeetingHandler& meeting_handler): MsgHandler()
{
Meeting_Handler = meeting_handler;
}

bool UserHandler::TransferAuth(const std::string& meeting_id, const std::string& user_name)
{
  int temp;
  temp = db_manager_->UpdateUserState(meeting_id, user_name, 4);
  if(temp != 1) {
    return false;
  }
  bool temp1 = Meeting_Handler->TransferHostDraw(meeting_id);
  if(!temp1) {
    return false;
  }
  temp = db_manager_->UpdateUserState(meeting_id, user_name, 3);
  if(temp != 1) {
    return false;
  }
  return true;
}

bool UserHandler::RequestAuth(const std::string& meeting_id, const std::string& user_name)
{
  int temp;
  temp=db_manager_->UpdateUserState(meeting_id, user_name, 2);
  if(temp != 1) {
    return false;
  }
  return true;
}

UserList UserHandler::GetCurrentUserList(const std::string& meeting_id)
{
  UserList list;
  int * size;
  DBManager::UserInfo * res = db_manager_->GetUserList(meeting_id, size);
  list = UserListFactory(res, size);
  return list;
}

UserList UserHandler::UserListFactory(DBManager::UserInfo* res , int& size )
{
  UserList list;
  for(int i = 0; i < *size; i++) {
    User usr = list.add_users();
    usr.set_identity(res[i].state);
    usr.set_user_name(res[i].user_name);
  }
  return list;
}

}  // Monitor
}  // Server
}  // OnlineWhiteBoard
}  // Kingslanding

int main() {
Kingslanding::OnlineWhiteBoard::Server::Monitor::MeetingHandler* m = new Kingslanding::OnlineWhiteBoard::Server::Monitor::MeetingHandler();
Kingslanding::OnlineWhiteBoard::Server::Monitor::UserHandler* u = new Kingslanding::OnlineWhiteBoard::Server::Monitor::UserHandler(m);
std::string meeting_id = "405";
std::string user_name = " abc";
bool temp = u->TransferAuth(meeting_id, user_name);
std::cout<<temp;
return 0;

}