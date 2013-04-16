/*************************************************************************
     ** File Name: RcfDefine.h
    ** Author: tsgsz
    ** Mail: cdtsgsz@gmail.com
    ** Created Time: Fri Apr 12 15:58:22 2013
    **Copyright [2013] <Copyright tsgsz>  [legal/copyright]
 ************************************************************************/
#include <RCF/RCF.hpp>
#include <RCF/Idl.hpp>

RCF_BEGIN(Updater,"Updater")
    RCF_METHOD_R1(bool, WriteOperationToPool, const Operation&)
RCF_END(Updater)

RCF_BEGIN(Monitor,"Monitor")
    RCF_METHOD_R1(bool, Login, const User&)
    RCF_METHOD_R2(JoinMeetingReturn, JoinMeeting, const std::string&,\
                  const std::string&)
    RCF_METHOD_R2(int32_t, TransferAuth, const std::string&, const std::string&)
    //0 for fail, 1 for success, 2 for there is some problem with the user
    RCF_METHOD_R2(bool, RequestAuth, const std::string&, const std::string&)
    RCF_METHOD_R1(UserList, GetCurrentUserList, const std::string&)
    RCF_METHOD_R1(HeartReturnPackage, HeartBeat, const HeartBeatSendPackage&)
    RCF_METHOD_R1(const std::string, CreateMeeting, const std::string&)
    RCF_METHOD_R1(bool, ResumeUpdater, const std::string&)
RCF_END(Monitor)

RCF_BEGIN(Provider,"Provider")
    RCF_METHOD_R2(Opeartions, GetOperations, const std::string&,\
                  const std::string&)
    RCF_METHOD_R1(Document, GetLatestDocument, const std::string&)
    RCF_METHOD_R1(DocumentList, GetHistorySnapshots, const std::string&)
    RCF_METHOD_R2(Document, GetDocument, const std::string&, int32_t)
RCF_END(Provider)


