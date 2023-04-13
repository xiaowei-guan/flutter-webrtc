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
  Map<String?, dynamic?> constraints;
}

class ConfigurationMessage {
  ConfigurationMessage(this.configurations);
  Map<String?, dynamic?> configurations;
}

class MediaStreamMessage {
  MediaStreamMessage(
      this.id, this.ownerTag, this.audioTracks, this.videoTracks);
  String id;
  String ownerTag;
  List<AudioTrackMessage?> audioTracks;
  List<VideoTrackMessage?> videoTracks;
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

class VideoTrackMessage {
  VideoTrackMessage(
      this.id, this.label, this.kind, this.enabled, this.settings);
  String id;
  String label;
  String kind;
  bool enabled;
  VideoTrackSettingsMessage settings;
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
  Map<dynamic?, dynamic?> values;
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
  Map<dynamic?, dynamic?>? parameters;
}

class RtpParametersMessage {
  String? transactionId;
  RTCParametersMessage? rtcp;
  List<HeaderExtensionMessage?>? headerExtensions;
  List<RtpEncodingMessage?>? encodings;
  List<RtpCodecMessage?>? codecs;
}

class RTCParametersMessage {
  RTCParametersMessage(this.cname, this.reducedSize);
  String cname;
  bool reducedSize;
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
abstract class RTCPeerconnectionFactoryApi {
  String createPeerconnection(
      Map<String, dynamic?> configuration, Map<String, dynamic?> constraints);
  RtpCapabilitiesMessage getRtpReceiverCapabilities(String kind);
  RtpCapabilitiesMessage getRtpSenderCapabilities(String kind);
}

@HostApi()
abstract class RtcPeerconnectionApi {
  void addCandidate(String peerconnectionId, IceCandidateMessage msg);
  void addStream(String peerconnectionId, String streamId);
  Map<String, dynamic> addTrack(
      String peerconnectionId, String trackId, List<String>? streamIds);
  void close(String peerconnectionId);
  SessionDescriptionMessage createAnswer(
      String peerconnectionId, ConstraintsMessage msg);
  Map<String, dynamic> createDataChannel(
      String peerconnectionId, String label, DataChannelInitMessage msg);
  SessionDescriptionMessage createOffer(
      String peerconnectionId, ConstraintsMessage msg);
  void dispose(String peerconnectionId);
  SessionDescriptionMessage? getLocalDescription(String peerconnectionId);
  List<MediaStreamMessage> getLocalStreams(String peerconnectionId);
  List<MediaStreamMessage> getRemoteStreams(String peerconnectionId);
  List<Map<String, dynamic>> getReceivers(String peerconnectionId);
  List<Map<String, dynamic>> getSenders(String peerconnectionId);
  List<Map<String, dynamic>> getTransceivers(String peerconnectionId);
  List<StatsReportMessage> getStats(String peerconnectionId, String trackId);
  void removeStream(String peerconnectionId, String streamId);
  bool removeTrack(String peerconnectionId, String senderId);
  void restartIce(String peerconnectionId);
  void setConfiguration(String peerconnectionId, ConfigurationMessage msg);
  void setLocalDescription(
      String peerconnectionId, SessionDescriptionMessage msg);
  SessionDescriptionMessage getRemoteDescription(String peerconnectionId);
  void setRemoteDescription(
      String peerconnectionId, SessionDescriptionMessage msg);
}

@HostApi()
abstract class RTCDataChannelApi {
  void send(String peerconnectionId, DataChannelMessage message);
  void close(String peerconnectionId);
}

@HostApi()
abstract class RTCDTMFSenderApi {
  void insertDtmf(String peerconnectionId, String rtpSenderId, String tones,
      int duration, int interToneGap);
  bool canInsertDtmf(String peerconnectionId, String rtpSenderId);
}

@HostApi()
abstract class RTCRtpSenderApi {
  bool setParameters(String peerconnectionId, String rtpSenderId,
      RtpParametersMessage parameters);
  void replaceTrack(
      String peerconnectionId, String rtpSenderId, String trackId);
  void setTrack(String peerconnectionId, String rtpSenderId, String trackId,
      bool takeOwnership);
}

@HostApi()
abstract class RTCRtpTransceiverApi {
  void setDirection(
      String peerconnectionId, String transceiverId, String direction);
  String? getCurrentDirection(String peerconnectionId, String transceiverId);
  String getDirection(String peerconnectionId, String transceiverId);
  void stop(String peerconnectionId, String transceiverId);
  void setCodecPreferences(String peerconnectionId, String transceiverId,
      List<RtpCodecCapabilityMessage> codecs);
}

@HostApi()
abstract class RTCVideoRendererApi {
  int? initialize();
  void setSrcObject(
      int textureId, String streamId, String ownerTag, String? trackId);
  void dispose(int textureId);
}

@HostApi()
abstract class MediaRecorderApi {
  void start(String path, int audioChannel, String? videoTrackId,
      int recorderId, String? peerconnectionId);
  void stop(int recorderId);
}

@HostApi()
abstract class MediaStreamApi {
  void getMediaTracks(String streamId);
  void addTrack(String streamId, String trackId);
  void removeTrack(String streamId, String trackId);
  void dispose(String streamId);
}

@HostApi()
abstract class MediaStreamTrackApi {
  void enable(String trackId, bool enabled, String peerconnectionId);
  bool hasTorch(String trackId);
  void setTorch(String trackId, bool torch);
  void captureFrame(String trackId, String peerconnectionId, String path);
  void stop(String trackId);
}

@HostApi()
abstract class DesktopCapturerSourceApi {
  List<DesktopCapturerSourceMessage> getDesktopSources(
      List<String> types, ThumbnailSizeMessage thumbnailSize);
  bool updateSources(List<String> types);
  Uint8List? getThumbnail(String sourceId, ThumbnailSizeMessage thumbnailSize);
}

@HostApi()
abstract class MediaDevices {
  MediaStreamMessage getUserMedia(Map<String, dynamic> mediaConstraints);
  MediaStreamMessage getDisplayMedia(Map<String, dynamic> mediaConstraints);
  List<dynamic> getSources();
  List<MediaDeviceInfoMessage> enumerateDevices();
  MediaDeviceInfoMessage selectAudioOutput(String deviceId);
}
