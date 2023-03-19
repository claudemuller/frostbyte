#include <iostream>
#include <SDL2/SDL_image.h>
#include <glm/glm.hpp>
#include "Game.h"

Game::Game() {
	isRunning = false;
}

Game::~Game() {

}

void Game::init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cerr << "error initing SDL" << std::endl;
		return;
	}

	SDL_DisplayMode displayMode;
	SDL_GetCurrentDisplayMode(1, &displayMode);
	windowWidth = 800; //displayMode.w;
	windowHeight = 600; //displayMode.h;

	window = SDL_CreateWindow(
			NULL,
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			windowWidth,
			windowHeight,
			SDL_WINDOW_BORDERLESS
	);
	if (window == nullptr) {
		std::cerr << "error creating window" << std::endl;
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		std::cerr << "error creating renderer" << std::endl;
		return;
	}

	SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
	isRunning = true;
}

void Game::run() {
	setup();

	while (isRunning) {
		processInput();
		update();
		render();
	}
}

glm::vec2 playerPos;
glm::vec2 playerVelocity;

void Game::setup() {
	playerPos = glm::vec2(10.0, 20.0);
	playerVelocity = glm::vec2(1.0, 0.0);
}

void Game::processInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				isRunning = false;
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					isRunning = false;
				}
				break;
		}
	}
}

void Game::update() {
	playerPos += playerVelocity;
}

void Game::render() {
	SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
	SDL_RenderClear(renderer);

	SDL_Surface *surface = IMG_Load("./assets/images/tank-tiger-right.png");
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	SDL_Rect destRect = {
		static_cast<int>(playerPos.x),
		static_cast<int>(playerPos.y),
		32,
		32
	};
	SDL_RenderCopy(renderer, texture, NULL, &destRect);
	SDL_DestroyTexture(texture);

	SDL_RenderPresent(renderer);
}

void Game::cleanup() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}