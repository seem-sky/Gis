/**********************************************************************
 * $Id: OffsetPointGenerator.h 1941 2006-12-13 10:55:55Z strk $
 *
 * GEOS - Geometry Engine Open Source
 * http://geos.refractions.net
 *
 * Copyright (C) 2006 Refractions Research Inc.
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU Lesser General Public Licence as published
 * by the Free Software Foundation. 
 * See the COPYING file for more information.
 *
 ***********************************************************************
 *
 * Last port: operation/overlay/validate/OffsetPointGenerator.java rev. 1.1
 * (we should move in GEOS too, probably)
 *
 **********************************************************************/

#ifndef GEOS_OP_OVERLAY_OFFSETPOINTGENERATOR_H
#define GEOS_OP_OVERLAY_OFFSETPOINTGENERATOR_H

#include <geos/algorithm/PointLocator.h> // for composition
#include <geos/geom/Geometry.h> // for auto_ptr visibility of dtor
#include <geos/geom/MultiPoint.h> // for auto_ptr visibility of dtor
#include <geos/geom/Coordinate.h> // for use in vector

#include <vector>
#include <memory> // for auto_ptr

// Forward declarations
namespace geos {
	namespace geom {
		//class Geometry;
		//class MultiPoint;
		class LineString;
		//class Coordinate;
	}
}

namespace geos {
namespace operation { // geos::operation
namespace overlay { // geos::operation::overlay

/// Generates points offset from both sides of all segments in a geometry
//
class OffsetPointGenerator {

public:

	OffsetPointGenerator(const geom::Geometry& geom, double offset);

	/// Gets the computed offset points.
	std::auto_ptr< std::vector<geom::Coordinate> > getPoints();

private:

	const geom::Geometry& g;

	double offsetDistance;

	std::auto_ptr< std::vector<geom::Coordinate> > offsetPts;

	void extractPoints(const geom::LineString* line);

	void computeOffsets(const geom::Coordinate& p0,
			const geom::Coordinate& p1);
};

} // namespace geos::operation::overlay
} // namespace geos::operation
} // namespace geos

#endif // ndef GEOS_OP_OVERLAY_OFFSETPOINTGENERATOR_H

/**********************************************************************
 * $Log$
 **********************************************************************/

