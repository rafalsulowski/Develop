#include "pch.h"
#include "Tobiekt.h"
#include <SFML/Graphics.hpp>

using namespace sf;
////////////////////////////////////////////

Tobiekt::Tobiekt(int a, int b, int c, int d) : x{ a }, y{ b }, sx{ c }, sy{ d }
{
	shape.setPosition(x, y);
	shape.setSize(Vector2f(sx, sy));
	shape.setFillColor(Color::Green);
	shape.setOrigin(sx / 2, sy / 2);
}

void Tobiekt::draw(RenderTarget & target, RenderStates state) const
{
	target.draw(shape, state);
}




// Gracz \/
Tstatek_matka::Tstatek_matka(int a, int b, int c, int d) : Tobiekt(a, b, c, d)
{ }

void Tstatek_matka::przemiesc(float v)
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Up) && this->gora() > 50)
		shape.move(0, -v);
	else if (Keyboard::isKeyPressed(Keyboard::Key::Down) && this->dol() < 450)
		shape.move(0, v);
	else
		shape.move(0, 0);

}

int Tstatek_matka::gora()
{
	return (this->shape.getPosition().y - shape.getSize().y / 2 + 1);
}

int Tstatek_matka::dol()
{
	return (this->shape.getPosition().y + shape.getSize().y / 2);
}

int Tstatek_matka::poz_x()
{
	return shape.getPosition().x;
}

int Tstatek_matka::poz_y()
{
	return shape.getPosition().y;
}




//przeciwnicy \/
Tstatek_obcy::Tstatek_obcy(int a, int b, int c, int d) : Tobiekt(a, b, c, d)
{
	shape.setFillColor(Color::Blue);
}

Tstatek_obcy::Tstatek_obcy()
{
}

void Tstatek_obcy::przemiesc(float v)
{
	shape.move(-v, 0);
}

int Tstatek_obcy::poz_x()
{
	return shape.getPosition().x;
}

int Tstatek_obcy::poz_y()
{
	return shape.getPosition().y;
}




//Laser \/
Tlaser::Tlaser(int a, int b, int c) : y{ b }, cool_down{ c }
{
	shape.setPosition(a, y);
	shape.setFillColor(Color::Red);
	shape.setSize(Vector2f(750.f, 3.f));
	shape.setOrigin(Vector2f(0.f, shape.getSize().y / 2));
}

Tlaser::~Tlaser()
{
}

void Tlaser::draw(RenderTarget & target, RenderStates state) const
{
	target.draw(shape, state);
}




//Napisy \/
Tnapisy::Tnapisy(string fo, float a, float b, string te, int c)
{
	
	font.loadFromFile(fo);
	tekst.setCharacterSize(c);
	tekst.setFillColor(Color::Yellow);
	tekst.setPosition(Vector2f(a, b));
	tekst.setString(te);
	tekst.setFont(font);
}

Tnapisy::~Tnapisy()
{
}

void Tnapisy::draw(RenderTarget & target, RenderStates state) const
{
	target.draw(tekst, state);
}

void Tnapisy::set_string(string napis)
{
	tekst.setString(napis);
}
