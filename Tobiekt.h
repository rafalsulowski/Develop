#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;
/////////////////////////////////

class Tobiekt : public Drawable
{
	int x;
	int y;
	int sx;
	int sy;

public:
	Tobiekt(int = 0, int = 0, int = 1, int = 1);
	~Tobiekt() = default;

	void draw(RenderTarget& target, RenderStates state) const override;
	RectangleShape shape;
};

//

class Tstatek_matka : public Tobiekt
{
public:
	Tstatek_matka(int, int, int, int);
	~Tstatek_matka() = default;

	void przemiesc(float);
	int gora();
	int dol();
	int poz_x();
	int poz_y();
};

//

class Tstatek_obcy : public Tobiekt
{
public:
	Tstatek_obcy(int, int, int, int);
	Tstatek_obcy();
	~Tstatek_obcy() = default;

	void przemiesc(float);
	int poz_x();
	int poz_y();
};

//

class Tlaser : public Drawable
{
	RectangleShape shape;
	int y;

public:
	Tlaser(int = 0, int = 0, int = 0);
	Tlaser() = delete;
	~Tlaser();

	int czas_zycia;
	int cool_down;

	void draw(RenderTarget& target, RenderStates state) const override;
};

//

class Tnapisy : public Drawable
{
public:
	Font font;
	Text tekst;

	Tnapisy(string, float, float, string, int);
	~Tnapisy();

	void draw(RenderTarget& target, RenderStates state) const override;
	void set_string(string);
};
