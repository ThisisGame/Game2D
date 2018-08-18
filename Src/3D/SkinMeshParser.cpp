#include "SkinMeshParser.h"
#include"PlayerPrefs/TinyXml/tinyxml.h"
#include"Component/GameObject.h"
#include<fstream>
#include"Tools/Helper.h"

SkinMeshParser::SkinMeshParser()
{
}


GameObject*	 SkinMeshParser::Create(const char * varFilePath)
{
	//�ļ������ڣ��ȴ���
	std::ifstream tmpXmlFile(varFilePath);
	if (!tmpXmlFile)
	{
		Helper::LOG("SkinMeshParser::CreateScene %s not exist", varFilePath);
		return nullptr;
	}

	//����һ��XML�ĵ�����;
	TiXmlDocument* tmpTiXmlDocument = new TiXmlDocument(varFilePath);
	tmpTiXmlDocument->LoadFile(TIXML_ENCODING_UTF8);

	//��ø�Ԫ�� PlayerPrefs;
	TiXmlElement *tmpTiXmlElementRoot = tmpTiXmlDocument->RootElement();
	if (tmpTiXmlElementRoot == NULL)
	{
		Helper::LOG("SkinMeshParser::CreateScene RootElement NULL");
		return nullptr;
	}

	//�������ڵ�
	GameObject* tmpGameObjectRoot = new GameObject(tmpTiXmlElementRoot->Attribute("Name"));

	RecursiveNode(tmpTiXmlElementRoot, tmpGameObjectRoot);

	return tmpGameObjectRoot;
}

void SkinMeshParser::RecursiveNode(TiXmlElement * varTiXmlElementRoot, GameObject * varGameObjectRoot)
{
	varGameObjectRoot->InitWithXml(varTiXmlElementRoot);

	//���� KeyValuePair;
	TiXmlNode *tmpTiXmlNode = NULL;

	for (tmpTiXmlNode = varTiXmlElementRoot->FirstChildElement(); tmpTiXmlNode != NULL; tmpTiXmlNode = tmpTiXmlNode->NextSiblingElement())
	{
		TiXmlElement* tmpTiXmlElement = tmpTiXmlNode->ToElement();
		const char* tmpNodeName = tmpTiXmlElement->Value();
		if (strcmp(tmpNodeName, "Component") == 0)
		{
			const char* tmpComponentType = tmpTiXmlElement->Attribute("Type");
			Component* tmpComponent = varGameObjectRoot->AddComponent(tmpComponentType);
			tmpComponent->InitWithXml(tmpTiXmlElement);
		}
		else if (strcmp(tmpNodeName, "GameObject") == 0)
		{
			const char* tmpGameObjectName = tmpTiXmlElement->Attribute("Name");
			GameObject* tmpGo = new GameObject(tmpGameObjectName);

			varGameObjectRoot->AddChild(tmpGo);
			RecursiveNode(tmpTiXmlElement, tmpGo);
		}
	}
}

SkinMeshParser::~SkinMeshParser()
{
}


