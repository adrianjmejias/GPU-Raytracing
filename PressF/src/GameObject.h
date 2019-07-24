#pragma once
#include "Transform.h"

class Component;

class GameObject
{
	friend class Application;
	std::vector<Component*> components;
public:
	Transform transform;
	GameObject();
	~GameObject();

	template <typename TT, typename ...Args>
	TT& AddComponent(Args&&... params);
	template <typename TT>
	TT& GetComponent();
};

template<typename TT, typename ...Args>
TT & GameObject::AddComponent(Args && ...params) {
	TT* comp = new TT(*this, transform, std::forward<Args>(params)...);
	components.push_back(comp);
	return *comp;
}

template<typename TT>
TT & GameObject::GetComponent() {
	for each (object comp in component)
	{
		if (TT* t = dynamic_cast<TT*>(comp)) {
			return t;
		}
	}
	return nullptr;
}