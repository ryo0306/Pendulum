#include "ScreenMake.h"
#include "Pendulum.h"
#include <iostream>

int main()
{

  Vec2f pos(0,0);
  Vec2f size(50, 50);
  float rotate = 0;
  float angle = 0;
  float rotateSpeed = 3;
  float length = 0;
  Vec2f mousePos;
  Vec2f sPos(0, 0);
  bool active = false;
  while (env.isOpen())
  {
    env.begin();

    mousePos = env.mousePosition();
    
    if (env.isPushButton(Mouse::LEFT))
    {
      // マウスの位置を支点に
      sPos = mousePos;
      //ラジアン角度を求める
      rotate =  (atan2(pos.y() - sPos.y(), pos.x() - sPos.x()))* 180/M_PI;
      length = sqrt(((pos.x() - sPos.x()) * (pos.x() - sPos.x())) + ((pos.y() - sPos.y()) * (pos.y() - sPos.y())));

      active = true;
    }

    // 長押ししている間振り子の動き
    if (active)
    {
      pos = Pendulum::Gravity(pos, sPos, rotate , rotateSpeed, length);
    }

    if (env.isPullButton(Mouse::LEFT))
    {
      
      active = false;
    }
  

    drawFillCircle(pos.x(), pos.y(), size.x(), size.y(), 20, Color::red);
    env.end();
  }
  return 0;
}



//-------------------------------//
//        振り子の動き原案        //
//-------------------------------//

//int main() {
//
//  env;
//
//  Vec2f pos = Vec2f(0, 0);
//  Vec2f size = Vec2f(50, 50);
//  float fx = 0;	// 支点 x 座標
//  float fy = 0;	// 支点 y 座標
//  float rot = 2;	// 角度
//  float rot_spd = 3;	// 角速度
//  float length = 150;	// 紐の長さ
//  float g = -0.0f;	// 重力加速度
//
//  while (env.isOpen()) {
//    env.begin();
//    
//    //pos.x() = fx + cos(rot * M_PI / 180) * length;
//    //pos.y() = fy + sin(rot * M_PI / 180) * length;
//
//    // 現在の角度を算出
//    float rad = rot * M_PI / 180;      
//
//    // 現在の重りの位置
//    float px = fx + cos(rad) * length;
//    float py = fy + sin(rad) * length;
//
//    // 重りと支点との距離を算出
//    float vx = px - fx;
//    float vy = py - fy;
//
//    //？
//    float t = -(vy * g) / (vx * vx + vy * vy);
//
//    // 重力移動量を反映した重りの位置
//    float gx = px + t * vx;
//    float gy = py + g + t * vy;
//
//    // ２つの重りの位置の角度差
//    float r = atan2(gy - fy, gx - fx) * 180 / M_PI;
//
//    //現在の角度二つの重りの角度差との差を算出
//    float sub = r - rot;
//    //角度の誤差をfloorで修正
//    sub -= floor(sub / 360.0) * 360.0;
//
//
//    // 角度差を角速度に加算
//    if (sub <-180.0)	sub += 360.0;
//    if (sub > 180.0)	sub -= 360.0;
//    rot_spd += sub;
//
//    // 摩擦
//    //	rot_spd *= 0.995;
//
//    // 角度に角速度を加算
//    rot += rot_spd;
//
//    // 新しい重りの位置
//    rad = rot * M_PI / 180;
//    px = fx + cos(rad) * length;
//    py = fy + sin(rad) * length;
//
//    // 重りの座標
//    pos.x()= px;
//    pos.y() = py;
//
//
//    drawFillCircle(pos.x(), pos.y(), size.x(), size.y(), 20, Color::red);
//
//    env.end();
//  }
//}
