# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

cmake_minimum_required(VERSION 3.4.1)

# List source files.
# Commented out the .cc file listing via globbing in the original sample code
# - Changed to explicitly list all the files in add_library() (GVR NDK sample + amorphous-vr)
#file(GLOB native_srcs "src/main/jni/*.c*")

add_library(treasurehunt_jni
    SHARED
    src/main/jni/treasure_hunt_jni.cc
    src/main/jni/treasure_hunt_renderer.cc
    src/main/jni/MyGvrApp.cpp

    # amorphous
    src/main/jni/amorphous/Input/InputDevice.cpp
    src/main/jni/amorphous/Input/InputHub.cpp
    src/main/jni/amorphous/Input/Android/AndroidKeyboard.cpp
    src/main/jni/amorphous/Support/Serialization/BinaryArchive_Input.cpp
    src/main/jni/amorphous/Support/Serialization/BinaryArchive_Output.cpp
    src/main/jni/amorphous/Support/Serialization/ArchiveObjectBase.cpp
    src/main/jni/amorphous/Support/Serialization/BinaryDatabase.cpp
    src/main/jni/amorphous/Support/Serialization/BinaryArchive.cpp
    src/main/jni/amorphous/Support/CameraController.cpp
    src/main/jni/amorphous/Support/Profile.cpp
    src/main/jni/amorphous/Support/DebugOutput.cpp
    src/main/jni/amorphous/Support/CameraControllerBase.cpp
    src/main/jni/amorphous/Support/Log/LogInputBase.cpp
    src/main/jni/amorphous/Support/Log/StateLog.cpp
    src/main/jni/amorphous/Support/Log/LogOutput.cpp
    src/main/jni/amorphous/Support/LogOutput_OnScreen.cpp
    src/main/jni/amorphous/Support/MTRand.cpp
    src/main/jni/amorphous/Support/BitmapImage_stb.cpp
    src/main/jni/amorphous/Support/ZLib/adler32.c
    src/main/jni/amorphous/Support/ZLib/trees.c
    src/main/jni/amorphous/Support/ZLib/inflate.c
    src/main/jni/amorphous/Support/ZLib/uncompr.c
    src/main/jni/amorphous/Support/ZLib/gzwrite.c
    src/main/jni/amorphous/Support/ZLib/inftrees.c
    src/main/jni/amorphous/Support/ZLib/compress.c
    src/main/jni/amorphous/Support/ZLib/infback.c
    src/main/jni/amorphous/Support/ZLib/gzclose.c
    src/main/jni/amorphous/Support/ZLib/gzlib.c
    src/main/jni/amorphous/Support/ZLib/crc32.c
    src/main/jni/amorphous/Support/ZLib/deflate.c
    src/main/jni/amorphous/Support/ZLib/zutil.c
    src/main/jni/amorphous/Support/ZLib/gzread.c
    src/main/jni/amorphous/Support/ZLib/inffast.c
    src/main/jni/amorphous/Support/ZLib/ZLibAux.cpp
    src/main/jni/amorphous/Support/ZLib/zpipe_stream.cpp
    src/main/jni/amorphous/3DMath/ConvexPolygon.cpp
    src/main/jni/amorphous/3DMath/PrimitivePolygonModelMaker.cpp
    src/main/jni/amorphous/3DMath/AABB3.cpp
    src/main/jni/amorphous/3DMath/BrickWallPolygonModelMaker.cpp
    src/main/jni/amorphous/3DMath/AABTree.cpp
    src/main/jni/amorphous/3DMath/BSPTreeForTriangleMesh.cpp
    src/main/jni/amorphous/3DMath/Perlin.cpp
    src/main/jni/amorphous/3DMath/OBBTree.cpp
    src/main/jni/amorphous/3DMath/BSPTreeForBox.cpp
    src/main/jni/amorphous/3DMath/HelixPolygonModelMaker.cpp
    src/main/jni/amorphous/App/Android/GvrAppBase.cpp
    src/main/jni/amorphous/Graphics/Font/BitstreamVeraSansMono_Bold_256.cpp
    src/main/jni/amorphous/Graphics/Font/FontFactory.cpp
    src/main/jni/amorphous/Graphics/Font/TextureFont.cpp
    src/main/jni/amorphous/Graphics/ResourceLoadingStateHolder.cpp
    src/main/jni/amorphous/Graphics/GraphicsResourceCacheManager.cpp
    src/main/jni/amorphous/Graphics/PostProcessEffectManager.cpp
    src/main/jni/amorphous/Graphics/OnScreenDebugInfoRenderer.cpp
    src/main/jni/amorphous/Graphics/Camera.cpp
    src/main/jni/amorphous/Graphics/TextureRenderTarget.cpp
    src/main/jni/amorphous/Graphics/ShadowMaps.cpp
    src/main/jni/amorphous/Graphics/GraphicsEffectManager.cpp
    src/main/jni/amorphous/Graphics/2DPrimitive/2DPolygon.cpp
    src/main/jni/amorphous/Graphics/2DPrimitive/2DFrameRect.cpp
    src/main/jni/amorphous/Graphics/2DPrimitive/2DPrimitive.cpp
    src/main/jni/amorphous/Graphics/2DPrimitive/2DRoundRect.cpp
    src/main/jni/amorphous/Graphics/2DPrimitive/2DRectSet.cpp
    src/main/jni/amorphous/Graphics/2DPrimitive/2DPrimitiveRenderer.cpp
    src/main/jni/amorphous/Graphics/2DPrimitive/2DRect.cpp
    src/main/jni/amorphous/Graphics/2DPrimitive/2DTriangle.cpp
    src/main/jni/amorphous/Graphics/MeshGenerators/PipeMeshGenerator.cpp
    src/main/jni/amorphous/Graphics/MeshGenerators/MeshGenerators.cpp
    src/main/jni/amorphous/Graphics/RectTree.cpp
    src/main/jni/amorphous/Graphics/ShaderHandle.cpp
    src/main/jni/amorphous/Graphics/GraphicsComponentCollector.cpp
    src/main/jni/amorphous/Graphics/ShadowMapManager.cpp
    src/main/jni/amorphous/Graphics/CubeMapManager.cpp
    src/main/jni/amorphous/Graphics/GraphicsDevice.cpp
    src/main/jni/amorphous/Graphics/SkyboxMisc.cpp
    src/main/jni/amorphous/Graphics/SimpleMotionBlur.cpp
    src/main/jni/amorphous/Graphics/PrimitiveShapeRenderer.cpp
    src/main/jni/amorphous/Graphics/GraphicsResourceEntries.cpp
    src/main/jni/amorphous/Graphics/PseudoNoiseEffect.cpp
    src/main/jni/amorphous/Graphics/GraphicsResources.cpp
    src/main/jni/amorphous/Graphics/Shader/ShaderManagerHub.cpp
    src/main/jni/amorphous/Graphics/Shader/ShaderLightManager.cpp
    src/main/jni/amorphous/Graphics/Shader/FixedFunctionPipelineManager.cpp
    src/main/jni/amorphous/Graphics/Shader/ShaderManager.cpp
    src/main/jni/amorphous/Graphics/Shader/Embedded/EmbeddedGenericShader.cpp
    src/main/jni/amorphous/Graphics/PostProcessEffectFilter.cpp
    src/main/jni/amorphous/Graphics/ShapeDetector.cpp
    src/main/jni/amorphous/Graphics/GraphicsElementManager.cpp
    src/main/jni/amorphous/Graphics/TextureGenerators/NoiseTextureGenerators.cpp
    src/main/jni/amorphous/Graphics/TextureGenerators/PerlinNoiseTextureGenerator.cpp
    src/main/jni/amorphous/Graphics/TextureGenerators/ParticleTextureGenerator.cpp
    src/main/jni/amorphous/Graphics/TextureGenerators/TextureFilter.cpp
    src/main/jni/amorphous/Graphics/TextureGenerators/TextureGeneratorFactory.cpp
    src/main/jni/amorphous/Graphics/BuiltinSkyTextures.cpp
    src/main/jni/amorphous/Graphics/MeshModel/NVMeshMender.cpp
    src/main/jni/amorphous/Graphics/MeshModel/MeshBone.cpp
    src/main/jni/amorphous/Graphics/MeshModel/PrimitiveShapeMeshes.cpp
    src/main/jni/amorphous/Graphics/MeshModel/3DMeshModelBuilder.cpp
    src/main/jni/amorphous/Graphics/MeshModel/General3DMeshFunctions.cpp
    src/main/jni/amorphous/Graphics/MeshModel/3DMeshModelArchive.cpp
    src/main/jni/amorphous/Graphics/MeshModel/MeshArchiveToGeneral3DMeshConverer.cpp
    src/main/jni/amorphous/Graphics/BoundingVolumeTreeRenderers.cpp
    src/main/jni/amorphous/Graphics/ShapesExtractor.cpp
    src/main/jni/amorphous/Graphics/GraphicsResourceManager.cpp
    src/main/jni/amorphous/Graphics/PostProcessEffect.cpp
    src/main/jni/amorphous/Graphics/CubeTextureRenderTarget.cpp
    src/main/jni/amorphous/Graphics/GraphicsResourceLoaders.cpp
    src/main/jni/amorphous/Graphics/IndexedPolygon.cpp
    src/main/jni/amorphous/Graphics/TextureHandle.cpp
    src/main/jni/amorphous/Graphics/GraphicsElements.cpp
    src/main/jni/amorphous/Graphics/GraphicsResourceDescs.cpp
    src/main/jni/amorphous/Graphics/Mesh/MeshFactory.cpp
    src/main/jni/amorphous/Graphics/Mesh/RectSetMesh.cpp
    src/main/jni/amorphous/Graphics/Mesh/CustomMeshRenderer.cpp
    src/main/jni/amorphous/Graphics/Mesh/ProgressiveMesh.cpp
    src/main/jni/amorphous/Graphics/Mesh/SkeletalMesh.cpp
    src/main/jni/amorphous/Graphics/Mesh/BasicMesh.cpp
    src/main/jni/amorphous/Graphics/Mesh/ConvexMeshSplitter.cpp
    src/main/jni/amorphous/Graphics/Mesh/CustomMesh.cpp
    src/main/jni/amorphous/Graphics/Mesh/MeshInfoRenderer.cpp
    src/main/jni/amorphous/Graphics/OpenGL/GLInitialization.cpp
    src/main/jni/amorphous/Graphics/OpenGL/2DPrimitive/2DPrimitiveRenderer_GL.cpp
    src/main/jni/amorphous/Graphics/OpenGL/GLGraphicsResources.cpp
    src/main/jni/amorphous/Graphics/OpenGL/Shader/GLFixedFunctionPipelineManager.cpp
    src/main/jni/amorphous/Graphics/OpenGL/Shader/GLSLShaderLightManager.cpp
    src/main/jni/amorphous/Graphics/OpenGL/Shader/Embedded/GLEmbeddedMiscGLSLShader.cpp
    src/main/jni/amorphous/Graphics/OpenGL/Shader/Embedded/EmbeddedPostProcessEffectGLSLShader.cpp
    src/main/jni/amorphous/Graphics/OpenGL/Shader/Embedded/EmbeddedGenericGLSLShader.cpp
    src/main/jni/amorphous/Graphics/OpenGL/Shader/GLShader.cpp
    src/main/jni/amorphous/Graphics/OpenGL/GLTextureUtilities.cpp
    src/main/jni/amorphous/Graphics/OpenGL/GLCubeTextureRenderTarget.cpp
    src/main/jni/amorphous/Graphics/OpenGL/Mesh/GLCustomMeshRenderer.cpp
    src/main/jni/amorphous/Graphics/OpenGL/Mesh/GLBasicMeshImpl.cpp
    src/main/jni/amorphous/Graphics/OpenGL/Mesh/GLSkeletalMeshImpl.cpp
    src/main/jni/amorphous/Graphics/OpenGL/Mesh/GLProgressiveMeshImpl.cpp
    src/main/jni/amorphous/Graphics/OpenGL/GLGraphicsDevice.cpp
    src/main/jni/amorphous/Graphics/GraphicsResourceHandle.cpp
    src/main/jni/amorphous/Graphics/AsyncResourceLoader.cpp
    src/main/jni/amorphous/Graphics/DoubleConeScrollEffect.cpp
    src/main/jni/amorphous/Graphics/MeshObjectContainer.cpp
    src/main/jni/amorphous/Graphics/MeshObjectHandle.cpp
    src/main/jni/amorphous/Graphics/LensFlare.cpp
    src/main/jni/amorphous/Graphics/RenderTaskProcessor.cpp
    src/main/jni/amorphous/Graphics/RectTriListIndex.cpp
    src/main/jni/amorphous/Graphics/MeshContainerRenderMethod.cpp
)

# Include the GVR headers & libraries.
include_directories(${GVR_INCLUDE})

include_directories(./src/main/jni)

add_library(gvr-lib SHARED IMPORTED)
set_target_properties(
    gvr-lib
    PROPERTIES IMPORTED_LOCATION ${GVR_LIBPATH}/${ANDROID_ABI}/libgvr.so)

add_library(gvraudio-lib SHARED IMPORTED)
set_target_properties(
    gvraudio-lib
    PROPERTIES IMPORTED_LOCATION ${GVR_LIBPATH}/${ANDROID_ABI}/libgvr_audio.so)

# Include general Android libraries.
find_library(android-lib android)
find_library(EGL-lib EGL)
find_library(GLESv2-lib GLESv2)
find_library(log-lib log)

# Build final libtreasurehunt_jni.so
target_link_libraries(treasurehunt_jni
    gvr-lib
    gvraudio-lib

    ${android-lib}
    ${EGL-lib}
    ${GLESv2-lib}
    ${log-lib} )
