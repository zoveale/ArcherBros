#ifndef CLACULATE_H
#define CALCULATE_H
#include <math.h>
#include <SDL.h>
class Calculate {

  public:

  int Distance(int xOne, int yOne, int xTwo, int yTwo) {

    return (int)sqrt( ((xTwo - xOne)^2)
                    + ((yTwo - yOne)^2) );
  }

  int aDistance(SDL_Rect rectA, SDL_Rect rectB) {
    /*
    rectA.x
    rectA.y

    rectB.x
    rectB.y
    */
    return (int)sqrt( ((rectB.x - rectA.x)^2)
                    + ((rectB.y - rectA.y)^2) );
  }

  int bDistance(SDL_Rect rectA, SDL_Rect rectB) {
    /*
    rectA.x + rectA.w
    rectA.y + rectA.h

    rectB.x + rectB.w
    rectB.y + rectB.h
    */
    return (int) sqrt((((rectB.x + rectB.w)
                      - (rectA.x + rectA.w)) ^ 2)
                      + (((rectB.y + rectB.h)
                      - (rectA.y + rectA.h)) ^ 2));
  }
};

#endif //!CALUCULATE_H