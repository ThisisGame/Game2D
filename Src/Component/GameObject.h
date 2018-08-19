#pragma once
#include "Object.h"
#include"Component.h"
#include<vector>
#include"LuaComponent.h"

class TiXmlElement;
class Transform;
class GameObject :
	public Object
{

private:
	GameObject();
public:
	GameObject(const char* varName);
	~GameObject();

	static void Destroy(GameObject* varGo);

	void InitWithXml(TiXmlElement* varTiXmlElement);

public:
	std::string name;

	Transform* mTransform;

	//**************************************************���ӽṹ���

public:

	///���������
	void AddChild(GameObject* varGameObject);

	///��ȡ���������
	int GetChildCount();

	///��ȡ������
	GameObject* GetChild(int varIndex);

	///��ȡ������
	GameObject* GetChild(const char* varName);

	///���ø��ڵ�
	void SetParent(GameObject* varGameObjectParent);

	///��ȡ���ڵ�
	GameObject* GetParent();

private:
	std::vector<GameObject*> mVectorChild;//�������б�

	GameObject* mGameObjectParent;//���ڵ�



	//**************************************************���
public:
	Component* AddComponent(const char* varComponentName);

	void RemoveComponent(const char* varComponentName);

	Component* GetComponent(const char* varComponentName);


	std::vector<Component*> GetComponents(const char* varComponentName);

private:
	std::vector<Component*> mVectorComponent;


	//**************************************************Lua���
public:
	LuaComponent* AddLuaComponent(const char* varFilePath);

	void RemoveLuaComponent(const char* varFilePath);

private:
	std::vector<LuaComponent*> mVectorLuaComponent;


	//**************************************************��������
public:
	void Awake() ;
	void OnEnable() ;
	void Start() ;

	void Update() ;

	void OnDisable() ;
	void OnDestroy() ;

public:
	static std::vector<GameObject*>& GetVectorGameObject();//all gameobject in gameapp
	
};

