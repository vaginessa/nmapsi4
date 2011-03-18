/***************************************************************************
 *   Copyright (C) 2011 by Francesco Cecconi                               *
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


QMap<QString, QString> nmapClass::defaultUrlVuln() const {
    // define a QMap with static url Name + url
    QMap<QString, QString> urlMap_;
    
    // set default name+value url
    urlMap_.insert("www.securityfocus.com",
		   "http://www.securityfocus.com/swsearch?sbm=bid&submit=Search%21&metaname=alldoc&sort=swishrank&query=");
    urlMap_.insert("cve.mitre.org","http://cve.mitre.org/cgi-bin/cvekey.cgi?keyword=");
    urlMap_.insert("secunia.com","http://secunia.com/advisories/search/?search=");
    
    return urlMap_;
}

