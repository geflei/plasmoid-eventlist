/*
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>
 *
 *   Copyright (C) 2008 by Javier Goday <jgoday@gmail.com>
 *   Copyright (C) 2009 by gerdfleischer <gerdfleischer@web.de>
 */

#ifndef EVENTAPPLET_H
#define EVENTAPPLET_H

// kde ui autogenerated file
#include "ui_eventappletformatconfig.h"
#include "ui_eventappletcolorconfig.h"

// Qt headers
#include <QMap>

// Plasma includes
#include <Plasma/PopupApplet>
#include <Plasma/DataEngine>
#include <Plasma/TreeView>
#include <Plasma/Label>

class QTimer;
class QModelIndex;
class QAction;
class KConfigDialog;
class EventModel;
class EventItemDelegate;

class EventApplet : public Plasma::PopupApplet
{
    Q_OBJECT

public:
    EventApplet(QObject *parent, const QVariantList &args);
    ~EventApplet();

    void init();
    QGraphicsWidget *graphicsWidget();
    virtual QList<QAction *> contextualActions();

public slots:
    void dataUpdated(const QString &name, const Plasma::DataEngine::Data &data);

private slots:
    void slotOpenEvent(const QModelIndex &index);
    void openEventFromMenu();
    void slotAddEvent();
    void passedTimerExpired();

protected slots:
    void configAccepted();

protected:
    void createConfigurationInterface(KConfigDialog *parent);

private:
    void updateCategories(const QStringList &categories);
    void updateColors(const QMap <QString, QVariant> &colors);
    void updateEventList(const QList <QVariant> &events);
    void updateAkonadiState(bool isRunning);
    void setupActions();
    void colorizeBirthdayAndAnniversaries(QColor birthdayColor, QColor anniversariesColor);
    void colorizeUrgentAndPassed();

private:
    Plasma::DataEngine *m_engine;
    QGraphicsWidget *m_graphicsWidget;
    EventModel *m_model;
    Plasma::TreeView *m_view;
    EventItemDelegate *m_delegate;
    Ui::EventAppletFormatConfig m_formatConfigUi;
    Ui::EventAppletColorConfig m_colorConfigUi;
    bool m_useColors;
    int m_urgency, m_checkInterval;
    QColor m_urgentBg, m_passedFg;
    QTimer *m_passedTimer;
    QList<QAction *> actions;
};

#endif
