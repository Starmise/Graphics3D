#pragma once
#include "Prerequisites.h"

class Window;

class UserInterface
{
public:
  UserInterface() = default;
  ~UserInterface() = default;

  void
    init();

  void
    update();

  void
    render();

  void
    destroy();

  void
    setupGUIStyle();

  void
    console(std::map<ConsolErrorType, std::string> programMessages);

private:

};