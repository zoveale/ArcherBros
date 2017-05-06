#ifndef  GLOBAL_H
#define GLOBAL_H

class Global {
  private:
  const int LEVEL_WIDTH = 1920;
  const int LEVEL_HEIGHT = 1080;
  
  const int SCREEN_WIDTH = 640;
  const int SCREEN_HEIGHT = 480;
  

  public:

  const int LEVELWIDTH(){return LEVEL_WIDTH;}
  const int LEVELHEIGHT(){return LEVEL_HEIGHT;}

  const int SCREENWIDTH(){return SCREEN_WIDTH;}
  const int SCREENHEIGHT(){return SCREEN_HEIGHT;}
  
};
#endif // ! GLOBAL_H
