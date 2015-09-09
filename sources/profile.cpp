#include "cgl/profile.h"

CglProfile::CglProfile()
{
  displayAxes       = true;
  displayAxesLabels = false;
  displayBackgroundGradient = true;

  displayShadows    = true;
  displayBottomGrid = false;//true;
  smooth            = false;

  displayReflection = true;

  stereo            = false;
  perspective       = true;

  classicalMode     = true;
  accumulatedMode   = false;
  flyingMode        = false;

  invertVertical    = true;

  independantScale  = false;
  globalScale       = true;

  groupRotation     = true;

  bottomDistance    = 0.1;
  bottomAngle       = 0.0;//G(float)3.14159/4;

  clear_back_color    = glm::vec3(1,   1,   0.98);
  clear_grid_color    = glm::vec3(0.4, 0.4, 0.4);
  clear_idle_color    = glm::vec3(0.15, 0.15, 0.15);
  clear_shadow        = 0.9;

  dark_back_color    = glm::vec3(0.02, 0.02, 0.02);
  dark_grid_color    = glm::vec3(0.65, 0.65, 0.65);
  dark_idle_color    = glm::vec3(0.8, 0.8, 0.8);
  dark_shadow        = 0.2;

  saturation     = 0.65;
  value          = 1;
  mixWithWhite   = 1;


  dark_theme = true;
  update_theme();

  sele_color    = glm::vec3(1,   0.6, 0);
}

CglProfile::~CglProfile(){}

glm::vec3 CglProfile::color(){
  return colorGenerator.generateColor();
}

void CglProfile::update_theme(){
  back_color    = ((dark_theme)?dark_back_color:clear_back_color);
  grid_color    = ((dark_theme)?dark_grid_color:clear_grid_color);
  idle_color    = ((dark_theme)?dark_idle_color:clear_idle_color);
  shadow_factor = ((dark_theme)?dark_shadow:clear_shadow);
  displayReflection = ((dark_theme)?1:0);
  displayShadows    = ((dark_theme)?0:1);
}
