#include "Label.hh"

namespace Akimbo::UI {

Label::Label(Core* core, const EdgeConstraints& edges, Font& font)
	: Widget(core, edges), font(font)
{
}

void Label::onRender(Render& render)
{
	render.text(text, font, position, size);
}

void Label::setText(const std::string& str)
{
	text = str;
}

}
