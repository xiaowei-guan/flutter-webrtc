// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'package:pigeon/pigeon.dart';

@ConfigurePigeon(PigeonOptions(
  dartOut: 'lib/src/native/messages.g.dart',
  cppHeaderOut: 'common/cpp/include/messages.h',
  cppSourceOut: 'common/cpp/src/messages.cc',
  javaOut: 'android/src/main/java/com/cloudwebrtc/webrtc/Messages.java',
  javaOptions: JavaOptions(
    package: 'com.cloudwebrtc.webrtc',
  ),
  copyrightHeader: 'pigeons/copyright.txt',
))
class SessionDescriptionMessage {
  String? sdp;
  String? type;
}

class ConstraintsMessage {
  ConstraintsMessage(this.constraints);
  Map<String?, Object?> constraints;
}

class ConfigurationMessage {
  ConfigurationMessage(this.configurations);
  Map<String?, Object?> configurations;
}

class AudioTrackSettingsMessage {
  AudioTrackSettingsMessage(
      this.deviceId,
      this.kind,
      this.autoGainControl,
      this.echoCancellation,
      this.noiseSuppression,
      this.channelCount,
      this.latency);
  String deviceId;
  String kind;
  bool autoGainControl;
  bool echoCancellation;
  bool noiseSuppression;
  int channelCount;
  int latency;
}

class AudioTrackMessage {
  AudioTrackMessage(
      this.id, this.label, this.kind, this.enabled, this.settings);
  String id;
  String label;
  String kind;
  bool enabled;
  AudioTrackSettingsMessage settings;
}

class VideoTrackSettingsMessage {
  VideoTrackSettingsMessage(
      this.deviceId, this.kind, this.width, this.height, this.frameRate);
  String deviceId;
  String kind;
  int width;
  int height;
  int frameRate;
}

class VideoTrackMessage {
  VideoTrackMessage(
      this.id, this.label, this.kind, this.enabled, this.settings);
  String id;
  String label;
  String kind;
  bool enabled;
  VideoTrackSettingsMessage settings;
}

class MediaStreamMessage {
  MediaStreamMessage(
      this.id, this.ownerTag, this.audioTracks, this.videoTracks);
  String id;
  String ownerTag;
  List<AudioTrackMessage?> audioTracks;
  List<VideoTrackMessage?> videoTracks;
}

class MediaDeviceInfoMessage {
  MediaDeviceInfoMessage({
    this.kind,
    required this.label,
    this.groupId,
    required this.deviceId,
  });

  final String deviceId;
  final String? groupId;
  final String? kind;
  final String label;
}

class IceCandidateMessage {
  IceCandidateMessage([this.candidate, this.sdpMid, this.sdpMLineIndex]);
  String? candidate;
  String? sdpMid;
  int? sdpMLineIndex;
}

class StatsReportMessage {
  StatsReportMessage(this.id, this.type, this.timestamp, this.values);
  String? id;
  String? type;
  double? timestamp;
  Map<Object?, Object?> values;
}

class DataChannelMessage {
  DataChannelMessage(this.channelId, this.type);
  String channelId;
  String type;
  Uint8List? binary;
  String? text;
}

class DataChannelInitMessage {
  DataChannelInitMessage(this.id, this.binaryType, this.maxRetransmitTime,
      this.maxRetransmits, this.negotiated, this.ordered, this.protocol);
  int id;
  bool negotiated;
  String binaryType;
  String protocol;
  bool ordered;
  int maxRetransmitTime;
  int maxRetransmits;
}

class HeaderExtensionMessage {
  String? uri;
  int? id;
  bool? encrypted;
}

class RtpEncodingMessage {
  RtpEncodingMessage(this.active);
  bool active;
  String? rid;
  int? maxBitrate;
  int? minBitrate;
  int? maxFramerate;
  int? numTemporalLayers;
  double? scaleResolutionDownBy;
  int? ssrc;
  String? scalabilityMode;
}

class RtpCodecMessage {
  int? payloadType;
  String? name;
  String? kind;
  int? clockRate;
  int? numChannels;
  Map<Object?, Object?>? parameters;
}

class RTCParametersMessage {
  RTCParametersMessage(this.cname, this.reducedSize);
  String cname;
  bool reducedSize;
}

class RtpParametersMessage {
  String? transactionId;
  RTCParametersMessage? rtcp;
  List<HeaderExtensionMessage?>? headerExtensions;
  List<RtpEncodingMessage?>? encodings;
  List<RtpCodecMessage?>? codecs;
}

class RtpCodecCapabilityMessage {
  RtpCodecCapabilityMessage(this.clockRate, this.mimeType);
  int? channels;
  int clockRate;
  String mimeType;
  String? sdpFmtpLine;
}

class RtpHeaderExtensionCapabilityMessage {
  RtpHeaderExtensionCapabilityMessage(this.uri);
  String uri;
}

class RtpCapabilitiesMessage {
  List<RtpCodecCapabilityMessage?>? codecs;
  List<RtpHeaderExtensionCapabilityMessage?>? headerExtensions;
  List<String?>? fecMechanisms;
}

class ThumbnailSizeMessage {
  ThumbnailSizeMessage(this.width, this.height);
  int width;
  int height;
}

class DesktopCapturerSourceMessage {
  DesktopCapturerSourceMessage(
      this.id, this.name, this.type, this.thumbnailSizeMessage);
  String id;
  String name;
  String type;
  ThumbnailSizeMessage thumbnailSizeMessage;
}

@HostApi()
abstract class RTCPeerConnectionFactoryApi {
  String createPeerConnection(
      Map<String, Object?> configuration, Map<String, Object?> constraints);
  RtpCapabilitiesMessage getRtpReceiverCapabilities(String kind);
  RtpCapabilitiesMessage getRtpSenderCapabilities(String kind);
}

@HostApi()
abstract class RTCPeerConnectionApi {
  void addCandidate(String peerConnectionId, IceCandidateMessage msg);
  void addStream(String peerConnectionId, String streamId);
  Map<String, Object?> addTrack(
      String peerConnectionId, String trackId, List<String>? streamIds);
  void closePeerConnection(String peerConnectionId);
  SessionDescriptionMessage createAnswer(
      String peerConnectionId, ConstraintsMessage msg);
  Map<String, Object?> createDataChannel(
      String peerConnectionId, String label, DataChannelInitMessage msg);
  SessionDescriptionMessage createOffer(
      String peerConnectionId, ConstraintsMessage msg);
  void disposePeerconnection(String peerConnectionId);
  SessionDescriptionMessage? getLocalDescription(String peerConnectionId);
  List<MediaStreamMessage> getLocalStreams(String peerConnectionId);
  List<MediaStreamMessage> getRemoteStreams(String peerConnectionId);
  List<Map<String, Object?>> getReceivers(String peerConnectionId);
  List<Map<String, Object?>> getSenders(String peerConnectionId);
  List<Map<String, Object?>> getTransceivers(String peerConnectionId);
  List<StatsReportMessage> getStats(String peerConnectionId, String trackId);
  void removeStream(String peerConnectionId, String streamId);
  bool removeTrack(String peerConnectionId, String senderId);
  void restartIce(String peerConnectionId);
  void setConfiguration(String peerConnectionId, ConfigurationMessage msg);
  void setLocalDescription(
      String peerConnectionId, SessionDescriptionMessage msg);
  SessionDescriptionMessage getRemoteDescription(String peerConnectionId);
  void setRemoteDescription(
      String peerConnectionId, SessionDescriptionMessage msg);
}

@HostApi()
abstract class RTCDataChannelApi {
  void send(String peerConnectionId, DataChannelMessage message);
  void closeDataChannel(String peerConnectionId);
}

@HostApi()
abstract class RTCDTMFSenderApi {
  void insertDtmf(String peerConnectionId, String rtpSenderId, String tones,
      int duration, int interToneGap);
  bool canInsertDtmf(String peerConnectionId, String rtpSenderId);
}

@HostApi()
abstract class RTCRtpSenderApi {
  bool setParameters(String peerConnectionId, String rtpSenderId,
      RtpParametersMessage parameters);
  void replaceTrack(
      String peerConnectionId, String rtpSenderId, String trackId);
  void setTrack(String peerConnectionId, String rtpSenderId, String trackId,
      bool takeOwnership);
}

@HostApi()
abstract class RTCRtpTransceiverApi {
  void setDirection(
      String peerConnectionId, String transceiverId, String direction);
  String? getCurrentDirection(String peerConnectionId, String transceiverId);
  String getDirection(String peerConnectionId, String transceiverId);
  void stopRtpTransceiver(String peerConnectionId, String transceiverId);
  void setCodecPreferences(String peerConnectionId, String transceiverId,
      List<RtpCodecCapabilityMessage> codecs);
}

@HostApi()
abstract class RTCVideoRendererApi {
  int? initialize();
  void setSrcObject(
      int textureId, String streamId, String ownerTag, String? trackId);
  void disposeVideoRender(int textureId);
}

@HostApi()
abstract class MediaRecorderApi {
  void start(String path, int audioChannel, String? videoTrackId,
      int recorderId, String? peerConnectionId);
  void stopMediaRecorder(int recorderId);
}

@HostApi()
abstract class MediaStreamApi {
  void getMediaStreamTracks(String streamId);
  void addMediaStreamTrack(String streamId, String trackId);
  void removeMediaStreamTrack(String streamId, String trackId);
  void disposeMediaStream(String streamId);
}

@HostApi()
abstract class MediaStreamTrackApi {
  void enable(String trackId, bool enabled, String peerConnectionId);
  bool hasTorch(String trackId);
  void setTorch(String trackId, bool torch);
  void captureFrame(String trackId, String peerConnectionId, String path);
  void stopMediaStreamTrack(String trackId);
}

@HostApi()
abstract class DesktopCapturerSourceApi {
  List<DesktopCapturerSourceMessage> getDesktopSources(
      List<String> types, ThumbnailSizeMessage thumbnailSize);
  bool updateSources(List<String> types);
  Uint8List? getThumbnail(String sourceId, ThumbnailSizeMessage thumbnailSize);
}

@HostApi()
abstract class MediaDevicesApi {
  MediaStreamMessage getUserMedia(Map<String, Object?> mediaConstraints);
  MediaStreamMessage getDisplayMedia(Map<String, Object?> mediaConstraints);
  List<Object?> getSources();
  List<MediaDeviceInfoMessage> enumerateDevices();
  MediaDeviceInfoMessage selectAudioOutput(String deviceId);
}
