# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

include_directories(
             'src/main/jni')

# This does not seem to work; apparently you need to add the include directory in the build.gradle
# using the cppFlags option, like cppFlags += "-I/..." notation
#include_directories(             '${CMAKE_CURRENT_LIST_DIR}/../libraries/headers')

include_directories(             '../libraries/headers')
             #'${CMAKE_CURRENT_LIST_DIR}/../libraries/headers'


# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             #src/main/cpp/native-lib.cpp

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

#link_directories(../libraries/jni/arm64-v8a)
link_directories(${CMAKE_CURRENT_LIST_DIR}/../libraries/jni/arm64-v8a)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

#find_library( # Need to find gvr libs
#              gvr-lib

              # The name of the Google VR SDK lib file (libgvr.so)
#              gvr

              # None of these worked so far. CMake can't find libgvr.so
              # HINTS "${CMAKE_CURRENT_LIST_DIR}/../libraries/jni/arm64-v8a"
              # HINTS "${CMAKE_CURRENT_LIST_DIR}/../libraries/jni/armeabi-v7a"
#              HINTS "../libraries/jni/armeabi-v7a"
#)

add_library( imported-lib
             SHARED
             IMPORTED )

set_target_properties( # Specifies the target library.
                       imported-lib

                       # Specifies the parameter you want to define.
                       PROPERTIES IMPORTED_LOCATION

                       # Provides the path to the library you want to import.
                       ${CMAKE_CURRENT_LIST_DIR}/../libraries/jni/${ANDROID_ABI}/libgvr.so )

add_library( audio-lib
             SHARED
             IMPORTED )

set_target_properties( # Specifies the target library.
                       audio-lib

                       # Specifies the parameter you want to define.
                       PROPERTIES IMPORTED_LOCATION

                       # Provides the path to the library you want to import.
                       ${CMAKE_CURRENT_LIST_DIR}/../libraries/jni/${ANDROID_ABI}/libgvr_audio.so )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib}

                       EGL
                       GLESv2
                       imported-lib
                       audio-lib)
                       # ${gvr-lib})

