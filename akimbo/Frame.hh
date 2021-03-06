#ifndef AKIMBO_FRAME_HH
#define AKIMBO_FRAME_HH

#include "Font.hh"
#include "Texture.hh"
#include "Vector2.hh"

#include "SDL2/SDL_render.h"

namespace Akimbo {
class Frame
{
public:
	friend class Window;
	~Frame();

	void color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
	void drawBox(Vec2 position, Vec2 size, bool filled);
	void drawLine(Vec2 from, Vec2 to);
	void drawDot(Vec2 position);

	void drawTexture(Texture& texture, Vec2 position, Vec2 size);
	void drawCharacter(char chr, Font& font, Vec2 position, Vec2 size);
	void drawText(const std::string& str, Font& font, Vec2 position, Vec2 size);

protected:
	//	Only Window can access the constructor, so only it can start rendering
	Frame(SDL_Window* w, Vec2& cameraPosition, Vec2& cameraRadius);

private:
	//	Converts a world-space position to a screen-space position
	Vec2 convert(Vec2 position);

	SDL_Window* window;
	Vec2& cameraPosition;
	Vec2& cameraRadius;
};

}

#endif
