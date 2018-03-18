#include "MyGvrApp.hpp"
#include "amorphous/3DMath/MatrixConversions.hpp"
#include "amorphous/Graphics/2DPrimitive/2DRect.hpp"
#include "amorphous/Graphics/Mesh/BasicMesh.hpp"
#include "amorphous/Graphics/MeshUtilities.hpp"
#include "amorphous/Graphics/HemisphericLight.hpp"
#include "amorphous/Graphics/Shader/CommonShaders.hpp"
#include "amorphous/Graphics/Shader/GenericShaderHelpers.hpp"
#include "amorphous/Graphics/Shader/MiscShaderGenerator.hpp"
#include "amorphous/Graphics/Shader/ShaderManager.hpp"
#include "amorphous/Graphics/Shader/ShaderLightManager.hpp"
#include "amorphous/Graphics/HemisphericLight.hpp"
#include "amorphous/Input/InputHandler.hpp"
#include "amorphous/Support/Macro.h"
//#include "amorphous/Graphics/PrimitiveShapeRenderer.hpp"

using namespace std;
using namespace amorphous;


int MyGvrApp::InitShader() {

	if(m_Lighting) {
		m_Shader = CreateHSDirectionalLightingShader();
		//m_Shader.Load("/storage/emulated/0/Download/shaders/shader.vert|/storage/emulated/0/Download/shaders/shader.frag");
	}
	else {
		m_Shader = GetNoLightingShader();
		//	m_Shader = CreateMiscShader( MiscShader::SINGLE_DIFFUSE_COLOR_WHITE );
	}

	return 0;
}

	
int MyGvrApp::Init() {

	const int num_meshes = 7;

	m_Meshes.resize(num_meshes);

	m_Meshes[0].Load("asset://vrplayground.msh");// = CreateBoxMesh( Vector3(10,1,1) );
	m_Meshes[1] = CreateSphereMesh( 1 );
	m_Meshes[2] = CreateBoxMesh( Vector3(3,3,3) );//CreateConeMesh();
	m_Meshes[3] = CreateSphereMesh( 3 );
	m_Meshes[4] = CreateBoxMesh( Vector3(4,4,4) );//CreateCylinderMesh();
	m_Meshes[5] = CreateSphereMesh( 2 );
	m_Meshes[6].Load("asset://synty_crate.msh");
	m_Meshes[7].Load("/storage/emulated/0/Download/models/gazebo.msh");
	
	m_Mesh = CreateBoxMesh( Vector3(15,1,1) );

	InitShader();

	return 0;
}

void MyGvrApp::Render() {

	//PrimitiveShapeRenderer renderer;
	auto pShaderMgr = m_Shader.GetShaderManager();
	if( !pShaderMgr ) {
		ONCE( LOG_PRINT_ERROR("pShaderMgr == nullptr") );
		return;
	}

	SetLights();

	Vector3 mesh_positions[] = {
		Vector3(  0, 0,  0),
		Vector3(  0, 0,-10),
		Vector3(  0, 0, 10),
		Vector3( 10, 0,  0),
		Vector3(-10, 0,  0),
		Vector3(  7, 0,-7),
		Vector3(  7, 0, 7),
		Vector3( -7, 0,-7),
		Vector3( -20, 0, 20),
		Vector3( -3, 0, -20),
	};

	Matrix34 pose = Matrix34Identity();

	auto pBoxMesh = m_Mesh.GetMesh();
	if(pBoxMesh) {
		pose.vPosition = Vector3(0,0,-5);
	  pShaderMgr->SetWorldTransform(ToMatrix44(pose));
	  //pBoxMesh->Render(*pShaderMgr);	
	}

	int i=0;
	for( auto mesh : m_Meshes ) {

		auto pMesh = mesh.GetMesh();
		// auto pMesh = m_Mesh.GetMesh();

		if(pMesh) {// && i==6) {

			pose.vPosition = mesh_positions[i];
			pShaderMgr->SetWorldTransform(ToMatrix44(pose));
			pMesh->Render(*pShaderMgr);	
		}
		else {
			ONCE( LOG_PRINTF_ERROR(("mesh[%d] == nullptr",i)) );
		}
		i += 1;
	}

	C2DRect rect;
	rect.SetPositionLTWH(10,10,500,350);
	rect.SetColor( SFloatRGBAColor::White() );
	rect.Draw();
}

int MyGvrApp::SetLights() {
	auto pShaderMgr = m_Shader.GetShaderManager();
	if(!pShaderMgr) {
		LOG_PRINT_ERROR("null pShaderMgr");
		return -1;
	}

	auto pLightMgr = pShaderMgr->GetShaderLightManager();

	if(!pLightMgr) {
		LOG_PRINT_ERROR("null pLightMgr");
		return -1;
	}

	HemisphericDirectionalLight light;
	light.vDirection = Vec3GetNormalized( Vector3(1,-4,2) );
	light.Attribute.SetColorsGrayscale( 1.0f, 0.3f );

	pLightMgr->ClearLights();
	pLightMgr->SetHemisphericDirectionalLight(light);
	pLightMgr->CommitChanges();

	return 0;
}

void MyGvrApp::HandleInput( const amorphous::InputData& input ) {

	switch(input.iGICode) {
	case 'I':
		if( input.iType == ITYPE_KEY_PRESSED ) {
			m_Lighting = !m_Lighting;
			InitShader();
		}
		break;
/*	case 'A':
		if( input.iType == ITYPE_KEY_PRESSED ) {
			right = -5.0f;
		} else {
			right = 0.0f;
		}
		break;
	case 'D':
		if( input.iType == ITYPE_KEY_PRESSED ) {
			right = 5.0f;
		} else {
			right = 0.0f;
		}
		break;
	case 'W':
		if( input.iType == ITYPE_KEY_PRESSED ) {
			fwd = 5.0f;
		} else {
			fwd = 0.0f;
		}
		break;
	case 'S':
		if( input.iType == ITYPE_KEY_PRESSED ) {
			fwd = -5.0f;
		} else {
			fwd = 0.0f;
		}
		break;*/
	default:
		break;
	}
}
