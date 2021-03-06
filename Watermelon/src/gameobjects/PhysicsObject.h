#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H

#include "GameObject.h"
#include "framework/ContactListener.h"
#include "Box2D/Box2D.h"
#include "framework/WorldManager.h"


namespace GAME {
	class PhysicsObject : public GameObject {
	public:
		PhysicsObject(const float32 x = 0, const float32 y = 0);
		virtual ~PhysicsObject();

		PhysicsObject(const PhysicsObject&) = delete;
		PhysicsObject(PhysicsObject &&) = delete;
		PhysicsObject& operator=(const PhysicsObject &) = delete;
		PhysicsObject& operator=(PhysicsObject &&) = delete;

		virtual GameObject::TYPE GetType() const;
		virtual void BeginContact(const b2Contact* contact, const PhysicsObject& physObjRef);
		virtual void EndContact(const b2Contact* contact, const PhysicsObject& physObjRef);
		virtual void SetBody(b2Body& bodyRef);
		virtual b2Body* GetBody() const;
		virtual void Update(const float deltaTime);
		virtual void  Draw(const int xOffset = 0, const int yOffset = 0, const float scale = 1, SDL_Rect* clip = nullptr,
			const double angle = 0, SDL_Point* center = nullptr,
			const SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE) const;

	public:
		b2Body* body;
	};
}


#endif