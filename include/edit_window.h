/**
 * Copyright (c) 2019-2022 WineGUI
 *
 * \file    edit_window.h
 * \brief   Edit GTK+ window class
 * \author  Melroy van den Berg <webmaster1989@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include <gtkmm.h>

using std::string;

// Forward declaration
class BottleItem;

/**
 * \class EditWindow
 * \brief GTK+ Window class for the settings
 */
class EditWindow : public Gtk::Window
{
public:
  // Signals
  sigc::signal<void,
               Glib::ustring&,
               Glib::ustring&,
               bool&,
               BottleTypes::Windows,
               BottleTypes::Bit,
               BottleTypes::AudioDriver>
      update_machine;
  sigc::signal<void> remove_machine; /*!< remove button clicked signal */

  explicit EditWindow(Gtk::Window& parent);
  virtual ~EditWindow();

  void Show();
  void SetActiveBottle(BottleItem* bottle);
  void ResetActiveBottle();
  void BottleRemoved();

protected:
  // Child widgets
  Gtk::Box vbox;
  Gtk::Box hbox_buttons;
  Gtk::Grid edit_grid;

  Gtk::Label header_edit_label;
  Gtk::Label name_label;
  Gtk::Label windows_version_label;
  Gtk::Label audiodriver_label;
  Gtk::Label virtual_desktop_resolution_label;
  Gtk::Entry name_entry;
  Gtk::Entry virtual_desktop_resolution_entry;
  Gtk::ComboBoxText windows_version_combobox;
  Gtk::ComboBoxText audiodriver_combobox;
  Gtk::CheckButton virtual_desktop_check;

  Gtk::Button save_button;   /*!< save button */
  Gtk::Button cancel_button; /*!< cancel button */
  Gtk::Button delete_button; /*!< delete button */

  // Buttons second row
  Gtk::ToolButton wine_config_button; /*!< Winecfg button */

private:
  // Signal handlers
  void on_cancel_button_clicked();
  void on_save_button_clicked();
  void on_virtual_desktop_toggle();

  // Member functions
  void ShowVirtualDesktopResolution();
  void HideVirtualDesktopResolution();

  BottleItem* activeBottle; /*!< Current active bottle */
};
