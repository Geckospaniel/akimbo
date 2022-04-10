#ifndef AKIMBO_UI_WIDGET_HH
#define AKIMBO_UI_WIDGET_HH

#include "Constraint.hh"
#include "../Frame.hh"

namespace Akimbo
{
	class Core;
}

namespace Akimbo::UI {

class Widget
{
public:
	Widget(Core* core, const EdgeConstraints& edges);

	virtual void onRender(Frame& frame);
	virtual void adjustPosition(Vec2 uiRadius);
	virtual void onResize(Vec2 resizeFactor) {};

	void setBackgroundColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
	void setBackgroundImage(Texture& texture);
	void removeBackgroundImage();

	//	Helpers to get some constrain with a gap
	/*	FIXME
	 *
	 *	The gap could be negated for bottom and right so that when gap is 0.1f, and constraint
	 *	is right, the gap goes left instead of right */
	Constraint top(float gap, bool isPercentage) { return Constraint(edges.top, gap, isPercentage); }
	Constraint left(float gap, bool isPercentage) { return Constraint(edges.left, gap, isPercentage); }
	Constraint right(float gap, bool isPercentage) { return Constraint(edges.right, gap, isPercentage); }
	Constraint bottom(float gap, bool isPercentage) { return Constraint(edges.bottom, gap, isPercentage); }

protected:
	Core* core;
	Widget* parent = nullptr;

	Vec2 position;
	Vec2 size;

	//	Widget background stuff
	uint8_t bgRed = 0;
	uint8_t bgGreen = 0;
	uint8_t bgBlue = 0;
	uint8_t bgAlpha = 0;
	Texture* bgImage = nullptr;

	EdgeConstraints edges;
};

}

#endif