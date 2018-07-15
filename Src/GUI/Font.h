#pragma once

#include"ftglyph.h"

#include FT_GLYPH_H
#include FT_TRUETYPE_TABLES_H
#include FT_BITMAP_H
#include FT_WINFONTS_H

#include"../GLProgram/GLProgram_Font.h"


#include<assert.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


#include<iostream>
#include<fstream>

class RGBA_4_BYTE
{
public:
	RGBA_4_BYTE(unsigned char r = 255, unsigned char g = 255, unsigned char b = 255, unsigned char a = 255)
	{
		R = r;
		G = g;
		B = b;
		A = a;
	}
	
	~RGBA_4_BYTE(){}

public:
	unsigned char R;
	unsigned char G;
	unsigned char B;
	unsigned char A;
};

struct  UIVertex
{
	float x, y, z;
	float u, v, w;
	RGBA_4_BYTE color;
};


class Character
{
public:
	Character()
	{
		x0 = 0;
		y0 = 0;
		x1 = 0;
		y1 = 0;
		offsetX = 0;
		offsetY = 0;
	}

public:
	//�洢��ǰ�ַ���Font�����ϵ�����λ�ã�����1024���������Դ泣�ú���;
	unsigned int x0 : 10;
	unsigned int y0 : 10;
	unsigned int x1 : 10;
	unsigned int y1 : 10;
	//����ƫ��X;������gb��g��Y������ƫ�Ƶ�.
	unsigned int offsetX : 8;
	//����ƫ��Y;
	unsigned int offsetY : 8;
	//���е�����,���256��,2��8�η�;
	unsigned int index : 8;
};

class Font
{

public:
	//����ʹ��GL_ALPHA��ʽ;
	unsigned int m_fontTexture;//����Texutre;
	Character m_character[1 << 16];//�洢2��16�η�����;

	FT_Library m_FTLibrary;
	FT_Face m_FTFace;

	char* m_fontBuffer;

	int m_yStart;
	int m_xStart;

	int m_fontSize;

	int m_fontPixelX;
	int m_fontPixelY;

	UIVertex* m_Vert;

public:
	Font()
	{
		memset(m_character, 0, sizeof(m_character));
		m_fontPixelX = 0;
		m_fontPixelY = 0;
		m_yStart = 0;
		m_xStart = 0;

		m_Vert= (UIVertex*)malloc(1024 * sizeof(UIVertex));

		m_fontBuffer = 0;
		m_FTLibrary = 0;
		m_FTFace = 0;

		FT_Init_FreeType(&m_FTLibrary);//FreeType��ʼ��;
	}

	virtual ~Font()
	{

	}

	char* readFontFile(const char* filepath, unsigned int& length)
	{
		FILE *pFile = fopen(filepath, "rb");
		if (pFile)
		{
			//��ȡ�ļ�;
			fseek(pFile, 0, SEEK_END);
			length = ftell(pFile);
			fseek(pFile, 0, SEEK_SET);

			//����buffer;
			char* buffer = new char[length + 1];

			//���buffer;
			fread(buffer, 1, length, pFile);

			//buffer�����0�������;
			buffer[length] = 0;

			//�ر��ļ�;
			fclose(pFile);
			return buffer;
		}
		else
		{
			char buffer[1024];
			sprintf(buffer, "read %s failed", filepath);
			assert(pFile != 0 && buffer);
		}
		return 0;
	}

	void buildSystemFont(const char* font, int fontsize)
	{
		unsigned int length = 0;
		m_fontBuffer = readFontFile(font, length); //���ص����ļ���С;

		//��������Ĵ�С;
		m_fontSize = fontsize;

		//����Ѿ���������������;
		if (m_FTFace)
		{
			FT_Done_Face(m_FTFace);
			m_xStart = 0;
			m_yStart = 0;
			//���m_character;
			memset(m_character, 0, sizeof(m_character));
		}

		FT_Error error = FT_New_Memory_Face(m_FTLibrary, (const FT_Byte*)m_fontBuffer, length, 0, &m_FTFace);
		if (error != 0)
		{
			return;
		}
		FT_Face ftFace = m_FTFace;
		FT_Select_Charmap(ftFace, FT_ENCODING_UNICODE);

		FT_F26Dot6 ftSize = (FT_F26Dot6)(fontsize*(1 << 6));

		FT_Set_Char_Size(m_FTFace, ftSize, 0, 72, 72);

		assert(m_FTFace != 0);

		glGenTextures(1, &m_fontTexture);

		glBindTexture(GL_TEXTURE_2D, m_fontTexture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);


		

		unsigned char * pixels = (unsigned char *)malloc(1024 * 1024);
		memset(pixels, 0, 1024 * 1024);

		glTexImage2D(
			GL_TEXTURE_2D,      //! ָ���Ƕ�άͼƬ  
			0,                  //! ָ��Ϊ��һ�������������mipmap,��lod,����ľͲ��ü����ģ�Զ��ʹ�ý�С������  
			GL_ALPHA,             //! �����ʹ�õĴ洢��ʽ  
			1024,              //! ��ȣ���һ����Կ�����֧�ֲ��������������Ⱥ͸߶Ȳ���2^n��  
			1024,             //! ��ȣ���һ����Կ�����֧�ֲ��������������Ⱥ͸߶Ȳ���2^n��  
			0,                  //! �Ƿ�ı�  
			GL_ALPHA,             //! ���ݵĸ�ʽ��bmp�У�windows,����ϵͳ�д洢��������bgr��ʽ  
			GL_UNSIGNED_BYTE,   //! ������8bit����  
			pixels
		);
	}


	//��ȡһ���֣�����Character;
	Character getCharacter(wchar_t ch)
	{
		if (m_character[ch].x0 == 0 &&
			m_character[ch].y0 == 0 &&
			m_character[ch].x1 == 0 &&
			m_character[ch].y1 == 0)
		{
			//�жϵ�ǰ�ֵ���ʼ x ����+�����С �ǲ��ǳ���������Ŀ�ȣ������˾ͻ���;
			if (m_xStart + glm::max(m_fontPixelX, m_fontSize) > 1024)
			{
				m_xStart = 0;

				//���� m_fontPixelY �� m_fontSizeȡ��ֵ��m_fontPixelӦ��������Ĭ�ϴ�С��m_fontSize�������Լ����õĴ�С;��������������ͼ�Ŀ�ߴ�С;
				m_yStart += glm::max(m_fontPixelY, m_fontSize);
			}

			//Glyph�����Σ�ͼ���ַ� [glif];
			//��������ֵ�����,���ص� m_FTFace����ȥ;
			FT_Load_Glyph(m_FTFace, FT_Get_Char_Index(m_FTFace, ch), FT_LOAD_DEFAULT);

			//�� m_FTFace�����ȡ�������  �� glyph ����;
			FT_Glyph glyph;
			FT_Get_Glyph(m_FTFace->glyph, &glyph);

			//���������С�����Ƿ����÷����;
			//�����С����ʹ��FT_Render_Mode_Mono;
			//>12����ʹ��FT_Render_Mode_Normal; 
			if (!(ch >= '0' && ch <= '9'))
			{
				FT_Glyph_To_Bitmap(&glyph, ft_render_mode_normal, 0, 1);
			}
			else
			{
				FT_Glyph_To_Bitmap(&glyph, ft_render_mode_mono, 0, 1);
			}

			FT_BitmapGlyph bitmapGlyph = (FT_BitmapGlyph)glyph;

			//��������;
			FT_Bitmap& bitmap = bitmapGlyph->bitmap;

			FT_Bitmap targetBitmap;

			//�������µ� FT_Bitmap;
			FT_Bitmap_New(&targetBitmap);

			if (bitmap.pixel_mode == FT_PIXEL_MODE_MONO)
			{
				//���Convert�ɹ�;
				if (FT_Bitmap_Convert(m_FTLibrary, &bitmap, &targetBitmap, 1) == 0)
				{
					for (unsigned char* p = targetBitmap.buffer, *endP = p + targetBitmap.width*targetBitmap.rows; p != endP;++p)
					{
						*p ^= -*p ^ *p;
					}
					bitmap = targetBitmap;
				}
			}

			//���û������;
			if (bitmap.width == 0 || bitmap.rows == 0)
			{
				char mem[1024 * 32];
				memset(mem, 0, sizeof(mem));

				m_character[ch].x0 = m_xStart;
				m_character[ch].y0 = m_yStart;
				m_character[ch].x1 = m_xStart + m_fontSize / 2;
				m_character[ch].y1 = m_xStart + m_fontSize - 1;
				m_character[ch].offsetY = m_fontSize - 1;
				m_character[ch].offsetX = 0;

				glBindTexture(GL_TEXTURE_2D, m_fontTexture);

				glTexSubImage2D(
					GL_TEXTURE_2D,
					0,
					m_xStart,
					m_yStart,
					m_fontSize / 2,
					m_fontSize,
					GL_ALPHA,
					GL_UNSIGNED_BYTE,
					mem
					);
				m_xStart += m_fontSize / 2;
			}
			else
			{
				glBindTexture(GL_TEXTURE_2D, m_fontTexture);

				m_character[ch].x0 = m_xStart;
				m_character[ch].y0 = m_yStart;
				m_character[ch].x1 = m_xStart + bitmap.width;
				m_character[ch].y1 = m_yStart + bitmap.rows;

				m_character[ch].offsetY = bitmapGlyph->top;
				m_character[ch].offsetX = bitmapGlyph->left;

				glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
				glTexSubImage2D(
					GL_TEXTURE_2D,
					0,
					m_xStart,
					m_yStart,
					glm::max(1, bitmap.width),
					glm::max(1, bitmap.rows),
					GL_ALPHA,
					GL_UNSIGNED_BYTE,
					bitmap.buffer
					);
				m_xStart += (bitmap.width + 1);
				m_fontPixelY = glm::max(m_fontPixelY, bitmap.rows);
				m_fontPixelX = glm::max(m_fontPixelX, bitmap.width);

				
			}
			FT_Bitmap_Done((FT_Library)m_FTLibrary, &targetBitmap);

			
		}

		return m_character[ch];
	}

	UIVertex* GetUIVertex(float x, float y, float z, RGBA_4_BYTE color, std::u32string& text, int space,unsigned int varTextureID,bool alignCenter)
	{
		memset(m_Vert, 0, 1024 * sizeof(UIVertex));

		float       texWidth = (float)1024;
		float       texHeight = (float)1024;
		float       xStart = x;
		float       yStart = y;
		//float       yStart = (float)(int)y + m_fontSize;
		float       zStart = z;
		unsigned    index = 0;
		unsigned    size =  text.length();

		for (unsigned i = 0; i < size; ++i)
		{
			Character   ch = getCharacter(text[i]);

			float       h = float(ch.y1 - ch.y0);
			float       w = float(ch.x1 - ch.x0);
			float offsetY = h - ch.offsetY;

			/**
			*   ��һ����
			*/
			m_Vert[index + 0].x = xStart;
			m_Vert[index + 0].y = yStart  - offsetY;
			m_Vert[index + 0].z = zStart;
			m_Vert[index + 0].u = ch.x0 / texWidth;
			m_Vert[index + 0].v = ch.y1 / texHeight;
			m_Vert[index + 0].w = 1;
			m_Vert[index + 0].color = color;
			/**
			*   �ڶ�����
			*/
			m_Vert[index + 1].x = xStart + w;
			m_Vert[index + 1].y = yStart  -offsetY;
			m_Vert[index + 1].z = zStart;
			m_Vert[index + 1].u = ch.x1 / texWidth;
			m_Vert[index + 1].v = ch.y1 / texHeight;
			m_Vert[index + 1].w = 1;
			m_Vert[index + 1].color = color;
			/**
			*   ��������
			*/
			m_Vert[index + 2].x = xStart + w;
			m_Vert[index + 2].y = yStart +h- offsetY;
			m_Vert[index + 2].z = zStart;
			m_Vert[index + 2].u = ch.x1 / texWidth;
			m_Vert[index + 2].v = ch.y0 / texHeight;
			m_Vert[index + 2].w = 1;
			m_Vert[index + 2].color = color;
			/**
			*   ��һ����
			*/
			m_Vert[index + 3].x = xStart;
			m_Vert[index + 3].y = yStart  - offsetY;
			m_Vert[index + 3].z = zStart;
			m_Vert[index + 3].u = ch.x0 / texWidth;
			m_Vert[index + 3].v = ch.y1 / texHeight;
			m_Vert[index + 3].w = 1;
			m_Vert[index + 3].color = color;
			/**
			*   ��������
			*/
			m_Vert[index + 4].x = xStart + w;
			m_Vert[index + 4].y = yStart+h - offsetY;
			m_Vert[index + 4].z = zStart;
			m_Vert[index + 4].u = ch.x1 / texWidth;
			m_Vert[index + 4].v = ch.y0 / texHeight;
			m_Vert[index + 4].w = 1;
			m_Vert[index + 4].color = color;
			/**
			*   ���ĸ���
			*/
			m_Vert[index + 5].x = xStart;
			m_Vert[index + 5].y = yStart+h - offsetY;
			m_Vert[index + 5].z = zStart;
			m_Vert[index + 5].u = ch.x0 / texWidth;
			m_Vert[index + 5].v = ch.y0 / texHeight;
			m_Vert[index + 5].w = 1;
			m_Vert[index + 5].color = color;

			index += 6;
			xStart += w+ ch.offsetX+ space;
		}

		if (alignCenter)
		{
			//������ʾ
			float xoffset = xStart / 2;
			for (size_t i = 0; i < index; i++)
			{
				m_Vert[i].x -= xoffset;
			}
		}


		return m_Vert;
	}

};
