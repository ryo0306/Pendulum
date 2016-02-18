#pragma once
#include "ScreenMake.h"
// ���Œu��
// �d�͂��ω�����悤�Ȃ�����ɓ����
#define GRAVITY (-0.2f)

namespace Pendulum
{
  // �d�͂���
  // Vec2f pos_        ���̂̈ʒu
  // Vec2f sPos_       �x�_�̈ʒu
  // float rotate_     ���݂̊p�x
  // float rotateS_    ���p���x
  // flaot length_     ���̂Ǝx�_�̋���
  Vec2f Gravity(Vec2f pos_, Vec2f sPos_, float& rotate_, float& rotateS_, float length_);

  // �d�͂Ȃ�
  // Vec2f pos_        ���̂̈ʒu
  // Vec2f sPos_       �x�_�̈ʒu
  // float rotate_     ���݂̊p�x
  // float rotateS_    ���p���x
  // flaot length_     ���̂Ǝx�_�̋���
  Vec2f AnGravity(Vec2f pos_, Vec2f sPos_, float rotate_, float rotateS_, float length_);

}