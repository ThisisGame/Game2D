#pragma once
#include "Component/Object.h"
#include "Vertex.h"

class Mesh :
	public Object
{
public:
	Mesh();
	~Mesh();

	void SetVertexCount(int varVertexCount);//���ö�������ͬʱ�����ڴ�

	void PushVertexArray(Vertex* varVertex);//���붥������

	glm::vec3* GetVertexPositionAnim();

	void ApplySkin();

	const bool GetApplyedSkin();

	Vertex* GetVertexArray();

	const unsigned short GetVertexCount();

	void SetVertexIndicesSize(unsigned short varVertexIndicesSize);


	void PushVertexIndicesArray(unsigned short * varVertexIndices);


	const unsigned short GetVertexIndicesSize();
	

	unsigned short* GetVertexIndices();


private:
	int mVertexCount;
	Vertex* mVertexArray;

	glm::vec3* mVertexPositionAnim;

	unsigned short mVertexIndicesSize;
	

	unsigned short* mVertexIndices;


	bool mApplyedSkin;
};

