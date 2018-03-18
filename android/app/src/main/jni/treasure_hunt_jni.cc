/* Copyright 2017 Google Inc. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <android/log.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include <android/keycodes.h> // For turning on/off the rendering of the floor (gDrawFloor). This include directive is meant to be temporary.
#include <jni.h>

#include <memory>

#include "treasure_hunt_renderer.h"  // NOLINT
#include "vr/gvr/capi/include/gvr.h"
#include "vr/gvr/capi/include/gvr_audio.h"
#include "amorphous/App/Android/GvrAppBase.hpp"
#include "amorphous/Input/Android/AndroidKeyboard.hpp"
#include "amorphous/Graphics/GraphicsResources.hpp"
//#include "amorphous/Support/Log/DefaultLogAux.hpp"

extern JavaVM *gJavaVM;

extern bool gDrawCube;
extern bool gDrawFloor;

static inline amorphous::AndroidKeyboard& get_kbd() {
  static amorphous::AndroidKeyboard s_kbd;
  return s_kbd;
}

// This causes crash at startup (app fails to create the vr.log log file).
//static amorphous::AndroidKeyboard kbd;

#define JNI_METHOD(return_type, method_name) \
  JNIEXPORT return_type JNICALL              \
      Java_space_nyanko_amorphousvr_MainActivity_##method_name

namespace {

inline jlong jptr(TreasureHuntRenderer *native_treasure_hunt) {
  return reinterpret_cast<intptr_t>(native_treasure_hunt);
}

inline TreasureHuntRenderer *native(jlong ptr) {
  return reinterpret_cast<TreasureHuntRenderer *>(ptr);
}
}  // anonymous namespace

extern "C" {

JNI_METHOD(jlong, nativeCreateRenderer)
(JNIEnv *env, jclass clazz, jobject class_loader, jobject android_context,
 jlong native_gvr_api) {

  env->GetJavaVM(&gJavaVM);

  std::unique_ptr<gvr::AudioApi> audio_context(new gvr::AudioApi);
  audio_context->Init(env, android_context, class_loader,
                      GVR_AUDIO_RENDERING_BINAURAL_HIGH_QUALITY);

  return jptr(
      new TreasureHuntRenderer(reinterpret_cast<gvr_context *>(native_gvr_api),
                               std::move(audio_context)));
}

JNI_METHOD(void, nativeDestroyRenderer)
(JNIEnv *env, jclass clazz, jlong native_treasure_hunt) {
  delete native(native_treasure_hunt);
}

JNI_METHOD(void, nativeInitializeGl)
(JNIEnv *env, jobject obj, jlong native_treasure_hunt) {
  native(native_treasure_hunt)->InitializeGl();
}

JNI_METHOD(void, nativeDrawFrame)
(JNIEnv *env, jobject obj, jlong native_treasure_hunt) {
  native(native_treasure_hunt)->DrawFrame();
}

JNI_METHOD(void, nativeOnTriggerEvent)
(JNIEnv *env, jobject obj, jlong native_treasure_hunt) {
  native(native_treasure_hunt)->OnTriggerEvent();
}

JNI_METHOD(void, nativeOnPause)
(JNIEnv *env, jobject obj, jlong native_treasure_hunt) {
  native(native_treasure_hunt)->OnPause();
}

JNI_METHOD(void, nativeOnResume)
(JNIEnv *env, jobject obj, jlong native_treasure_hunt) {
  native(native_treasure_hunt)->OnResume();
}

extern std::unique_ptr<amorphous::GvrAppBase> kMyApp;

JNI_METHOD(void, nativeOnKeyDown)
(JNIEnv *env, jobject obj, jlong native_treasure_hunt, jint key_code) {
  //native(native_treasure_hunt)->OnKeyDown((int)key_code);

  get_kbd().OnKeyDown((int)key_code);

  if( (int)key_code == AKEYCODE_F6
   || (int)key_code == AKEYCODE_6
   || (int)key_code == AKEYCODE_L ) {
    gDrawFloor = !gDrawFloor;
    //amorphous::LOG_PRINTF(("gDrawFloor: %d",(int)gDrawFloor));
   }

  //if(::kMyApp)
  //  ::kMyApp->OnKeyDown();
}

JNI_METHOD(void, nativeOnKeyUp)
(JNIEnv *env, jobject obj, jlong native_treasure_hunt, jint key_code) {
  //native(native_treasure_hunt)->OnKeyUp((int)key_code);

  get_kbd().OnKeyUp((int)key_code);

  //if(::kMyApp)
  //  ::kMyApp->OnKeyDown();
}

JNI_METHOD(void, nativeInitAssetManager)
(JNIEnv *env, jobject obj, jobject assetManager) {

  AAssetManager *mgr = AAssetManager_fromJava(env, assetManager);

  amorphous::SetAssetManager(mgr);
}

}  // extern "C"
