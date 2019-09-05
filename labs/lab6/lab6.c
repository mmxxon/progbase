#include <math.h>
#include <progbase.h>
#include <progbase/canvas.h>
#include <progbase/console.h>
#include <stdio.h>
#include <stdlib.h>

struct Loc {
  int x;
  int y;
};

struct Color {
  int R;
  int G;
  int B;
};

struct Ball {
  struct Loc loc;
  int radius;
};

int main() {
  const float pi = 3.14159265;

  struct Ball A;
  struct Ball B;
  struct Ball C;

  struct ConsoleSize cs = Console_size();
  int w = cs.columns;
  int h = cs.rows * 2;

  A.loc.x = w / 2;
  A.loc.y = h / 2;

  float angle = 2 * pi;
  float angle1 = angle;

  if (w < h) {
    A.radius = w / 6;
  } else {
    A.radius = h / 6;
  }
  B.radius = A.radius / 2;
  C.radius = B.radius / 2;

  struct Color colA;
  struct Color colB;
  struct Color colC;

  colA.R = 0;
  colA.G = 128;
  colA.B = 128;

  colB.R = 255;
  colB.G = 215;
  colB.B = 0;

  colC.R = 128;
  colC.G = 0;
  colC.B = 0;

  Canvas_invertYOrientation();
  int key;
  do {
    Console_clear();

    B.loc.x = (A.loc.x + A.radius * cos(angle));
    B.loc.y = (A.loc.y + A.radius * sin(angle));

    C.loc.x = (B.loc.x + B.radius * cos(angle1));
    C.loc.y = (B.loc.y + B.radius * sin(angle1));

    Canvas_setSize(w, h);
    Canvas_beginDraw();

    Canvas_setColorRGB(colA.R, colA.G, colA.B);
    Canvas_strokeCircle(A.loc.x, A.loc.y, A.radius);
    Canvas_setColorRGB(colB.R, colB.G, colB.B);
    Canvas_putPixel(B.loc.x, B.loc.y);
    Canvas_setColorRGB(colC.R, colC.G, colC.B);
    Canvas_strokeCircle(C.loc.x, C.loc.y, C.radius);

    Canvas_endDraw();
    key = Console_getChar();
    switch (key) {
    case 'w':
      A.loc.y++;
      break;
    case 's':
      A.loc.y--;
      break;
    case 'd':
      A.loc.x++;
      break;
    case 'a':
      A.loc.x--;
      break;
    case 'r':
      A.radius++;
      break;
    case 't':
      A.radius--;
      if (A.radius < 0)
        A.radius = 0;
      break;
    case 'y':
      angle += pi / 18;
      break;
    case 'u':
      angle -= pi / 18;
      break;
    case 'h':
      angle1 -= pi / 18;
      break;
    case 'j':
      angle1 += pi / 18;
      break;
    case 'f':
      B.radius++;
      break;
    case 'g':
      B.radius--;
      if (B.radius < 0)
        B.radius = 0;
      break;
    case 'v':
      C.radius++;
      break;
    case 'b':
      C.radius--;
      if (C.radius < 0)
        C.radius = 0;
      break;
    }
    int bonus =1;
    int salary = 10;
    return (bonus ? salary*10 : salary);
  } while (key != '\n');
  return 0;
}
