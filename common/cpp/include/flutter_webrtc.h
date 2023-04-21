// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
#ifndef FLUTTER_WEBRTC_H
#define FLUTTER_WEBRTC_H
#include <flutter/plugin_registrar.h>
#include "messages.h"
namespace flutter_webrtc_plugin {
class FlutterWebRTC : public RTCPeerConnectionFactoryApi,
                      public RTCDataChannelApi,
                      public RTCDTMFSenderApi,
                      public RTCRtpSenderApi,
                      public RTCRtpTransceiverApi,
                      public RTCVideoRendererApi,
                      public RTCPeerConnectionApi,
                      public MediaRecorderApi,
                      public MediaStreamApi,
                      public MediaStreamTrackApi,
                      public DesktopCapturerSourceApi,
                      public MediaDevicesApi {
 public:
  FlutterWebRTC(flutter::PluginRegistrar* registrar);
  virtual ~FlutterWebRTC();
  // RTCPeerConnectionFactoryApi
  virtual ErrorOr<std::string> CreatePeerConnection(
      const flutter::EncodableMap& configuration,
      const flutter::EncodableMap& constraints) override;
  virtual ErrorOr<RtpCapabilitiesMessage> GetRtpReceiverCapabilities(
      const std::string& kind) override;
  virtual ErrorOr<RtpCapabilitiesMessage> GetRtpSenderCapabilities(
      const std::string& kind) override;
  // RTCDataChannelApi
  virtual std::optional<FlutterError> Send(
      const std::string& peerConnection_id,
      const DataChannelMessage& message) override;
  virtual std::optional<FlutterError> CloseDataChannel(
      const std::string& peerConnection_id) override;
  // RTCDTMFSenderApi
  virtual std::optional<FlutterError> InsertDtmf(
      const std::string& peerConnection_id,
      const std::string& rtp_sender_id,
      const std::string& tones,
      int64_t duration,
      int64_t inter_tone_gap) override;
  virtual ErrorOr<bool> CanInsertDtmf(
      const std::string& peerConnection_id,
      const std::string& rtp_sender_id) override;
  // RTCRtpSenderApi
  virtual ErrorOr<bool> SetParameters(
      const std::string& peerConnection_id,
      const std::string& rtp_sender_id,
      const RtpParametersMessage& parameters) override;
  virtual std::optional<FlutterError> ReplaceTrack(
      const std::string& peerConnection_id,
      const std::string& rtp_sender_id,
      const std::string& track_id) override;
  virtual std::optional<FlutterError> SetTrack(
      const std::string& peerConnection_id,
      const std::string& rtp_sender_id,
      const std::string& track_id,
      bool take_ownership) override;
  // RTCRtpTransceiverApi
  virtual std::optional<FlutterError> SetDirection(
      const std::string& peerConnection_id,
      const std::string& transceiver_id,
      const std::string& direction) override;
  virtual ErrorOr<std::optional<std::string>> GetCurrentDirection(
      const std::string& peerConnection_id,
      const std::string& transceiver_id) override;
  virtual ErrorOr<std::string> GetDirection(
      const std::string& peerConnection_id,
      const std::string& transceiver_id) override;
  virtual std::optional<FlutterError> StopRtpTransceiver(
      const std::string& peerConnection_id,
      const std::string& transceiver_id) override;
  virtual std::optional<FlutterError> SetCodecPreferences(
      const std::string& peerConnection_id,
      const std::string& transceiver_id,
      const flutter::EncodableList& codecs) override;
  // RTCVideoRendererApi
  virtual ErrorOr<std::optional<int64_t>> Initialize() override;
  virtual std::optional<FlutterError> SetSrcObject(
      int64_t texture_id,
      const std::string& stream_id,
      const std::string& owner_tag,
      const std::string* track_id) override;
  virtual std::optional<FlutterError> DisposeVideoRender(
      int64_t texture_id) override;
  // RtcPeerConnectionApi
  virtual std::optional<FlutterError> AddCandidate(
      const std::string& peerConnection_id,
      const IceCandidateMessage& msg) override;
  virtual std::optional<FlutterError> AddStream(
      const std::string& peerConnection_id,
      const std::string& stream_id) override;
  virtual ErrorOr<flutter::EncodableMap> AddTrack(
      const std::string& peerConnection_id,
      const std::string& track_id,
      const flutter::EncodableList* stream_ids) override;
  virtual std::optional<FlutterError> ClosePeerConnection(
      const std::string& peerConnection_id) override;
  virtual ErrorOr<SessionDescriptionMessage> CreateAnswer(
      const std::string& peerConnection_id,
      const ConstraintsMessage& msg) override;
  virtual ErrorOr<flutter::EncodableMap> CreateDataChannel(
      const std::string& peerConnection_id,
      const std::string& label,
      const DataChannelInitMessage& msg) override;
  virtual ErrorOr<SessionDescriptionMessage> CreateOffer(
      const std::string& peerConnection_id,
      const ConstraintsMessage& msg) override;
  virtual std::optional<FlutterError> DisposePeerconnection(
      const std::string& peerConnection_id) override;
  virtual ErrorOr<std::optional<SessionDescriptionMessage>> GetLocalDescription(
      const std::string& peerConnection_id) override;
  virtual ErrorOr<flutter::EncodableList> GetLocalStreams(
      const std::string& peerConnection_id) override;
  virtual ErrorOr<flutter::EncodableList> GetRemoteStreams(
      const std::string& peerConnection_id) override;
  virtual ErrorOr<flutter::EncodableList> GetReceivers(
      const std::string& peerConnection_id) override;
  virtual ErrorOr<flutter::EncodableList> GetSenders(
      const std::string& peerConnection_id) override;
  virtual ErrorOr<flutter::EncodableList> GetTransceivers(
      const std::string& peerConnection_id) override;
  virtual ErrorOr<flutter::EncodableList> GetStats(
      const std::string& peerConnection_id,
      const std::string& track_id) override;
  virtual std::optional<FlutterError> RemoveStream(
      const std::string& peerConnection_id,
      const std::string& stream_id) override;
  virtual ErrorOr<bool> RemoveTrack(const std::string& peerConnection_id,
                                    const std::string& sender_id) override;
  virtual std::optional<FlutterError> RestartIce(
      const std::string& peerConnection_id) override;
  virtual std::optional<FlutterError> SetConfiguration(
      const std::string& peerConnection_id,
      const ConfigurationMessage& msg) override;
  virtual std::optional<FlutterError> SetLocalDescription(
      const std::string& peerConnection_id,
      const SessionDescriptionMessage& msg) override;
  virtual ErrorOr<SessionDescriptionMessage> GetRemoteDescription(
      const std::string& peerConnection_id) override;
  virtual std::optional<FlutterError> SetRemoteDescription(
      const std::string& peerConnection_id,
      const SessionDescriptionMessage& msg) override;
  // MediaRecorderApi
  virtual std::optional<FlutterError> Start(
      const std::string& path,
      int64_t audio_channel,
      const std::string* video_track_id,
      int64_t recorder_id,
      const std::string* peerConnection_id) override;
  virtual std::optional<FlutterError> StopMediaRecorder(
      int64_t recorder_id) override;
  // MediaStreamApi
  virtual std::optional<FlutterError> GetMediaStreamTracks(
      const std::string& stream_id) override;
  virtual std::optional<FlutterError> AddMediaStreamTrack(
      const std::string& stream_id,
      const std::string& track_id) override;
  virtual std::optional<FlutterError> RemoveMediaStreamTrack(
      const std::string& stream_id,
      const std::string& track_id) override;
  virtual std::optional<FlutterError> DisposeMediaStream(
      const std::string& stream_id) override;
  // MediaStreamTrackApi
  virtual std::optional<FlutterError> Enable(
      const std::string& track_id,
      bool enabled,
      const std::string& peerConnection_id) override;
  virtual ErrorOr<bool> HasTorch(const std::string& track_id) override;
  virtual std::optional<FlutterError> SetTorch(const std::string& track_id,
                                               bool torch) override;
  virtual std::optional<FlutterError> CaptureFrame(
      const std::string& track_id,
      const std::string& peerConnection_id,
      const std::string& path) override;
  virtual std::optional<FlutterError> StopMediaStreamTrack(
      const std::string& track_id) override;
  // DesktopCapturerSourceApi
  virtual ErrorOr<flutter::EncodableList> GetDesktopSources(
      const flutter::EncodableList& types,
      const ThumbnailSizeMessage& thumbnail_size) override;
  virtual ErrorOr<bool> UpdateSources(
      const flutter::EncodableList& types) override;
  virtual ErrorOr<std::optional<std::vector<uint8_t>>> GetThumbnail(
      const std::string& source_id,
      const ThumbnailSizeMessage& thumbnail_size) override;
  // MediaDevicesApi
  virtual ErrorOr<MediaStreamMessage> GetUserMedia(
      const flutter::EncodableMap& media_constraints) override;
  virtual ErrorOr<MediaStreamMessage> GetDisplayMedia(
      const flutter::EncodableMap& media_constraints) override;
  virtual ErrorOr<flutter::EncodableList> GetSources() override;
  virtual ErrorOr<flutter::EncodableList> EnumerateDevices() override;
  virtual ErrorOr<MediaDeviceInfoMessage> SelectAudioOutput(
      const std::string& device_id) override;

 private:
  flutter::PluginRegistrar* registrar_;
};
}  // namespace flutter_webrtc_plugin

#endif  // FLUTTER_WEBRTC_H