/*************************************************************************
     ** File Name: DrawOp.h
    ** Author: vanvick
    ** Mail: vanvick@163.com
    ** Created Time: Wed Apr 10 16:46:51 2013
    **Copyright [2013] <Copyright vanvick>  [legal/copyright]
 ************************************************************************/


#ifndef KINGSLANDING_ONLINEWHITEBOARD_SERVER_DRAWOPERATION_DRAWOP_H_
#define KINGSLANDING_ONLINEWHITEBOARD_SERVER_DRAWOPERATION_DRAWOP_H_

#include<opencv/highgui.h>
#include<opencv2/core/core.hpp>
#include "../common.h"
#include "../message.pb.h"

namespace Kingslanding {
namespace OnlineWhiteBoard {
namespace Server {
namespace DrawOperation {

class DrawOp {
public:
      explicit DrawOp(int meeting_id);
      ~DrawOp();
      void Draw(Operation op);
      void SaveAsBmp();
      void Show();

private:
      void DrawEclipse();
      void DrawCircle();
      void DrawLine();
      void DrawRect();
      void DrawPoint();
      void DrawTransEclipse();
      void DrawTransCircle();
      void DrawTransRect();
      void DrawEraser();
      cv::Scalar SetColor(int color);
#ifdef DEBUG
      FRIEND_TEST(DrawOpTest, Initial);
      FRIEND_TEST(DrawOpTest, DrawCircle);
      FRIEND_TEST(DrawOpTest, DrawTransCircle);
      FRIEND_TEST(DrawOpTest, DrawEclipse);
      FRIEND_TEST(DrawOpTest, DrawRect);
      FRIEND_TEST(DrawOpTest, DrawTransRect);
      FRIEND_TEST(DrawOpTest, DrawLine);
      FRIEND_TEST(DrawOpTest, DrawPoint);
      FRIEND_TEST(DrawOpTest, DrawEraser);
#endif
      
      int meeting_id_;
      int a_;
      int b_;
      int color_;
      int thinkness_;
      float alpha_;
      int xa_;
      int xb_;
      int ya_;
      int yb_;
      cv::Mat picture_;
};
}  // DrawOperation
}  // Server
}  // OnlineWhiteBoard
}  // Kingslanding
#endif  // KINGSLANDING_ONLINEWHITEBOARD_SERVER_DRAWOPERATION_DRAWOP_H_
