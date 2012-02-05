/***************************************************************************
 *   Copyright (C) 2012 by Francesco Cecconi                               *
 *   francesco.cecconi@gmail.com                                           *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License.        *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef BOOKMARKMANAGER_H
#define BOOKMARKMANAGER_H

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtGui/QTreeWidgetItem>

#include "history.h"
#include "memorytools.h"

class MainWindow;

class BookmarkManager : public QObject
{
    Q_OBJECT

public:
    BookmarkManager(MainWindow* parent);
    ~BookmarkManager();
    /**
     * Restore all saved values on treeWidget
     */
    void restoreAllHistoryValues();
    /**
     * Save Vulnerability search address in bookmark
     */
    void saveAddressToBookmark(const QString addressName, const QString address);
    /**
     * Delete Vulnerability search address in bookmark
     */
    void deleteAddressFromBookmark(const QString addressName);
    /**
     * Save Host (ip or Dns or ip-range) to bookmark
     */
    void saveHostToBookmark(const QString hostName, int cacheLimit);
    /**
     * Save Vulnerability service to bookmark
     */
    void saveServiceToBookmark(const QString service, int cacheLimit);
    /**
     * Return stored host list from bookmark
     */
    QStringList getHostListFromBookmark();
    /**
     * Return stored Services list from bookmark
     */
    QStringList getServicesListFromBookmark();
    bool isBookmarkHostListEmpty();
    bool isBookmarkServicesListEmpty();

private:
    MainWindow* m_ui;
    int m_userId;
    QList<QTreeWidgetItem*> m_treeloghlist;
    QList<QTreeWidgetItem*> m_treebookparlist;
    QList<QTreeWidgetItem*> m_treebookvulnlist;
    QList<QTreeWidgetItem*> m_treewidgetvulnlist;

public slots:
    /**
     * Save selected Vulnerability service, host from bookmark (contextual menu)
     */
    void saveItemToBookmarks();
    /**
     * Delete selected Vulnerability service, host from bookmark (contextual menu)
     */
    void deleteItemFromBookmark();
    /**
     * Save scan parameters to bookmark
     */
    void saveParametersToBookmarks(const QString profileName, const QString profileParameters);
    /**
     * Delete selected scan parameters to bookmark (contextual menu)
     */
    void deleteParametersFromBookmark();
    void startParametersToBookmarksDialog();

};

#endif // BOOKMARKMANAGER_H