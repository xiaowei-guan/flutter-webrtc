// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "flutter_webrtc.h"
namespace flutter_webrtc_plugin {
FlutterWebRTC::FlutterWebRTC(flutter::PluginRegistrar* registrar)
    : registrar_(registrar) {
  RTCPeerConnectionFactoryApi::SetUp(registrar_->messenger(), this);
  RTCDataChannelApi::SetUp(registrar_->messenger(), this);
  RTCDTMFSenderApi::SetUp(registrar_->messenger(), this);
  RTCRtpSenderApi::SetUp(registrar_->messenger(), this);
  RTCRtpTransceiverApi::SetUp(registrar_->messenger(), this);
  RTCVideoRendererApi::SetUp(registrar_->messenger(), this);
  RTCPeerConnectionApi::SetUp(registrar_->messenger(), this);
  MediaRecorderApi::SetUp(registrar_->messenger(), this);
  MediaStreamApi::SetUp(registrar_->messenger(), this);
  MediaStreamTrackApi::SetUp(registrar_->messenger(), this);
  DesktopCapturerSourceApi::SetUp(registrar_->messenger(), this);
  MediaDevicesApi::SetUp(registrar_->messenger(), this);
}

FlutterWebRTC::~FlutterWebRTC() {}
// RTCpeerConnectionFactoryApi
ErrorOr<std::string> FlutterWebRTC::CreatePeerConnection(
    const flutter::EncodableMap& configuration,
    const flutter::EncodableMap& constraints) {
  return std::string("");
}
ErrorOr<RtpCapabilitiesMessage> FlutterWebRTC::GetRtpReceiverCapabilities(
    const std::string& kind) {
  return RtpCapabilitiesMessage();
}
ErrorOr<RtpCapabilitiesMessage> FlutterWebRTC::GetRtpSenderCapabilities(
    const std::string& kind) {
  return RtpCapabilitiesMessage();
}
// RTCDataChannelApi
std::optional<FlutterError> FlutterWebRTC::Send(
    const std::string& peerConnection_id,
    const DataChannelMessage& message) {
  return {};
}
std::optional<FlutterError> FlutterWebRTC::CloseDataChannel(
    const std::string& peerConnection_id) {
  return {};
}
// RTCDTMFSenderApi
std::optional<FlutterError> FlutterWebRTC::InsertDtmf(
    const std::string& peerConnection_id,
    const std::string& rtp_sender_id,
    const std::string& tones,
    int64_t duration,
    int64_t inter_tone_gap) {
  return {};
}
ErrorOr<bool> FlutterWebRTC::CanInsertDtmf(const std::string& peerConnection_id,
                                           const std::string& rtp_sender_id) {
  return true;
}
// RTCRtpSenderApi
ErrorOr<bool> FlutterWebRTC::SetParameters(
    const std::string& peerConnection_id,
    const std::string& rtp_sender_id,
    const RtpParametersMessage& parameters) {
  return true;
}
std::optional<FlutterError> FlutterWebRTC::ReplaceTrack(
    const std::string& peerConnection_id,
    const std::string& rtp_sender_id,
    const std::string& track_id) {
  return {};
}
std::optional<FlutterError> FlutterWebRTC::SetTrack(
    const std::string& peerConnection_id,
    const std::string& rtp_sender_id,
    const std::string& track_id,
    bool take_ownership) {
  return {};
}
// RTCRtpTransceiverApi
std::optional<FlutterError> FlutterWebRTC::SetDirection(
    const std::string& peerConnection_id,
    const std::string& transceiver_id,
    const std::string& direction) {
  return {};
}
ErrorOr<std::optional<std::string>> FlutterWebRTC::GetCurrentDirection(
    const std::string& peerConnection_id,
    const std::string& transceiver_id) {
  return std::optional(std::string(""));
}
ErrorOr<std::string> FlutterWebRTC::GetDirection(
    const std::string& peerConnection_id,
    const std::string& transceiver_id) {
  return std::string("");
}
std::optional<FlutterError> FlutterWebRTC::StopRtpTransceiver(
    const std::string& peerConnection_id,
    const std::string& transceiver_id) {
  return {};
}
std::optional<FlutterError> FlutterWebRTC::SetCodecPreferences(
    const std::string& peerConnection_id,
    const std::string& transceiver_id,
    const flutter::EncodableList& codecs) {
  return {};
}
// RTCVideoRendererApi
ErrorOr<std::optional<int64_t>> FlutterWebRTC::Initialize() {
  return {12};
}
std::optional<FlutterError> FlutterWebRTC::SetSrcObject(
    int64_t texture_id,
    const std::string& stream_id,
    const std::string& owner_tag,
    const std::string* track_id) {
  return {};
}
std::optional<FlutterError> FlutterWebRTC::DisposeVideoRender(
    int64_t texture_id) {
  return {};
}
// RtcPeerConnectionApi
std::optional<FlutterError> FlutterWebRTC::AddCandidate(
    const std::string& peerConnection_id,
    const IceCandidateMessage& msg) {
  return {};
}
std::optional<FlutterError> FlutterWebRTC::AddStream(
    const std::string& peerConnection_id,
    const std::string& stream_id) {
  return {};
}
ErrorOr<flutter::EncodableMap> FlutterWebRTC::AddTrack(
    const std::string& peerConnection_id,
    const std::string& track_id,
    const flutter::EncodableList* stream_ids) {
  return flutter::EncodableMap();
}
std::optional<FlutterError> FlutterWebRTC::ClosePeerConnection(
    const std::string& peerConnection_id) {
  return {};
}
ErrorOr<SessionDescriptionMessage> FlutterWebRTC::CreateAnswer(
    const std::string& peerConnection_id,
    const ConstraintsMessage& msg) {
  return SessionDescriptionMessage();
}
ErrorOr<flutter::EncodableMap> FlutterWebRTC::CreateDataChannel(
    const std::string& peerConnection_id,
    const std::string& label,
    const DataChannelInitMessage& msg) {
  return flutter::EncodableMap();
}
ErrorOr<SessionDescriptionMessage> FlutterWebRTC::CreateOffer(
    const std::string& peerConnection_id,
    const ConstraintsMessage& msg) {
  return SessionDescriptionMessage();
}
std::optional<FlutterError> FlutterWebRTC::DisposePeerconnection(
    const std::string& peerConnection_id) {
  return {};
}
ErrorOr<std::optional<SessionDescriptionMessage>>
FlutterWebRTC::GetLocalDescription(const std::string& peerConnection_id) {
  return std::optional(SessionDescriptionMessage());
}
ErrorOr<flutter::EncodableList> FlutterWebRTC::GetLocalStreams(
    const std::string& peerConnection_id) {
  return flutter::EncodableList();
}
ErrorOr<flutter::EncodableList> FlutterWebRTC::GetRemoteStreams(
    const std::string& peerConnection_id) {
  return flutter::EncodableList();
}
ErrorOr<flutter::EncodableList> FlutterWebRTC::GetReceivers(
    const std::string& peerConnection_id) {
  return flutter::EncodableList();
}
ErrorOr<flutter::EncodableList> FlutterWebRTC::GetSenders(
    const std::string& peerConnection_id) {
  return flutter::EncodableList();
}
ErrorOr<flutter::EncodableList> FlutterWebRTC::GetTransceivers(
    const std::string& peerConnection_id) {
  return flutter::EncodableList();
}
ErrorOr<flutter::EncodableList> FlutterWebRTC::GetStats(
    const std::string& peerConnection_id,
    const std::string& track_id) {
  return flutter::EncodableList();
}
std::optional<FlutterError> FlutterWebRTC::RemoveStream(
    const std::string& peerConnection_id,
    const std::string& stream_id) {
  return {};
}
ErrorOr<bool> FlutterWebRTC::RemoveTrack(const std::string& peerConnection_id,
                                         const std::string& sender_id) {
  return true;
}
std::optional<FlutterError> FlutterWebRTC::RestartIce(
    const std::string& peerConnection_id) {
  return {};
}
std::optional<FlutterError> FlutterWebRTC::SetConfiguration(
    const std::string& peerConnection_id,
    const ConfigurationMessage& msg) {
  return {};
}
std::optional<FlutterError> FlutterWebRTC::SetLocalDescription(
    const std::string& peerConnection_id,
    const SessionDescriptionMessage& msg) {
  return {};
}
ErrorOr<SessionDescriptionMessage> FlutterWebRTC::GetRemoteDescription(
    const std::string& peerConnection_id) {
  return SessionDescriptionMessage();
}
std::optional<FlutterError> FlutterWebRTC::SetRemoteDescription(
    const std::string& peerConnection_id,
    const SessionDescriptionMessage& msg) {
  return {};
}
// MediaRecorderApi
std::optional<FlutterError> FlutterWebRTC::Start(
    const std::string& path,
    int64_t audio_channel,
    const std::string* video_track_id,
    int64_t recorder_id,
    const std::string* peerConnection_id) {
  return {};
}
std::optional<FlutterError> FlutterWebRTC::StopMediaRecorder(
    int64_t recorder_id) {
  return {};
}
// MediaStreamApi
std::optional<FlutterError> FlutterWebRTC::GetMediaStreamTracks(
    const std::string& stream_id) {
  return {};
}
std::optional<FlutterError> FlutterWebRTC::AddMediaStreamTrack(
    const std::string& stream_id,
    const std::string& track_id) {
  return {};
}
std::optional<FlutterError> FlutterWebRTC::RemoveMediaStreamTrack(
    const std::string& stream_id,
    const std::string& track_id) {
  return {};
}
std::optional<FlutterError> FlutterWebRTC::DisposeMediaStream(
    const std::string& stream_id) {
  return {};
}
// MediaStreamTrackApi
std::optional<FlutterError> FlutterWebRTC::Enable(
    const std::string& track_id,
    bool enabled,
    const std::string& peerConnection_id) {
  return {};
}
ErrorOr<bool> FlutterWebRTC::HasTorch(const std::string& track_id) {
  return true;
}
std::optional<FlutterError> FlutterWebRTC::SetTorch(const std::string& track_id,
                                                    bool torch) {
  return {};
}
std::optional<FlutterError> FlutterWebRTC::CaptureFrame(
    const std::string& track_id,
    const std::string& peerConnection_id,
    const std::string& path) {
  return {};
}
std::optional<FlutterError> FlutterWebRTC::StopMediaStreamTrack(
    const std::string& track_id) {
  return {};
}
// DesktopCapturerSourceApi
ErrorOr<flutter::EncodableList> FlutterWebRTC::GetDesktopSources(
    const flutter::EncodableList& types,
    const ThumbnailSizeMessage& thumbnail_size) {
  return flutter::EncodableList();
}
ErrorOr<bool> FlutterWebRTC::UpdateSources(
    const flutter::EncodableList& types) {
  return true;
}
ErrorOr<std::optional<std::vector<uint8_t>>> FlutterWebRTC::GetThumbnail(
    const std::string& source_id,
    const ThumbnailSizeMessage& thumbnail_size) {
  return std::optional(std::vector<uint8_t>());
}
// MediaDevicesApi
ErrorOr<MediaStreamMessage> FlutterWebRTC::GetUserMedia(
    const flutter::EncodableMap& media_constraints) {
  return MediaStreamMessage(std::string(""), std::string(""),
                            flutter::EncodableList(), flutter::EncodableList());
}
ErrorOr<MediaStreamMessage> FlutterWebRTC::GetDisplayMedia(
    const flutter::EncodableMap& media_constraints) {
  return MediaStreamMessage(std::string(""), std::string(""),
                            flutter::EncodableList(), flutter::EncodableList());
}
ErrorOr<flutter::EncodableList> FlutterWebRTC::GetSources() {
  return flutter::EncodableList();
}
ErrorOr<flutter::EncodableList> FlutterWebRTC::EnumerateDevices() {
  return flutter::EncodableList();
}
ErrorOr<MediaDeviceInfoMessage> FlutterWebRTC::SelectAudioOutput(
    const std::string& device_id) {
  return MediaDeviceInfoMessage(std::string(""), std::string(""));
}
}  // namespace flutter_webrtc_plugin