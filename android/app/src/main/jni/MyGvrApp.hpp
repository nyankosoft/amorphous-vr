#ifndef __MyGvrApp_HPP__
#define __MyGvrApp_HPP__


#include "amorphous/App/Android/GvrAppBase.hpp"
#include "amorphous/Graphics/MeshObjectHandle.hpp"
#include "amorphous/Graphics/ShaderHandle.hpp"
#include "amorphous/Input/fwd.hpp"


// namespace mygvrapp{

	
class MyGvrApp : public amorphous::GvrAppBase
{
	std::vector<amorphous::MeshHandle> m_Meshes;

	amorphous::MeshHandle m_Mesh;

	amorphous::ShaderHandle m_Shader;

	bool m_Lighting;

	float fwd;
	float right;

private:

	int InitShader();

	int SetLights();

public:

	MyGvrApp() : fwd(0), right(0), m_Lighting(false) {}

	~MyGvrApp(){}
	
	int Init();

	void Render();

	void HandleInput( const amorphous::InputData& input );
};

	
//} // namespace mygvrapp


#endif /* __MyGvrApp_HPP__ */
