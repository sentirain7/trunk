/*************************************************************************
*  Copyright (C) 2004 by Janek Kozicki                                   *
*  cosurgi@berlios.de                                                    *
*                                                                        *
*  This program is free software; it is licensed under the terms of the  *
*  GNU General Public License v2 or later. See file LICENSE for details. *
*************************************************************************/

#ifndef DATARECORDER_HPP
#define DATARECORDER_HPP

#include "StandAloneEngine.hpp"

class DataRecorder : public StandAloneEngine
{
	public :
		DataRecorder() {};
		virtual ~DataRecorder() {};

	REGISTER_CLASS_NAME(DataRecorder);	
	REGISTER_BASE_CLASS_NAME(StandAloneEngine);
};

REGISTER_SERIALIZABLE(DataRecorder,false);

#endif // DATARECORDER_HPP