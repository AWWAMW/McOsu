//================ Copyright (c) 2016, PG, All rights reserved. =================//
//
// Purpose:		pause menu (while playing)
//
// $NoKeywords: $
//===============================================================================//

#ifndef OSUPAUSEMENU_H
#define OSUPAUSEMENU_H

#include "OsuScreen.h"

class Osu;
class OsuSongBrowser;
class CBaseUIContainer;
class OsuPauseMenuButton;

class OsuPauseMenu : public OsuScreen
{
public:
	OsuPauseMenu(Osu *osu);
	virtual ~OsuPauseMenu();

	void draw(Graphics *g);
	void update();

	void onKeyDown(KeyboardEvent &e);
	void onChar(KeyboardEvent &e);

	void onResolutionChange(Vector2 newResolution);

	void setVisible(bool visible);

private:
	void updateLayout();
	void updateButtons();
	OsuPauseMenuButton *addButton();
	void setButton(int i, Image *img);

	void onContinueClicked();
	void onRetryClicked();
	void onBackClicked();

	void scheduleVisibilityChange(bool visible);

	Osu *m_osu;

	CBaseUIContainer *m_container;
	bool m_bScheduledVisibilityChange;
	bool m_bScheduledVisibility;

	std::vector<OsuPauseMenuButton*> m_buttons;
};

#endif