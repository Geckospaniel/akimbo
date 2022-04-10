#include "Widget.hh"
#include "../Core.hh"
#include "../Debug.hh"

namespace Akimbo::UI
{

Widget::Widget(Core* core, const EdgeConstraints& edges)
	: core(core), edges(edges), size(1.0f, 1.0f)
{
}

void Widget::adjustPosition(Vec2 uiRadius)
{
	//	Update the position of each constrain
	edges.top.updatePosition(uiRadius.y);
	edges.left.updatePosition(uiRadius.x);
	edges.right.updatePosition(uiRadius.x);
	edges.bottom.updatePosition(uiRadius.y);

	//	Calculate the position and size of the widget
	position = Vec2(edges.left, edges.top);
	Vec2 newSize = Vec2(edges.right, edges.bottom) - position;

	//	How mcuh did the widget size change
	Vec2 relation = size / newSize;
	size = newSize;

	//	Do resizing if necessary
	onResize(relation);
}

void Widget::onRender(Frame& frame)
{
	//	If there's a background image, draw it
	if(bgImage)
	{
		frame.drawTexture(*bgImage, position, size);
		return;
	}

	//	Is there any background color
	bool transparent = !bgAlpha || (!bgRed && !bgGreen && !bgBlue);

	//	If there is a background color, draw a filled box with that color
	if(!transparent)
	{
		frame.color(bgRed, bgGreen, bgBlue);
		frame.drawBox(position, size, true);
	}

	DBG(
		frame.color(255, 0, 0);	
		frame.drawBox(position, size, false);
	);
}

void Widget::setBackgroundColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	bgRed = r;
	bgGreen = g;
	bgBlue = b;
	bgAlpha = a;
}

void Widget::setBackgroundImage(Texture& texture)
{
	bgImage = &texture;
}

void Widget::removeBackgroundImage()
{
	bgImage = nullptr;
}

}