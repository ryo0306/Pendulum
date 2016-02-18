#pragma once
#include "lib/framework.hpp"
#define env App::Get() 

enum Window {
  WIDTH = 512,
  HEIGHT = 512
};


class App
{
public:
  static AppEnv& Get()
  {
    static AppEnv putenv(Window::WIDTH, Window::HEIGHT);
    return putenv;
  }
private:
  App(){}
};