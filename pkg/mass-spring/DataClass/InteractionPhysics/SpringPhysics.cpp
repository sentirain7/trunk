/*************************************************************************
*  Copyright (C) 2004 by Olivier Galizzi                                 *
*  olivier.galizzi@imag.fr                                               *
*                                                                        *
*  This program is free software; it is licensed under the terms of the  *
*  GNU General Public License v2 or later. See file LICENSE for details. *
*************************************************************************/

#include "SpringPhysics.hpp"

SpringPhysics::SpringPhysics()
{
	createIndex();
}

SpringPhysics::~SpringPhysics()
{
}


YADE_PLUGIN((SpringPhysics));