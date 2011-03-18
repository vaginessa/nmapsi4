/***************************************************************************
 *   Copyright (C) 2007-2011 by Francesco Cecconi                          *
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

#include "../../mainwin.h"

void nmapClass::searchVulnNG()
{
    if (comboVulnRis->currentText().isEmpty())
        return;

    // save current search on history
    history = new logHistory("nmapsi4/cacheVuln", hostCache);
    history->addItemHistory(comboVulnRis->currentText());
    delete history;
    // default action settings
    actSearch->setEnabled(false);
    actStop->setEnabled(true);
    actBack->setEnabled(true);
    actForward->setEnabled(true);

    QString finalUrlString_("");
    QString tmpSearchString_("");
    // search string from QComboBox
    tmpSearchString_ = comboVulnRis->currentText();
    // space to + for correct search string format
    tmpSearchString_.replace(QString(" "), QString("+"));

    // create QMap for default profile
    QMap<QString, QString> tmpUrlMap_ = defaultUrlVuln();
    
    // selection url from key for search
    if (comboWebV->currentIndex() < tmpUrlMap_.size()) {
	// is a default url in QMap
	finalUrlString_ = tmpUrlMap_.value(comboWebV->currentText());
    } else {
	// TODO:: isn't a default url in QMap but in treeWidget
    }
    
    finalUrlString_.append(tmpSearchString_);
    
    QUrl urlFinal(finalUrlString_);
    QWebView *result_;

    // check for tab rilecation
    if(viewVuln->url().toString().contains("about:blank")) {
	// first tab isEmpty
        viewVuln->load(urlFinal);
        tWresult->setTabText(0,comboVulnRis->currentText());
    } else {
	// create new tab for QWebView
        result_ = new QWebView();
        webViewList.push_back(result_);
        result_->load(urlFinal);
        tWresult->addTab(result_,comboVulnRis->currentText());
        connect(result_, SIGNAL(loadProgress(int)),
                progressWeb, SLOT(setValue(int)));
        connect(result_, SIGNAL(loadFinished(bool)),
                this, SLOT(vulnPostScan()));
    }
}
