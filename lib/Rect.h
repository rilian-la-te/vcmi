/*
 * Rect.h, part of VCMI engine
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 *
 */
#pragma once

#include "Point.h"

VCMI_LIB_NAMESPACE_BEGIN

/// Rectangle class, which have a position and a size
class Rect
{
public:
	int x;
	int y;
	int w;
	int h;

	constexpr Rect(): x(-1), y(-1), w(-1), h(-1)
	{}

	constexpr Rect(int X, int Y, int W, int H): x(X), y(Y), w(W), h(H)
	{}
	constexpr Rect(const Point & position, const Point & size):
		x(position.x),
		y(position.y),
		w(size.x),
		h(size.y)
	{}
	constexpr Rect(const Rect& r) = default;

	DLL_LINKAGE static Rect createCentered( const Point & around, const Point & size );
	DLL_LINKAGE static Rect createCentered( const Rect  & target, const Point & size );
	DLL_LINKAGE static Rect createAround(const Rect &r, int borderWidth);

	constexpr bool isInside(int qx, int qy) const
	{
		if (qx > x && qx<x+w && qy>y && qy<y+h)
			return true;
		return false;
	}
	constexpr bool isInside(const Point & q) const
	{
		return isInside(q.x,q.y);
	}
	constexpr int top() const
	{
		return y;
	}
	constexpr int bottom() const
	{
		return y+h;
	}
	constexpr int left() const
	{
		return x;
	}
	constexpr int right() const
	{
		return x+w;
	}

	constexpr Point topLeft() const
	{
		return Point(x,y);
	}
	constexpr Point topRight() const
	{
		return Point(x+w,y);
	}
	constexpr Point bottomLeft() const
	{
		return Point(x,y+h);
	}
	constexpr Point bottomRight() const
	{
		return Point(x+w,y+h);
	}
	constexpr Point center() const
	{
		return Point(x+w/2,y+h/2);
	}
	constexpr Point dimensions() const
	{
		return Point(w,h);
	}

	constexpr void moveTo(const Point & dest)
	{
		x = dest.x;
		y = dest.y;
	}

	constexpr Rect operator+(const Point &p) const
	{
		return Rect(x+p.x,y+p.y,w,h);
	}

	constexpr Rect& operator=(const Rect &p)
	{
		x = p.x;
		y = p.y;
		w = p.w;
		h = p.h;
		return *this;
	}

	constexpr Rect& operator+=(const Point &p)
	{
		x += p.x;
		y += p.y;
		return *this;
	}

	constexpr Rect& operator-=(const Point &p)
	{
		x -= p.x;
		y -= p.y;
		return *this;
	}

	/// returns true if this rect intersects with another rect
	DLL_LINKAGE bool intersectionTest(const Rect & other) const;

	/// returns true if this rect intersects with line specified by two points
	DLL_LINKAGE bool intersectionTest(const Point & line1, const Point & line2) const;

	/// Returns rect that represents intersection of two rects
	DLL_LINKAGE Rect intersect(const Rect & other) const;

	/// Returns rect union - rect that covers both this rect and provided rect
	DLL_LINKAGE Rect include(const Rect & other) const;

	template <typename Handler>
	void serialize(Handler &h, const int version)
	{
		h & x;
		h & y;
		h & w;
		h & h;
	}
};

VCMI_LIB_NAMESPACE_END
