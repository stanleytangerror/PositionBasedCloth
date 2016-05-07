#ifndef PRIMITIVE_REFERENCE_H
#define PRIMITIVE_REFERENCE_H

#include "SurfaceMeshObject.h"
#include "Types.h"

#include <Eigen/Dense>

class Face3fRef
{
public:
	SurfaceMesh3f const & mesh;
	Faceidx const faceidx;
	SurfaceMesh3f::Property_map<Veridx, PointEigen3f> const & posMap;

	Face3fRef(SurfaceMesh3f const & mesh, Faceidx const faceidx,
		SurfaceMesh3f::Property_map<Veridx, PointEigen3f> const & posMap) :
		mesh(mesh), faceidx(faceidx), posMap(posMap) {}

	Face3fRef(Face3fRef && other) = default;
	Face3fRef & operator=(Face3fRef && other) = default;
	Face3fRef(Face3fRef const & other) = default;
	Face3fRef & operator=(Face3fRef const & other) = delete;

	PointEigen3f point(Veridx const & vid) const
	{
		return posMap[vid];
	}

};

class Vertex3fRef
{
public:
	SurfaceMesh3f const & mesh;
	Veridx const veridx;
	SurfaceMesh3f::Property_map<Veridx, PointEigen3f> const & posMap;

	Vertex3fRef(SurfaceMesh3f const & mesh, Veridx const veridx,
		SurfaceMesh3f::Property_map<Veridx, PointEigen3f> const & posMap) :
		mesh(mesh), veridx(veridx), posMap(posMap) {}

	Vertex3fRef(Vertex3fRef && other) = default;
	Vertex3fRef & operator=(Vertex3fRef && other) = default;
	Vertex3fRef(Vertex3fRef const & other) = delete;
	Vertex3fRef & operator=(Vertex3fRef const & other) = delete;

	// TODO change to range of PointEigen3fs
	PointEigen3f point(Veridx const & vid) const
	{
		return posMap[vid];
	}

};

class Edge3fRef
{
public:
	SurfaceMesh3f const & mesh;
	Edgeidx const & edgeidx;
	SurfaceMesh3f::Property_map<Veridx, Eigen::Vector3f> const & posMap;

	Edge3fRef(SurfaceMesh3f const & mesh, Edgeidx const & edgeidx,
		SurfaceMesh3f::Property_map<Veridx, Eigen::Vector3f> const & posMap) :
		mesh(mesh), edgeidx(edgeidx), posMap(posMap) {}

	Edge3fRef(Edge3fRef && other) = default;
	Edge3fRef & operator=(Edge3fRef && other) = default;
	Edge3fRef(Edge3fRef const & other) = default;
	Edge3fRef & operator=(Edge3fRef const & other) = delete;

	PointEigen3f point(Veridx const & vid) const
	{
		return posMap[vid];
	}
};

class Face3fContinuesRef
{
public:
	SurfaceMesh3f const & mesh;
	Faceidx const faceidx;
	SurfaceMesh3f::Property_map<Veridx, PointEigen3f> const & posMap0;
	SurfaceMesh3f::Property_map<Veridx, PointEigen3f> const & posMap1;

	Face3fContinuesRef(SurfaceMesh3f const & mesh, Faceidx const faceidx,
		SurfaceMesh3f::Property_map<Veridx, PointEigen3f> const & posMap0,
		SurfaceMesh3f::Property_map<Veridx, PointEigen3f> const & posMap1) :
		mesh(mesh), faceidx(faceidx), posMap0(posMap0), posMap1(posMap1) {}

	Face3fContinuesRef(Face3fContinuesRef && other) = default;
	Face3fContinuesRef & operator=(Face3fContinuesRef && other) = default;
	Face3fContinuesRef(Face3fContinuesRef const & other) = default;
	Face3fContinuesRef & operator=(Face3fContinuesRef const & other) = delete;

	PointEigen3f point0(Veridx const & vid) const
	{
		return posMap0[vid];
	}

	PointEigen3f point1(Veridx const & vid) const
	{
		return posMap1[vid];
	}

};

class Vertex3fContinuesRef
{
public:
	SurfaceMesh3f const & mesh;
	Veridx const veridx;
	SurfaceMesh3f::Property_map<Veridx, PointEigen3f> const & posMap0;
	SurfaceMesh3f::Property_map<Veridx, PointEigen3f> const & posMap1;

	Vertex3fContinuesRef(SurfaceMesh3f const & mesh, Veridx const veridx,
		SurfaceMesh3f::Property_map<Veridx, PointEigen3f> const & posMap0,
		SurfaceMesh3f::Property_map<Veridx, PointEigen3f> const & posMap1) :
		mesh(mesh), veridx(veridx), posMap0(posMap0), posMap1(posMap1) {}

	Vertex3fContinuesRef(Vertex3fContinuesRef && other) = default;
	Vertex3fContinuesRef & operator=(Vertex3fContinuesRef && other) = default;
	Vertex3fContinuesRef(Vertex3fContinuesRef const & other) = default;
	Vertex3fContinuesRef & operator=(Vertex3fContinuesRef const & other) = delete;

	PointEigen3f point0(Veridx const & vid) const
	{
		return posMap0[vid];
	}

	PointEigen3f point1(Veridx const & vid) const
	{
		return posMap1[vid];
	}

};

#endif