#ifndef AKIMBO_UI_WIDGET_HH
#define AKIMBO_UI_WIDGET_HH

#include "../KeyboardState.hh"
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

	//	Widgets should never be copied
	Widget(const Widget& rhs) = delete;
	Widget& operator=(const Widget& rhs) = delete;

	//	Functions that get called on each frame
	virtual void onRender(Frame& frame);
	virtual void onUpdate(double delta);

	//	Function that gets called when the user clicks this widget
	virtual void onMouseClick(Vec2, int button);

	//	Function that gets called when a key is pressed while this widget is active
	virtual void onKeyPress(char key);
	virtual void onKeyPress(Key key);

	//	Function that gets called when the widget is resized
	virtual void onResize(Vec2 resizeFactor);

	//	Function that gets called when constraints should be updated
	//	NOTE Do not override or bad stuff happens
	virtual void adjustPosition(Vec2 uiRadius);

	//	Widget background setters
	void setBackgroundColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
	void setBackgroundImage(Texture& texture);
	void removeBackgroundImage();

	//	Is a point inside this widget
	virtual Widget* isInside(Vec2 point);

	//	Helpers to get constraints relative to this widget with units
	Constraint top(float units = 0.0f);
	Constraint left(float units = 0.0f);
	Constraint right(float units = 0.0f);
	Constraint bottom(float units = 0.0f);

	//	Helpers to get constraints relative to this widget with percents
	Constraint top(int percents);
	Constraint left(int percents);
	Constraint right(int percents);
	Constraint bottom(int percents);

protected:
	bool isRelativeConstraint(Constraint& constraint);

	Core* core;
	Widget* parent = nullptr;

	Vec2 position;
	Vec2 size;

private:
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
