/***************************************************************************
 *   Copyright (C) 2009-2011 by Francesco Cecconi                          *
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

#include "lookUpT.h"


internalLookup::lookUpT::lookUpT(const QString hostname, QObject *parent) : m_host(hostname), m_par(parent)
{
    killLookup();
}

void internalLookup::lookUpT::run() 
{
    qRegisterMetaType<QHostInfo>("QHostInfo");
    m_info = QHostInfo::fromName(m_host);

    if(m_info.error() != QHostInfo::NoError 
        && m_info.error() != QHostInfo::UnknownError
        && m_info.error() != QHostInfo::HostNotFound) 
    {
#ifdef LOOKUP_NO_THREAD
         qDebug() << "Lookup failed:" << info.errorString();
#endif
         emit threadEnd(m_info, -1, m_host);
         return;
    }
    emit threadEnd(m_info, 1, m_host);
}

void internalLookup::lookUpT::killLookup() 
{
#ifdef LOOKUP_NO_THREAD
    qDebug() << "Lookup::kill --> call";
#endif
    m_info.abortHostLookup(m_info.lookupId());
}