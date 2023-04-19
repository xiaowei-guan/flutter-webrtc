#include "flutter_webrtc/flutter_web_r_t_c_plugin.h"

#include <flutter/plugin_registrar.h>
#include "flutter_webrtc.h"

//#if defined(_WINDOWS)

namespace flutter_webrtc_plugin {

// A webrtc plugin for windows/linux.
class FlutterWebRTCPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrar* registrar) {
    auto plugin = std::make_unique<FlutterWebRTCPlugin>(registrar);
    registrar->AddPlugin(std::move(plugin));
  }
  virtual ~FlutterWebRTCPlugin() {}

 public:
  // Creates a plugin that communicates on the given channel.
  FlutterWebRTCPlugin(flutter::PluginRegistrar* registrar) {
    webrtc_ = std::make_unique<FlutterWebRTC>(registrar);
  }

 private:
  std::unique_ptr<FlutterWebRTC> webrtc_;
};

}  // namespace flutter_webrtc_plugin

#if defined(_WINDOWS)
void FlutterWebRTCPluginRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
#else
void flutter_web_r_t_c_plugin_register_with_registrar(
    FlPluginRegistrar* registrar) {
#endif
  static auto* plugin_registrar = new flutter::PluginRegistrar(registrar);
  flutter_webrtc_plugin::FlutterWebRTCPlugin::RegisterWithRegistrar(
      plugin_registrar);
}