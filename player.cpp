#include "player.hpp"

Player::Player(std::string name, char glyph, int color) {
  this->name = name;
  this->glyph = glyph;
  this->color = color;
  this->worldY = 7;
  this->worldX = 0;
}

Player::~Player() {

}

void Player::draw(Screen &scr) {
  // draw player glyph to screen
  scr.addChar(this->y, this->x, this->glyph, this->color);
}

bool Player::mv(int dy, int dx, Map &currentmap) {
  this->dx = dx;
  this->dy = dy;
  // predict new position
  int newx = this->x + this->dx;
  int newy = this->y + this->dy;

  // move to next area

  // move east
  if(newx == MAP_WIDTH) {
    this->worldX++;
    this->x = 0;
  }
  // move west
  if(newx == -1) {
    this->worldX--;
    this->x = MAP_WIDTH - 1;
  }
  // move north
  if(newy == -1) {
    this->worldY--;
    this->y = MAP_HEIGHT - 1;
  }
  // move south
  if(newy == MAP_HEIGHT) {
    this->worldY++;
    this->y = 0;
  }

  // check for collisions
  if( newy >= 0 and
      newx >= 0 and
      newx < MAP_WIDTH and
      newy < MAP_HEIGHT and
      currentmap.mapArray[newy][newx].passable == true ) {
        // move character to new position
        this->y = newy;
        this->x = newx;
        return true;
  }

  return false;
}

const char * Player::getName() {
  return this->name.c_str();
}