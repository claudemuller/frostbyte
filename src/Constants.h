#ifndef FROSTBYTE_CONSTANTS_H
#define FROSTBYTE_CONSTANTS_H

#include <SDL.h>

const unsigned int FPS = 60;
const unsigned int FRAME_TARGET_TIME = (1000 / FPS);

const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 600;

enum LayerType {
	TILEMAP_LAYER,
	VEGETATION_LAYER,
	ENEMY_LAYER,
	PLAYER_LAYER,
	PROJECTILE_LAYER,
	UI_LAYER
};

const unsigned int NUM_LAYERS = 6;

const SDL_Color WHITE = {255, 255, 255, 255};
const SDL_Color GREEN = {0, 255, 0, 255};
const SDL_Color RED = {255, 0, 0, 255};

#endif //FROSTBYTE_CONSTANTS_H
