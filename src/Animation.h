#ifndef FROSTBYTE_ANIMATION_H
#define FROSTBYTE_ANIMATION_H

class Animation {
public:
	Animation();
	Animation(unsigned int index, unsigned int numFrames, unsigned int speed);

	unsigned int index;
	unsigned int numFrames;
	unsigned int speed;
};

#endif //FROSTBYTE_ANIMATION_H
