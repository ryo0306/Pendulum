#include "src/Pendulum.h"


Vec2f Pendulum::Gravity(Vec2f pos_, Vec2f sPos_, float& rotate_, float& rotateS_, float length_)
{

  Vec2f putPos = pos_;
  // ���݂̊p�x
  float rad = rotate_ * M_PI / 180;

  // ���݂̏d��̈ʒu
  putPos.x() = sPos_.x() + cos(rad) * length_;
  putPos.y() = sPos_.y() + sin(rad) * length_;

  // �d��Ǝx�_�Ƃ̋������Z�o
  float vx = putPos.x() - sPos_.x();
  float vy = putPos.y() - sPos_.y();

  //�H
  float t = -(vy * GRAVITY) / (vx * vx + vy * vy);

  // �d�͈ړ��ʂ𔽉f�����d��̈ʒu
  float gx = putPos.x() + t * vx;
  float gy = putPos.y() + GRAVITY + t * vy;

  // �Q�̏d��̈ʒu�̊p�x��
  float r = atan2(gy - sPos_.y(), gx - sPos_.x()) * 180 / M_PI;

  //���݂̊p�x��̏d��̊p�x���Ƃ̍����Z�o
  float sub = r - rotate_;
  //�p�x�̌덷��floor�ŏC��
  sub -= floor(sub / 360.0) * 360.0;


  // �p�x�����p���x�ɉ��Z
  if (sub <-180.0)	sub += 360.0;
  if (sub > 180.0)	sub -= 360.0;
  rotateS_ += sub;

  // ���C
  //	rot_spd *= 0.995;

  // �p�x�Ɋp���x�����Z
  rotate_ += rotateS_;

  // �V�����d��̈ʒu
  rad = rotate_ * M_PI / 180;
  putPos.x() = sPos_.x() + cos(rad) * length_;
  putPos.y() = sPos_.y() + sin(rad) * length_;

  // �d��̍��W
  
  return putPos;
}


Vec2f Pendulum::AnGravity(Vec2f pos_, Vec2f sPos_, float rotate_, float rotateS_, float length_)
{

  Vec2f putPos = pos_;
  // ���݂̊p�x
  float rad = rotate_ * M_PI / 180;

  // ���݂̏d��̈ʒu
  putPos.x() = sPos_.x() + cos(rad) * length_;
  putPos.y() = sPos_.y() + sin(rad) * length_;

  // �d��Ǝx�_�Ƃ̋������Z�o
  float vx = putPos.x() - sPos_.x();
  float vy = putPos.y() - sPos_.y();

  //�H
  float t = -(vy * 0) / (vx * vx + vy * vy);

  // �d�͈ړ��ʂ𔽉f�����d��̈ʒu
  float gx = putPos.x() + t * vx;
  float gy = putPos.y() + t * vy;

  // �Q�̏d��̈ʒu�̊p�x��
  float r = atan2(gy - sPos_.y(), gx - sPos_.x()) * 180 / M_PI;

  //���݂̊p�x��̏d��̊p�x���Ƃ̍����Z�o
  float sub = r - rotate_;
  //�p�x�̌덷��floor�ŏC��
  sub -= floor(sub / 360.0) * 360.0;


  // �p�x�����p���x�ɉ��Z
  if (sub <-180.0)	sub += 360.0;
  if (sub > 180.0)	sub -= 360.0;
  rotateS_ += sub;

  // ���C
  //	rot_spd *= 0.995;

  // �p�x�Ɋp���x�����Z
  rotate_ += rotateS_;

  // �V�����d��̈ʒu
  rad = rotate_ * M_PI / 180;
  putPos.x() = sPos_.x() + cos(rad) * length_;
  putPos.y() = sPos_.y() + sin(rad) * length_;

  // �d��̍��W

  return putPos;
}

