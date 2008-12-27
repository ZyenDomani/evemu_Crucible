/*
	------------------------------------------------------------------------------------
	LICENSE:
	------------------------------------------------------------------------------------
	This file is part of EVEmu: EVE Online Server Emulator
	Copyright 2006 - 2008 The EVEmu Team
	For the latest information visit http://evemu.mmoforge.org
	------------------------------------------------------------------------------------
	This program is free software; you can redistribute it and/or modify it under
	the terms of the GNU Lesser General Public License as published by the Free Software
	Foundation; either version 2 of the License, or (at your option) any later
	version.

	This program is distributed in the hope that it will be useful, but WITHOUT
	ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
	FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License along with
	this program; if not, write to the Free Software Foundation, Inc., 59 Temple
	Place - Suite 330, Boston, MA 02111-1307, USA, or go to
	http://www.gnu.org/copyleft/lesser.txt.
	------------------------------------------------------------------------------------
	Author:		Zhur
*/
#include "EvemuPCH.h"


PyCallable_Make_InnerDispatcher(MissionMgrService)



/*
class MissionMgrBound
: public PyBoundObject {
public:
	
	PyCallable_Make_Dispatcher(MissionMgrBound)
	
	MissionMgrBound(PyServiceMgr *mgr, MissionMgrDB *db)
	: PyBoundObject(mgr, "MissionMgrBound"),
	  m_db(db),
	  m_dispatch(new Dispatcher(this))
	{
		_SetCallDispatcher(m_dispatch);
		
		PyCallable_REG_CALL(MissionMgrBound, )
		PyCallable_REG_CALL(MissionMgrBound, )
	}
	virtual ~MissionMgrBound() { delete m_dispatch; }
	virtual void Release() {
		//I hate this statement
		delete this;
	}
	
	PyCallable_DECL_CALL()
	PyCallable_DECL_CALL()

protected:
	MissionMgrDB *const m_db;
	Dispatcher *const m_dispatch;   //we own this
};
*/


MissionMgrService::MissionMgrService(PyServiceMgr *mgr, DBcore *db)
: PyService(mgr, "missionMgr"),
m_dispatch(new Dispatcher(this)),
m_db(db)
{
	_SetCallDispatcher(m_dispatch);

	PyCallable_REG_CALL(MissionMgrService, GetMyCourierMissions)
}

MissionMgrService::~MissionMgrService() {
	delete m_dispatch;
}


/*
PyBoundObject *MissionMgrService::_CreateBoundObject(Client *c, PyRepTuple *bind_args) {
	_log(CLIENT__MESSAGE, "MissionMgrService bind request for:");
	bind_args->Dump(CLIENT__MESSAGE, "    ");

	return(new MissionMgrBound(m_manager, &m_db));
}*/


PyResult MissionMgrService::Handle_GetMyCourierMissions(PyCallArgs &call) {
	codelog(SERVICE__ERROR, "GetMyCourierMissions unimplemented");
	//SELECT * FROM courierMissions
	return NULL;
}




























