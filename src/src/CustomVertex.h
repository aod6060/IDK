#ifndef CUSTOM_VERTEX_H
#define CUSTOM_VERTEX_H

#include <vector>
#include <d3d9.h>

struct Vertex {
	D3DXVECTOR3 xyz;
	D3DXVECTOR2 tex1;

public:

	Vertex() : xyz(0, 0, 0), tex1(0, 0) {}

	Vertex(D3DXVECTOR3 xyz, D3DXVECTOR2 tex1) : xyz(xyz), tex1(tex1) {}

};

typedef std::vector<Vertex> VertexList;

#define VERTEX_FVF (D3DFVF_XYZ | D3DFVF_TEX1)

#endif