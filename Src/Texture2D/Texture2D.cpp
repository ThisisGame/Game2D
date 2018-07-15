#include "Texture2D.h"
#include"./Tools/Helper.h"
#include"stb_image.h"

Texture2D::Texture2D():m_textureId(-1),m_imageFilePath("")
{
	
}

void Texture2D::LoadTexture(const char* varFilePath)
{
	//Helper::LOG("Texture2D::LoadTexture %s", varFilePath);

	m_imageFilePath = std::string(varFilePath);

	stbi_set_flip_vertically_on_load(true);
	int tmpComponents;
	unsigned char* data = stbi_load(varFilePath, &mTextureWidth, &mTextureHeight, &tmpComponents, 0);
	if (data)
	{
		GLenum format;
		if (tmpComponents == 1)
			format = GL_ALPHA;
		else if (tmpComponents == 3)
			format = GL_RGB;
		else if (tmpComponents == 4)
			format = GL_RGBA;

		//1������һ������ID;
		glGenTextures(1, &m_textureId);

		//2���������������ID;
		glBindTexture(GL_TEXTURE_2D, m_textureId);

		//3��ָ���Ŵ���С�˲���ʽ�������˲������Ŵ���С�Ĳ�ֵ��ʽ;
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		// set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		//��ͼƬrgb�����ϴ���OpenGL,����һ���Ű����ݴ��ڴ�Copy���Դ�;
		glTexImage2D(GL_TEXTURE_2D, 0, format, mTextureWidth, mTextureHeight, 0, format, GL_UNSIGNED_BYTE, data);
	}
	else
	{
		Helper::LOG("Failed to load texture %s",varFilePath);
	}

	stbi_image_free(data);
}


Texture2D::~Texture2D()
{
}
