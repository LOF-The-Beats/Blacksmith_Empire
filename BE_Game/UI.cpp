#include "precomp.h"
#include "UI.h"

UI::UI()
{
}

void UI::UI_Layout(Surface* screen)
{
	screen->Line(0, 50, SCRWIDTH, 50, 0xFF00FF);
	screen->Line(SCRWIDTH / 3 * 1, 0, SCRWIDTH / 3 * 1, 50, 0xFF00FF);
	screen->Line(SCRWIDTH / 3 * 2, 0, SCRWIDTH / 3 * 2, 50, 0xFF00FF);
	// top tekst


	// left bar
	screen->Line(150, 50, 150, SCRHEIGHT, 0xFF00FF);
	// Locaton buttons
	screen->Box(0, 50, 150, SCRHEIGHT / 10 * 1 + 50, 0xFF00FF);
	screen->Box(0, 50, 150, SCRHEIGHT / 10 * 2 + 50, 0xFF00FF);
	screen->Box(0, 50, 150, SCRHEIGHT / 10 * 3 + 50, 0xFF00FF);
	screen->Box(0, 50, 150, SCRHEIGHT / 10 * 4 + 50, 0xFF00FF);
	screen->Box(0, 50, 150, SCRHEIGHT / 10 * 5 + 50, 0xFF00FF);
	screen->Box(0, 50, 150, SCRHEIGHT / 10 * 6 + 50, 0xFF00FF);
	screen->Box(0, 50, 150, SCRHEIGHT / 10 * 7 + 50, 0xFF00FF);
	screen->Box(0, 50, 150, SCRHEIGHT / 10 * 8 + 50, 0xFF00FF);

	screen->Print("Forest", 50, SCRHEIGHT / 10 * 1, 0xFF00FF);
}


