////////////////////////////////////////////////////////////////////////////////
//
// QOffice - The office framework for Qt
// Copyright (C) 2016-2018 Nicolas Kogler
//
// This file is part of the Widget module.
//
// QOffice is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// QOffice is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with QOffice. If not, see <http://www.gnu.org/licenses/>.
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef QOFFICE_WIDGETS_DIALOGS_OFFICEWINDOW_HPP
#define QOFFICE_WIDGETS_DIALOGS_OFFICEWINDOW_HPP

#include <QOffice/Widgets/OfficeWidget.hpp>
#include <QOffice/Widgets/OfficeWindowMenu.hpp>
#include <QOffice/Widgets/Dialogs/OfficeWindowResizeArea.hpp>
#include <QOffice/Widgets/Dialogs/OfficeWindowTitlebar.hpp>

////////////////////////////////////////////////////////////////////////////////
/// \class OfficeWindow
/// \brief This class defines a window in a modern look and feel.
/// \author Nicolas Kogler (nicolas.kogler@hotmail.com)
/// \date September 24, 2017
///
////////////////////////////////////////////////////////////////////////////////
class QOFFICE_WIDGET_API OfficeWindow : public QWidget, public OfficeWidget
{
public:

    ////////////////////////////////////////////////////////////////////////////
    /// \brief Defines flags that can modify the behaviour of OfficeWindow.
    /// \enum Flag
    ///
    ////////////////////////////////////////////////////////////////////////////
    enum Flags
    {
        NoFlag           = 0x0000,
        NoCloseButton    = 0x0001,
        NoMinimizeButton = 0x0002,
        NoMaximizeButton = 0x0004,
        NoResize         = 0x0008,
        NoMaximize       = 0x0010,
        NoMenu           = 0x0020
    };

    OffDefaultDtor(OfficeWindow)
    OffDisableCopy(OfficeWindow)
    OffDisableMove(OfficeWindow)

    ////////////////////////////////////////////////////////////////////////////
    /// Initializes a new instance of OfficeWindow and specifies the given
    /// \p parent as parent window.
    ///
    /// \param[in] parent The parent window of this window.
    ///
    ////////////////////////////////////////////////////////////////////////////
    OfficeWindow(QWidget* parent = nullptr);

    ////////////////////////////////////////////////////////////////////////////
    /// Determines whether this window has a close button.
    ///
    /// \return True if it has a close button, false otherwise.
    ///
    /// \sa OfficeWindow::setFlags OfficeWindow::setCloseButtonVisible
    ///
    ////////////////////////////////////////////////////////////////////////////
    bool hasCloseButton() const;

    ////////////////////////////////////////////////////////////////////////////
    /// Determines whether this window has a maximize button.
    ///
    /// \return True if it has a maximize button, false otherwise.
    ///
    /// \sa  OfficeWindow::flags OfficeWindow::setMaximizeButtonVisible
    ///
    ////////////////////////////////////////////////////////////////////////////
    bool hasMaximizeButton() const;

    ////////////////////////////////////////////////////////////////////////////
    /// Determines whether this window has a minimize button.
    ///
    /// \return True if it has a minimize button, false otherwise.
    ///
    /// \sa  OfficeWindow::flags OfficeWindow::setMinimizeButtonVisible
    ///
    ////////////////////////////////////////////////////////////////////////////
    bool hasMinimizeButton() const;

    ////////////////////////////////////////////////////////////////////////////
    /// Determines whether this window can be resized.
    ///
    /// \return True if it can be resized, false otherwise.
    ///
    /// \sa OfficeWindow::flags OfficeWindow::setFlags
    ///
    ////////////////////////////////////////////////////////////////////////////
    bool canResize() const;

    ////////////////////////////////////////////////////////////////////////////
    /// Determines whether this window is active.
    ///
    /// \return True if it is active, false otherwise.
    ///
    ////////////////////////////////////////////////////////////////////////////
    bool isActive() const;

    ////////////////////////////////////////////////////////////////////////////
    /// Retrieves the current flags of this OfficeWindow.
    ///
    /// \return A bitwise OR combination of OfficeWindow::Flags values.
    ///
    /// \sa OfficeWindow::setFlags
    ///
    ////////////////////////////////////////////////////////////////////////////
    Flags flags() const;

    ////////////////////////////////////////////////////////////////////////////
    /// Retrieves the label menu associated to this window.
    ///
    /// \return The label menu. Items can be added to that menu afterwards.
    ///
    ////////////////////////////////////////////////////////////////////////////
    OfficeWindowMenu* labelMenu() const;

    ////////////////////////////////////////////////////////////////////////////
    /// Retrieves the quick menu associated to this window.
    ///
    /// \return The quick menu. Items can be added to that menu afterwards.
    ///
    ////////////////////////////////////////////////////////////////////////////
    OfficeWindowMenu* quickMenu() const;

    ////////////////////////////////////////////////////////////////////////////
    /// Specifies the accent for all widgets subordinated to this window.
    ///
    /// \param[in] accent The new accent to apply to all widgets.
    ///
    /// \sa OfficeWidget::accent
    ///
    ////////////////////////////////////////////////////////////////////////////
    void setAccent(Office::Accent accent) override;

    ////////////////////////////////////////////////////////////////////////////
    /// Specifies whether the window has a close button or not.
    ///
    /// \param[in] visible True to show the close button.
    ///
    /// \sa OfficeWindow::hasCloseButton OfficeWindow::setFlags
    ///
    ////////////////////////////////////////////////////////////////////////////
    void setCloseButtonVisible(bool visible);

    ////////////////////////////////////////////////////////////////////////////
    /// Specifies whether the window has a maximize button or not.
    ///
    /// \param[in] visible True to show the maximize button.
    ///
    /// \sa OfficeWindow::hasMaximizeButton OfficeWindow::setFlags
    ///
    ////////////////////////////////////////////////////////////////////////////
    void setMaximizeButtonVisible(bool visible);

    ////////////////////////////////////////////////////////////////////////////
    /// Specifies whether the window has a minimize button or not.
    ///
    /// \param[in] visible True to show the minimize button.
    ///
    /// \sa OfficeWindow::hasMinimizeButton OfficeWindow::setFlags
    ///
    ////////////////////////////////////////////////////////////////////////////
    void setMinimizeButtonVisible(bool visible);

    ////////////////////////////////////////////////////////////////////////////
    /// Specifies whether the window is resizable.
    ///
    /// \param[in] resizable True to be able to resize window.
    ///
    /// \sa OfficeWindow::canResize OfficeWindow::setFlags
    ///
    ////////////////////////////////////////////////////////////////////////////
    void setResizable(bool resizable);

    ////////////////////////////////////////////////////////////////////////////
    /// Specifies the flags for this office window. The flags specify window
    /// button visibility, resize capability and more. Multiple flags can be
    /// specified by bitwise OR'ing multiple OfficeWindow::Flags values together.
    ///
    /// \param[in] flags The new flags.
    ///
    /// \sa OfficeWindow::flags
    ///
    ////////////////////////////////////////////////////////////////////////////
    void setFlags(Flags flags);

    ////////////////////////////////////////////////////////////////////////////
    /// Retrieves the currently active window.
    ///
    /// \return The active window or nullptr.
    ///
    ////////////////////////////////////////////////////////////////////////////
    static OfficeWindow* activeWindow();

    enum WindowState
    {
        StateNone,
        StateDrag,
        StateResize
    };

    enum ResizeDirection
    {
        ResizeNone   = 0x0000,
        ResizeLeft   = 0x0001,
        ResizeTop    = 0x0002,
        ResizeRight  = 0x0004,
        ResizeBottom = 0x0008
    };

protected:

    virtual void accentUpdateEvent() override;
    virtual void paintEvent(QPaintEvent*) override;
    virtual void resizeEvent(QResizeEvent*) override;
    virtual void focusInEvent(QFocusEvent*) override;
    virtual void focusOutEvent(QFocusEvent*) override;
    virtual void showEvent(QShowEvent*) override;
    virtual bool event(QEvent*) override;

private:

    ////////////////////////////////////////////////////////////////////////////
    // Functions
    ////////////////////////////////////////////////////////////////////////////
    void generateDropShadow();
    void updateResizeRectangles();
    void updateResizeWidgets();
    void updateLayoutPadding();

    ////////////////////////////////////////////////////////////////////////////
    // Members
    ////////////////////////////////////////////////////////////////////////////
    priv::ResizeArea* m_resizeTopLeft;
    priv::ResizeArea* m_resizeTopRight;
    priv::ResizeArea* m_resizeBottomLeft;
    priv::ResizeArea* m_resizeBottomRight;
    priv::ResizeArea* m_resizeTop;
    priv::ResizeArea* m_resizeLeft;
    priv::ResizeArea* m_resizeBottom;
    priv::ResizeArea* m_resizeRight;
    priv::Titlebar*   m_titleBar;
    WindowState       m_stateWindow;
    Flags             m_flagsWindow;
    QPixmap           m_dropShadow;
    QRect             m_clientRectangle;
    bool              m_tooltipVisible;

    ////////////////////////////////////////////////////////////////////////////
    // Metadata
    ////////////////////////////////////////////////////////////////////////////
    Q_OBJECT
    Q_PROPERTY(bool Resizable READ canResize WRITE setResizable)
    Q_PROPERTY(bool CloseButton READ hasCloseButton WRITE setCloseButtonVisible)
    Q_PROPERTY(bool MaximizeButton READ hasMaximizeButton WRITE setMaximizeButtonVisible)
    Q_PROPERTY(bool MinimizeButton READ hasMinimizeButton WRITE setMinimizeButtonVisible)
    Q_PROPERTY(Office::Accent Accent READ accent WRITE setAccent)

    friend class priv::ResizeArea;
    friend class priv::Titlebar;
    friend class OfficeTooltip;
};

OffEnumOperators(OfficeWindow::Flags)
OffEnumOperators(OfficeWindow::ResizeDirection)

#endif

////////////////////////////////////////////////////////////////////////////////
/// \class OfficeWindow
/// \ingroup Widget
///
/// While having functionality that is typical to windows, such as resize, drag,
/// window buttons and title text, the OfficeWindow also contains two menus. One
/// menu is called the "label menu" and is located on the left hand side of the
/// window. It contains items that function as hyperlinks. One can connect to
/// the signals they emit and do anything they like. The other menu is called
/// the "quick menu" and is located on the right hand side of the window. It
/// contains items that function as clickable image-buttons. One can connect to
/// the signals they emit and do anything they like. Both of these menus are
/// capable of showing tooltips for every item. The following example shows how
/// to set up a simple OfficeWindow with some menu items.
///
/// \code
/// #include <QOfficeWindow>
/// #include <QApplication>
///
/// int main(int argc, char *argv[])
/// {
///     QApplication a(argc, argv);
///     OfficeWindow w;
///
///     w.setWindowTitle("QOffice example");
///     w.labelMenu()->addLabelItem(0, "Item1", "This is a dummy item.");
///     w.quickMenu()->addQuickItem(0, QPixmap(""), "This is a dummy item.");
///     w.show();
///
///     QObject::connect(w.labelMenu(), &OfficeWindowMenu::itemClicked, [&](int id)
///         {
///             qDebug() << "Item with id" << id << "was clicked.";
///         });
///     QObject::connect(w.labelMenu(), &OfficeWindowMenu::helpRequested, [&](int id)
///         {
///             qDebug() << "Help was requested from item with id" << id << ".";
///         });
///
///     return a.exec();
/// }
/// \endcode
///
/// Now try to click on the item or request help when its tooltip is shown by
/// pressing F1 or clicking the help text link.
///
////////////////////////////////////////////////////////////////////////////////
