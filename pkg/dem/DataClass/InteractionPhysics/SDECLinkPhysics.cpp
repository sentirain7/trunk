/*************************************************************************
*  Copyright (C) 2004 by Olivier Galizzi                                 *
*  olivier.galizzi@imag.fr                                               *
*  Copyright (C) 2004 by Janek Kozicki                                   *
*  cosurgi@berlios.de                                                    *
*                                                                        *
*  This program is free software; it is licensed under the terms of the  *
*  GNU General Public License v2 or later. See file LICENSE for details. *
*************************************************************************/

#include "SDECLinkPhysics.hpp"


SDECLinkPhysics::SDECLinkPhysics()
{
	createIndex();
}

SDECLinkPhysics::~SDECLinkPhysics()
{
}

void SDECLinkPhysics::postProcessAttributes(bool deserializing)
{
	if(deserializing)
	{
		shearForce = Vector3r(0,0,0);
		thetar = Vector3r(0,0,0);
	}
}


void SDECLinkPhysics::registerAttributes()
{
	InteractionPhysics::registerAttributes();
	REGISTER_ATTRIBUTE(initialKn);
	REGISTER_ATTRIBUTE(initialKs);
	REGISTER_ATTRIBUTE(initialEquilibriumDistance);
	REGISTER_ATTRIBUTE(knMax);
	REGISTER_ATTRIBUTE(ksMax);
	REGISTER_ATTRIBUTE(heta);
}
