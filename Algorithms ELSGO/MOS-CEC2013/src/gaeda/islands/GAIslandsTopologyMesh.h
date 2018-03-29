/*****************************************************************************
 * GAEDAlib: A C++ GA library with EDA and multiprocessor (MPI) support      *
 *                                                                           *
 * (C) 2005 Pedro Diaz (pdiaz@laurel.datsi.fi.upm.es)                        *
 *                                                                           *
 * GAEDAlib is distributed under the terms of the BSD software license       *
 *                                                                           *
 * GAEDAlib is heavily based on GAlib, a C++ GA library by Mathew Wall:      *
 * Copyright (c) 1995-1996 Massachusetts Institute of Technology (MIT)       *
 * Copyright (c) 1996-2000 Matthew Wall (author of GAlib)                    *
 *                                                                           *
 * Some portions of GAEDAlib's source code come from the GNU C++ compiler    *
 * library and therefore are covered under the terms of a different license, *
 * the GNU Public License.                                                   *
 *                                                                           *
 * You should have received a file named LICENSE along with this software.   *
 * This file contains more information about the licensing conditions of     *
 * GAEDAlib as well as the full text of each license involved.               *
 *                                                                           *
 * The file AUTHORS lists the people who have contributed (directly or       *
 * indirectly) to GAEDAlib                                                   *
 *****************************************************************************/

/**
 * @file
 * @brief GAIslandsTopologyMesh class hdr.
 *
 * Header for class GAIslandsTopologyMesh. This class represents
 * a mesg topology
 */

#ifndef GAISLANDSTOPOLOGYMESH_H
#define GAISLANDSTOPOLOGYMESH_H


/* INCLUDES */

#include <list>

#include "EAIslandsTopology.h"


using namespace std; // For STL stuff


/**
 * @brief Mesh islands topology
 *
 */
class GAIslandsTopologyMesh : public EAIslandsTopology {

	public:
		/* Constructor and destructor */
		GAIslandsTopologyMesh( int count );
		~GAIslandsTopologyMesh();


		/* Members */
		list<int>* getDestinations( int islandID );
		list<int>* getOrigins( int islandID );
	
};

#endif
