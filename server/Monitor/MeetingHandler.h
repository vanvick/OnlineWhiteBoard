/*************************************************************************
     ** File Name: MeetingHandler.h
    ** Author: fl570
    ** Mail: cqfl570@gmail.com
    ** Created Time: Wed Apr 10 16:46:51 2013
    **Copyright [2013] <Copyright fl570>  [legal/copyright]
 ************************************************************************/

#ifndef KINGSLANDING_ONLINEWHITEBOARD_SERVER_MONITOR_MEETINGHANDLER_H_
#define KINGSLANDING_ONLINEWHITEBOARD_SERVER_MONITOR_MEETINGHANDLER_H_

#define DBMANAGER Kingslanding::OnlineWhiteBoard::Server::DBManager


#include <RCF/RCF.hpp>
#include <hash_map>

#include "./Handler.h"

namespace Kingslanding {
namespace OnlineWhiteBoard {
namespace Server {
namespace Monitor {

class MeetingHandler : public MsgHandler {
public:
    MeetingHandler();
    bool CreateMeeting(const std::string&, const std::string&);
    MeetingServerInfo JoinMeeting(const std::string&, const std::string&, int);
    bool DeleteMeeting(const std::string&);
    bool LogIn(const User&);
    virtual ~MeetingHandler();
private:
    bool AddMeetingPort(const std::string&, int);
    bool SetDataRef(const std::string&, int);
    int GetDataRef(const std::string&);

    std::hash_map monitor_updater_<std::string, RCF::RcfServer>;
};
}  // Monitor
}  // Server
}  // OnlineWhiteBoard
}  // Kingslanding
#endif  // KINGSLANDING_ONLINEWHITEBOARD_SERVER_MONITOR_MEETINGHANDLER_H_
