//  $Id$
//
//  SuperTux
//  Copyright (C) 2004 Tobias Glaesser <tobi.web@gmx.de>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
//  02111-1307, USA.

#ifndef SUPERTUX_BUTTON_H
#define SUPERTUX_BUTTON_H

#include <vector>
#include "screen/texture.h"

// TODO
#if 0

enum ButtonState {
  BUTTON_NONE = -1,
  BUTTON_CLICKED,
  BUTTON_PRESSED,
  BUTTON_HOVER,
  BUTTON_WHEELUP,
  BUTTON_WHEELDOWN,
  BUTTON_DEACTIVE
};

class ButtonPanel;

class Button
{
  friend class ButtonPanel;

public:
  Button(Surface* icon_file, const std::string& info, SDLKey shortcut,
      int x, int y, int mw = -1, int h = -1);
  Button(const std::string& icon_name, const std::string& info, SDLKey shortcut,
      int x, int y, int mw = -1, int h = -1);
  
  ~Button();
  void event(SDL_Event& event);
  void draw();
  int get_state();
  void set_active(bool active) { active ? state = BUTTON_NONE : state = BUTTON_DEACTIVE; };
  void add_icon(const std::string& imagefile, int mw, int mh);
  SDL_Rect get_pos() { return rect; }
  int get_tag(){return tag; }
  void set_drawable(Drawable* newdrawable)
  { drawable = newdrawable; }

private:
  static Timer popup_timer;
  Drawable* drawable;
  std::vector<Surface*> icon;
  std::string info;
  SDLKey shortcut;
  SDL_Rect rect;
  bool show_info;
  ButtonState state;
  int tag;
};

class ButtonPanel
{
public:
  ButtonPanel(int x, int y, int w, int h);
  ~ButtonPanel();
  void draw();
  Button* event(SDL_Event &event);
  void additem(Button* pbutton, int tag);
  Button* button_panel_event(SDL_Event& event);
  void set_button_size(int w, int h);
  Button* manipulate_button(int i);
  void highlight_last(bool b);
  void set_last_clicked(unsigned int last)
  { if(hlast) { if(item.size() >= last) { last_clicked = item.begin() + last; } } };

private:
  int bw, bh;
  bool hlast;
  bool hidden;
  SDL_Rect rect;
  std::vector<Button*> item;
  std::vector<Button*>::iterator last_clicked;
};
#endif

#endif /*SUPERTUX_BUTTON_H*/
