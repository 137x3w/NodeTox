
/*
 * https://github.com/w3x731/NodeTox
 */

#include "toxcore.h"
#include <tox/tox.h>

Napi::FunctionReference ToxCore::constructor;

Napi::Object ToxCore::Init(Napi::Env env, Napi::Object exports) {
    Napi::HandleScope scope(env);

    Napi::Function func = DefineClass(env, "ToxCore", {    

        InstanceMethod("updateToxCallbackSelfConnectionStatus", &ToxCore::updateToxCallbackSelfConnectionStatus),
        InstanceMethod("updateToxCallbackFriendName", &ToxCore::updateToxCallbackFriendName),
        InstanceMethod("updateToxCallbackFriendStatusMessage", &ToxCore::updateToxCallbackFriendStatusMessage),
        InstanceMethod("updateToxCallbackFriendStatus", &ToxCore::updateToxCallbackFriendStatus),
        InstanceMethod("updateToxCallbackFriendConnectionStatus", &ToxCore::updateToxCallbackFriendConnectionStatus),
        InstanceMethod("updateToxCallbackFriendTyping", &ToxCore::updateToxCallbackFriendTyping),
        InstanceMethod("updateToxCallbackFriendReadReceipt", &ToxCore::updateToxCallbackFriendReadReceipt),
        InstanceMethod("updateToxCallbackFriendRequest", &ToxCore::updateToxCallbackFriendRequest),
        InstanceMethod("updateToxCallbackFriendMessage", &ToxCore::updateToxCallbackFriendMessage),
        InstanceMethod("updateToxCallbackFileRecvControl", &ToxCore::updateToxCallbackFileRecvControl),
        InstanceMethod("updateToxCallbackFileChunkRequest", &ToxCore::updateToxCallbackFileChunkRequest),
        InstanceMethod("updateToxCallbackFileRecv", &ToxCore::updateToxCallbackFileRecv),
        InstanceMethod("updateToxCallbackFileRecvChunk", &ToxCore::updateToxCallbackFileRecvChunk),
        InstanceMethod("updateToxCallbackConferenceInvite", &ToxCore::updateToxCallbackConferenceInvite),
        InstanceMethod("updateToxCallbackConferenceMessage", &ToxCore::updateToxCallbackConferenceMessage),
        InstanceMethod("updateToxCallbackConferenceTitle", &ToxCore::updateToxCallbackConferenceTitle),

        InstanceMethod("updateToxCallbackConferencePeerName", &ToxCore::updateToxCallbackConferencePeerName),
        InstanceMethod("updateToxCallbackConferencePeerListChanged", &ToxCore::updateToxCallbackConferencePeerListChanged),

        InstanceMethod("updateToxCallbackFriendLossyPacket", &ToxCore::updateToxCallbackFriendLossyPacket),
        InstanceMethod("updateToxCallbackFriendLosslessPacket", &ToxCore::updateToxCallbackFriendLosslessPacket),        

        InstanceMethod("toxVersionMajor", &ToxCore::toxVersionMajor),
        InstanceMethod("toxVersionMinor", &ToxCore::toxVersionMinor),
        InstanceMethod("toxVersionPatch", &ToxCore::toxVersionPatch),
        InstanceMethod("toxVersionIsCompatible", &ToxCore::toxVersionIsCompatible),

        InstanceMethod("toxPublicKeySize", &ToxCore::toxPublicKeySize),
        InstanceMethod("toxSecretKeySize", &ToxCore::toxSecretKeySize),
        InstanceMethod("toxNospamSize", &ToxCore::toxNospamSize),
        InstanceMethod("toxAddressSize", &ToxCore::toxAddressSize),
        InstanceMethod("toxMaxNameLength", &ToxCore::toxMaxNameLength),
        InstanceMethod("toxMaxStatusMessageLength", &ToxCore::toxMaxStatusMessageLength),
        InstanceMethod("toxMaxFriendRequestLength", &ToxCore::toxMaxFriendRequestLength),
        InstanceMethod("toxMaxMessageLength", &ToxCore::toxMaxMessageLength),
        InstanceMethod("toxMaxCustomPacketSize", &ToxCore::toxMaxCustomPacketSize),
        InstanceMethod("toxHashLength", &ToxCore::toxHashLength),
        InstanceMethod("toxFileIdLength", &ToxCore::toxFileIdLength),
        InstanceMethod("toxMaxFilenameLength", &ToxCore::toxMaxFilenameLength),

        InstanceMethod("toxOptionsGetIpv6Enabled", &ToxCore::toxOptionsGetIpv6Enabled),
        InstanceMethod("toxOptionsSetIpv6Enabled", &ToxCore::toxOptionsSetIpv6Enabled),
        InstanceMethod("toxOptionsGetUdpEnabled", &ToxCore::toxOptionsGetUdpEnabled),
        InstanceMethod("toxOptionsSetUdpEnabled", &ToxCore::toxOptionsSetUdpEnabled),
        InstanceMethod("toxOptionsGetLocalDiscoveryEnabled", &ToxCore::toxOptionsGetLocalDiscoveryEnabled),
        InstanceMethod("toxOptionsSetLocalDiscoveryEnabled", &ToxCore::toxOptionsSetLocalDiscoveryEnabled),
        InstanceMethod("toxOptionsGetProxyType", &ToxCore::toxOptionsGetProxyType),
        InstanceMethod("toxOptionsSetProxyType", &ToxCore::toxOptionsSetProxyType),
        InstanceMethod("toxOptionsGetProxyHost", &ToxCore::toxOptionsGetProxyHost),
        InstanceMethod("toxOptionsSetProxyHost", &ToxCore::toxOptionsSetProxyHost),
        InstanceMethod("toxOptionsGetProxyPort", &ToxCore::toxOptionsGetProxyPort),
        InstanceMethod("toxOptionsSetProxyPort", &ToxCore::toxOptionsSetProxyPort),
        InstanceMethod("toxOptionsGetStartPort", &ToxCore::toxOptionsGetStartPort),
        InstanceMethod("toxOptionsSetStartPort", &ToxCore::toxOptionsSetStartPort),
        InstanceMethod("toxOptionsGetEndPort", &ToxCore::toxOptionsGetEndPort),
        InstanceMethod("toxOptionsSetEndPort", &ToxCore::toxOptionsSetEndPort),
        InstanceMethod("toxOptionsGetTcpPort", &ToxCore::toxOptionsGetTcpPort),
        InstanceMethod("toxOptionsSetTcpPort", &ToxCore::toxOptionsSetTcpPort),
        InstanceMethod("toxOptionsGetHolePunchingEnabled", &ToxCore::toxOptionsGetHolePunchingEnabled),
        InstanceMethod("toxOptionsSetHolePunchingEnabled", &ToxCore::toxOptionsSetHolePunchingEnabled),
        InstanceMethod("toxOptionsGetSavedataType", &ToxCore::toxOptionsGetSavedataType),
        InstanceMethod("toxOptionsSetSavedataType", &ToxCore::toxOptionsSetSavedataType),
        InstanceMethod("toxOptionsGetSavedataData", &ToxCore::toxOptionsGetSavedataData),
        InstanceMethod("toxOptionsSetSavedataData", &ToxCore::toxOptionsSetSavedataData),
        InstanceMethod("toxOptionsGetSavedataLength", &ToxCore::toxOptionsGetSavedataLength),
        InstanceMethod("toxOptionsSetSavedataLength", &ToxCore::toxOptionsSetSavedataLength),
        // InstanceMethod("toxOptionsGetLogCallback", &ToxCore::toxOptionsGetLogCallback),
        // InstanceMethod("toxOptionsSetLogCallback", &ToxCore::toxOptionsSetLogCallback),
        // InstanceMethod("toxOptionsGetLogUserData", &ToxCore::toxOptionsGetLogUserData),
        // InstanceMethod("toxOptionsSetLogUserData", &ToxCore::toxOptionsSetLogUserData),
        InstanceMethod("toxOptionsDefault", &ToxCore::toxOptionsDefault),
        InstanceMethod("toxOptionsNew", &ToxCore::toxOptionsNew),
        InstanceMethod("toxOptionsFree", &ToxCore::toxOptionsFree),

        InstanceMethod("toxNew", &ToxCore::toxNew),
        InstanceMethod("toxKill", &ToxCore::toxKill),
        InstanceMethod("toxGetSavedataSize", &ToxCore::toxGetSavedataSize),
        InstanceMethod("toxGetSavedata", &ToxCore::toxGetSavedata),

        InstanceMethod("toxBootstrap", &ToxCore::toxBootstrap),
        InstanceMethod("toxAddTcpRelay", &ToxCore::toxAddTcpRelay),
        InstanceMethod("toxCallbackSelfConnectionStatus", &ToxCore::toxCallbackSelfConnectionStatus),
        InstanceMethod("toxSelfGetConnectionStatus", &ToxCore::toxSelfGetConnectionStatus),
        InstanceMethod("toxIterationInterval", &ToxCore::toxIterationInterval),
        InstanceMethod("toxIterate", &ToxCore::toxIterate),

        InstanceMethod("toxSelfGetAddress", &ToxCore::toxSelfGetAddress),
        InstanceMethod("toxSelfSetNospam", &ToxCore::toxSelfSetNospam),
        InstanceMethod("toxSelfGetNospam", &ToxCore::toxSelfGetNospam),
        InstanceMethod("toxSelfGetPublicKey", &ToxCore::toxSelfGetPublicKey),
        InstanceMethod("toxSelfGetSecretKey", &ToxCore::toxSelfGetSecretKey),

        InstanceMethod("toxSelfSetName", &ToxCore::toxSelfSetName),
        InstanceMethod("toxSelfGetNameSize", &ToxCore::toxSelfGetNameSize),
        InstanceMethod("toxSelfGetName", &ToxCore::toxSelfGetName),
        InstanceMethod("toxSelfSetStatusMessage", &ToxCore::toxSelfSetStatusMessage),
        InstanceMethod("toxSelfGetStatusMessageSize", &ToxCore::toxSelfGetStatusMessageSize),
        InstanceMethod("toxSelfGetStatusMessage", &ToxCore::toxSelfGetStatusMessage),
        InstanceMethod("toxSelfSetStatus", &ToxCore::toxSelfSetStatus),
        InstanceMethod("toxSelfGetStatus", &ToxCore::toxSelfGetStatus),

        InstanceMethod("toxFriendAdd", &ToxCore::toxFriendAdd),
        InstanceMethod("toxFriendAddNorequest", &ToxCore::toxFriendAddNorequest),
        InstanceMethod("toxFriendDelete", &ToxCore::toxFriendDelete),

        InstanceMethod("toxFriendByPublicKey", &ToxCore::toxFriendByPublicKey),
        InstanceMethod("toxFriendExists", &ToxCore::toxFriendExists),
        InstanceMethod("toxSelfGetFriendListSize", &ToxCore::toxSelfGetFriendListSize),
        InstanceMethod("toxSelfGetFriendList", &ToxCore::toxSelfGetFriendList),
        InstanceMethod("toxFriendGetPublicKey", &ToxCore::toxFriendGetPublicKey),
        InstanceMethod("toxFriendGetLastOnline", &ToxCore::toxFriendGetLastOnline),

        InstanceMethod("toxFriendGetNameSize", &ToxCore::toxFriendGetNameSize),
        InstanceMethod("toxFriendGetName", &ToxCore::toxFriendGetName),
        InstanceMethod("toxCallbackFriendName", &ToxCore::toxCallbackFriendName),
        InstanceMethod("toxFriendGetStatusMessageSize", &ToxCore::toxFriendGetStatusMessageSize),
        InstanceMethod("toxFriendGetStatusMessage", &ToxCore::toxFriendGetStatusMessage),
        InstanceMethod("toxCallbackFriendStatusMessage", &ToxCore::toxCallbackFriendStatusMessage),
        InstanceMethod("toxFriendGetStatus", &ToxCore::toxFriendGetStatus),
        InstanceMethod("toxCallbackFriendStatus", &ToxCore::toxCallbackFriendStatus),
        InstanceMethod("toxFriendGetConnectionStatus", &ToxCore::toxFriendGetConnectionStatus),
        InstanceMethod("toxCallbackFriendConnectionStatus", &ToxCore::toxCallbackFriendConnectionStatus),
        InstanceMethod("toxFriendGetTyping", &ToxCore::toxFriendGetTyping),
        InstanceMethod("toxCallbackFriendTyping", &ToxCore::toxCallbackFriendTyping),

        InstanceMethod("toxSelfSetTyping", &ToxCore::toxSelfSetTyping),
        InstanceMethod("toxFriendSendMessage", &ToxCore::toxFriendSendMessage),
        InstanceMethod("toxCallbackFriendReadReceipt", &ToxCore::toxCallbackFriendReadReceipt),
        InstanceMethod("toxCallbackFriendRequest", &ToxCore::toxCallbackFriendRequest),
        InstanceMethod("toxCallbackFriendMessage", &ToxCore::toxCallbackFriendMessage),

        InstanceMethod("toxHash", &ToxCore::toxHash),
        InstanceMethod("toxFileControl", &ToxCore::toxFileControl),
        InstanceMethod("toxCallbackFileRecvControl", &ToxCore::toxCallbackFileRecvControl),
        InstanceMethod("toxFileSeek", &ToxCore::toxFileSeek),
        InstanceMethod("toxFileGetFileId", &ToxCore::toxFileGetFileId),

        InstanceMethod("toxFileSend", &ToxCore::toxFileSend),
        InstanceMethod("toxFileSendChunk", &ToxCore::toxFileSendChunk),
        InstanceMethod("toxCallbackFileChunkRequest", &ToxCore::toxCallbackFileChunkRequest),

        InstanceMethod("toxCallbackFileRecv", &ToxCore::toxCallbackFileRecv),
        InstanceMethod("toxCallbackFileRecvChunk", &ToxCore::toxCallbackFileRecvChunk),

        InstanceMethod("toxCallbackConferenceInvite", &ToxCore::toxCallbackConferenceInvite),
        InstanceMethod("toxCallbackConferenceMessage", &ToxCore::toxCallbackConferenceMessage),
        InstanceMethod("toxCallbackConferenceTitle", &ToxCore::toxCallbackConferenceTitle),
        //
        InstanceMethod("toxCallbackConferencePeerName", &ToxCore::toxCallbackConferencePeerName),
        InstanceMethod("toxCallbackConferencePeerListChanged", &ToxCore::toxCallbackConferencePeerListChanged),        
        //
        InstanceMethod("toxConferenceNew", &ToxCore::toxConferenceNew),
        InstanceMethod("toxConferenceDelete", &ToxCore::toxConferenceDelete),
        InstanceMethod("toxConferencePeerCount", &ToxCore::toxConferencePeerCount),
        InstanceMethod("toxConferencePeerGetNameSize", &ToxCore::toxConferencePeerGetNameSize),
        InstanceMethod("toxConferencePeerGetName", &ToxCore::toxConferencePeerGetName),
        InstanceMethod("toxConferencePeerGetPublicKey", &ToxCore::toxConferencePeerGetPublicKey),
        InstanceMethod("toxConferencePeerNumberIsOurs", &ToxCore::toxConferencePeerNumberIsOurs),
        InstanceMethod("toxConferenceInvite", &ToxCore::toxConferenceInvite),
        InstanceMethod("toxConferenceJoin", &ToxCore::toxConferenceJoin),
        InstanceMethod("toxConferenceSendMessage", &ToxCore::toxConferenceSendMessage),
        InstanceMethod("toxConferenceGetTitleSize", &ToxCore::toxConferenceGetTitleSize),
        InstanceMethod("toxConferenceGetTitle", &ToxCore::toxConferenceGetTitle),
        InstanceMethod("toxConferenceSetTitle", &ToxCore::toxConferenceSetTitle),
        InstanceMethod("toxConferenceGetChatlistSize", &ToxCore::toxConferenceGetChatlistSize),
        InstanceMethod("toxConferenceGetChatlist", &ToxCore::toxConferenceGetChatlist),
        InstanceMethod("toxConferenceGetType", &ToxCore::toxConferenceGetType),

        InstanceMethod("toxFriendSendLossyPacket", &ToxCore::toxFriendSendLossyPacket),
        InstanceMethod("toxFriendSendLosslessPacket", &ToxCore::toxFriendSendLosslessPacket),
        InstanceMethod("toxCallbackFriendLossyPacket", &ToxCore::toxCallbackFriendLossyPacket),
        InstanceMethod("toxCallbackFriendLosslessPacket", &ToxCore::toxCallbackFriendLosslessPacket),

        InstanceMethod("toxSelfGetDhtId", &ToxCore::toxSelfGetDhtId),
        InstanceMethod("toxSelfGetUdpPort", &ToxCore::toxSelfGetUdpPort),
        InstanceMethod("toxSelfGetTcpPort", &ToxCore::toxSelfGetTcpPort)

    });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();

    exports.Set("ToxCore", func);
    return exports;
}

ToxCore::ToxCore(const Napi::CallbackInfo &info) : Napi::ObjectWrap<ToxCore>(info)
{
    toxOptions = 0;
    tox = 0;
}

/*  
 * Additional functions
 */

void ToxCore::convertFromChar2Uint8t(const char* source, uint8_t* result, size_t length)
{
    char c[] = { 0, 0 };
    for (int i = 0; i < length; i++) {
        c[0] = source[i * 2];
        c[1] = source[i * 2 + 1];
        result[i] = (uint8_t)(strtoul(c, NULL, 16));
    }
}

void ToxCore::convertFromUint64_t2Uint32_t(const uint64_t* source, uint32_t* result)
{
    result[0] = *source & 0xFFFFFFFF;
    result[1] = (*source & 0xFFFFFFFF00000000) >> 32;
}

void ToxCore::convertFromUint32_t2Uint64_t(const uint32_t* source, uint64_t* result)
{
    *result = ((uint64_t)source[1] << 32) + source[0];
}

void ToxCore::updateToxCallbackSelfConnectionStatus(const Napi::CallbackInfo& info)
{
    tox_callback_self_connection_status(tox, _selfConnectionStatusChanged);
}

void ToxCore::updateToxCallbackFriendName(const Napi::CallbackInfo& info)
{
    tox_callback_friend_name(tox, _friendNameChanged);
}

void ToxCore::updateToxCallbackFriendStatusMessage(const Napi::CallbackInfo& info)
{
    tox_callback_friend_status_message(tox, _friendStatusMessageChanged);
}

void ToxCore::updateToxCallbackFriendStatus(const Napi::CallbackInfo& info)
{
    tox_callback_friend_status(tox, _friendStatusChanged);
}

void ToxCore::updateToxCallbackFriendConnectionStatus(const Napi::CallbackInfo& info)
{
    tox_callback_friend_connection_status(tox, _friendConnectionStatusChanged);
}

void ToxCore::updateToxCallbackFriendTyping(const Napi::CallbackInfo& info)
{
    tox_callback_friend_typing(tox, _friendTypingChanged);
}

void ToxCore::updateToxCallbackFriendReadReceipt(const Napi::CallbackInfo& info)
{
    tox_callback_friend_read_receipt(tox, _friendReadReceiptChanged);
}

void ToxCore::updateToxCallbackFriendRequest(const Napi::CallbackInfo& info)
{
    tox_callback_friend_request(tox, _friendRequestChanged);
}

void ToxCore::updateToxCallbackFriendMessage(const Napi::CallbackInfo& info)
{
    tox_callback_friend_message(tox, _friendMessageChanged);
}

void ToxCore::updateToxCallbackFileRecvControl(const Napi::CallbackInfo& info)
{
    tox_callback_file_recv_control(tox, _fileRecvControlChanged);
}

void ToxCore::updateToxCallbackFileChunkRequest(const Napi::CallbackInfo& info)
{
    tox_callback_file_chunk_request(tox, _fileChunkRequestChanged);
}

void ToxCore::updateToxCallbackFileRecv(const Napi::CallbackInfo& info)
{
    tox_callback_file_recv(tox, _fileRecvChanged);
}

void ToxCore::updateToxCallbackFileRecvChunk(const Napi::CallbackInfo& info)
{
    tox_callback_file_recv_chunk(tox, _fileRecvChunkChanged);
}

void ToxCore::updateToxCallbackConferenceInvite(const Napi::CallbackInfo& info)
{
    tox_callback_conference_invite(tox, _conferenceInviteChanged);
}

void ToxCore::updateToxCallbackConferenceMessage(const Napi::CallbackInfo& info)
{
    tox_callback_conference_message(tox, _conferenceMessageChanged);
}

void ToxCore::updateToxCallbackConferenceTitle(const Napi::CallbackInfo& info)
{
    tox_callback_conference_title(tox, _conferenceTitleChanged);
}

void ToxCore::updateToxCallbackConferencePeerName(const Napi::CallbackInfo& info)
{
    tox_callback_conference_peer_name(tox, _conferencePeerNameChanged);
}

void ToxCore::updateToxCallbackConferencePeerListChanged(const Napi::CallbackInfo& info)
{
    tox_callback_conference_peer_list_changed(tox, _conferencePeerListChangedChanged);
}

void ToxCore::updateToxCallbackFriendLossyPacket(const Napi::CallbackInfo& info)
{
    tox_callback_friend_lossy_packet(tox, _friendLossyPacketChanged);
}

void ToxCore::updateToxCallbackFriendLosslessPacket(const Napi::CallbackInfo& info)
{
    tox_callback_friend_lossless_packet(tox, _friendLosslessPacketChanged);
}

/*
 * API version
 */

Napi::Value ToxCore::toxVersionMajor(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), tox_version_major());
}

Napi::Value ToxCore::toxVersionMinor(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), tox_version_minor());
}

Napi::Value ToxCore::toxVersionPatch(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), tox_version_patch());
}
    
Napi::Value ToxCore::toxVersionIsCompatible(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber() || !info[1].IsNumber() || !info[2].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t major = info[0].As<Napi::Number>().Uint32Value();
    uint32_t minor = info[1].As<Napi::Number>().Uint32Value();
    uint32_t patch = info[2].As<Napi::Number>().Uint32Value();

    return Napi::Boolean::New(env, tox_version_is_compatible(major, minor, patch));
}

/*
 * Numeric constants
 */

Napi::Value ToxCore::toxPublicKeySize(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), tox_public_key_size());
}

Napi::Value ToxCore::toxSecretKeySize(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), tox_secret_key_size());
}

Napi::Value ToxCore::toxNospamSize(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), TOX_NOSPAM_SIZE);
}

Napi::Value ToxCore::toxAddressSize(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), tox_address_size());
}

Napi::Value ToxCore::toxMaxNameLength(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), tox_max_name_length());
}

Napi::Value ToxCore::toxMaxStatusMessageLength(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), tox_max_status_message_length());
}

Napi::Value ToxCore::toxMaxFriendRequestLength(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), tox_max_friend_request_length());
}

Napi::Value ToxCore::toxMaxMessageLength(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), tox_max_message_length());
}

Napi::Value ToxCore::toxMaxCustomPacketSize(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), tox_max_custom_packet_size());
}

Napi::Value ToxCore::toxHashLength(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), tox_hash_length());
}

Napi::Value ToxCore::toxFileIdLength(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), tox_file_id_length());
}

Napi::Value ToxCore::toxMaxFilenameLength(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), tox_max_filename_length());
}

/*
 * Startup options
 */

Napi::Value ToxCore::toxOptionsGetIpv6Enabled(const Napi::CallbackInfo& info)
{
    return Napi::Boolean::New(info.Env(), tox_options_get_ipv6_enabled(toxOptions));
}

void ToxCore::toxOptionsSetIpv6Enabled(const Napi::CallbackInfo& info)
{   
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return;
    }

    if (!info[0].IsBoolean()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return;
    }

    bool ipv6_enabled = info[0].As<Napi::Boolean>().Value();
    tox_options_set_ipv6_enabled(toxOptions, ipv6_enabled);
}

Napi::Value ToxCore::toxOptionsGetUdpEnabled(const Napi::CallbackInfo& info)
{
    return Napi::Boolean::New(info.Env(), tox_options_get_udp_enabled(toxOptions));
}

void ToxCore::toxOptionsSetUdpEnabled(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return;
    }

    if (!info[0].IsBoolean()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return;
    }

    bool udp_enabled = info[0].As<Napi::Boolean>().Value();
    tox_options_set_udp_enabled(toxOptions, udp_enabled);
}

Napi::Value ToxCore::toxOptionsGetLocalDiscoveryEnabled(const Napi::CallbackInfo& info)
{
    return Napi::Boolean::New(info.Env(), tox_options_get_local_discovery_enabled(toxOptions));
}

void ToxCore::toxOptionsSetLocalDiscoveryEnabled(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return;
    }

    if (!info[0].IsBoolean()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return;
    }

    bool local_discovery_enabled = info[0].As<Napi::Boolean>().Value();
    tox_options_set_local_discovery_enabled(toxOptions, local_discovery_enabled);
}

Napi::Value ToxCore::toxOptionsGetProxyType(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), tox_options_get_proxy_type(toxOptions));
}

void ToxCore::toxOptionsSetProxyType(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return;
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return;
    }

    TOX_PROXY_TYPE type = (TOX_PROXY_TYPE)info[0].As<Napi::Number>().Uint32Value();
    tox_options_set_proxy_type(toxOptions, type);
}

Napi::Value ToxCore::toxOptionsGetProxyHost(const Napi::CallbackInfo& info)
{
    return Napi::String::New(info.Env(), tox_options_get_proxy_host(toxOptions));
}

void ToxCore::toxOptionsSetProxyHost(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return;
    }

    if (!info[0].IsString()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return;
    }
    
    tox_options_set_proxy_host(toxOptions, info[0].As<Napi::String>().Utf8Value().c_str());
}

Napi::Value ToxCore::toxOptionsGetProxyPort(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), tox_options_get_proxy_port(toxOptions));
}

void ToxCore::toxOptionsSetProxyPort(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return;
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return;
    }

    uint16_t port = (uint16_t)info[0].As<Napi::Number>().Uint32Value();
    tox_options_set_proxy_port(toxOptions, port);   
}

Napi::Value ToxCore::toxOptionsGetStartPort(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), tox_options_get_start_port(toxOptions));
}

void ToxCore::toxOptionsSetStartPort(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return;
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return;
    }

    uint16_t start_port = (uint16_t)info[0].As<Napi::Number>().Uint32Value();
    tox_options_set_start_port(toxOptions, start_port);   
}

Napi::Value ToxCore::toxOptionsGetEndPort(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), tox_options_get_end_port(toxOptions));
}

void ToxCore::toxOptionsSetEndPort(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return;
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return;
    }

    uint16_t end_port = (uint16_t)info[0].As<Napi::Number>().Uint32Value();
    tox_options_set_end_port(toxOptions, end_port);  
}

Napi::Value ToxCore::toxOptionsGetTcpPort(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), tox_options_get_tcp_port(toxOptions));
}

void ToxCore::toxOptionsSetTcpPort(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return;
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return;
    }

    uint16_t tcp_port = (uint16_t)info[0].As<Napi::Number>().Uint32Value();
    tox_options_set_tcp_port(toxOptions, tcp_port);  
}

Napi::Value ToxCore::toxOptionsGetHolePunchingEnabled(const Napi::CallbackInfo& info)
{
    return Napi::Boolean::New(info.Env(), tox_options_get_hole_punching_enabled(toxOptions));
}

void ToxCore::toxOptionsSetHolePunchingEnabled(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return;
    }

    if (!info[0].IsBoolean()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return;
    }

    bool hole_punching_enabled = info[0].As<Napi::Boolean>().Value();
    tox_options_set_tcp_port(toxOptions, hole_punching_enabled);  
}

Napi::Value ToxCore::toxOptionsGetSavedataType(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), tox_options_get_savedata_type(toxOptions));
}

void ToxCore::toxOptionsSetSavedataType(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return;
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return;
    }

    TOX_SAVEDATA_TYPE type = (TOX_SAVEDATA_TYPE)info[0].As<Napi::Number>().Uint32Value();
    tox_options_set_savedata_type(toxOptions, type);  
}

Napi::Value ToxCore::toxOptionsGetSavedataData(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    size_t length = (size_t)info[0].As<Napi::Number>().Uint32Value();
    return Napi::ArrayBuffer::New(info.Env(), (void*)tox_options_get_savedata_data(toxOptions), length);
}

void ToxCore::toxOptionsSetSavedataData(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return;
    }

    if (!info[0].IsTypedArray()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return;
    }

    Napi::TypedArray info0TypedArray = info[0].As<Napi::TypedArray>();
    if (info0TypedArray.TypedArrayType() != napi_uint8_array) {
        Napi::TypeError::New(env, "Wrong array type").ThrowAsJavaScriptException();
        return;
    }

    Napi::Uint8Array data = info0TypedArray.As<Napi::Uint8Array>();
    size_t length = (size_t)data.ByteLength();
    tox_options_set_savedata_data(toxOptions, (uint8_t*)data.Data(), length);
}

Napi::Value ToxCore::toxOptionsGetSavedataLength(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), tox_options_get_savedata_length(toxOptions));
}

void ToxCore::toxOptionsSetSavedataLength(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return;
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return;
    }

    size_t length = (size_t)info[0].As<Napi::Number>().Uint32Value();
    tox_options_set_savedata_length(toxOptions, length);  
}

// Napi::Value ToxCore::toxOptionsGetLogCallback(const Napi::CallbackInfo& info)
// {
//     
// }

// Napi::Value ToxCore::toxOptionsSetLogCallback(const Napi::CallbackInfo& info)
// {
//
// }

// Napi::Value ToxCore::toxOptionsGetLogUserData(const Napi::CallbackInfo& info)
// {
//
// }

// Napi::Value ToxCore::toxOptionsSetLogUserData(const Napi::CallbackInfo& info)
// {
//
// }

void ToxCore::toxOptionsDefault(const Napi::CallbackInfo& info)
{
    tox_options_default(toxOptions);
}

Napi::Value ToxCore::toxOptionsNew(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    TOX_ERR_OPTIONS_NEW error;
    toxOptions = tox_options_new(&error);

    Napi::Object result = Napi::Object::New(env);
    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));

    return result;
}

void ToxCore::toxOptionsFree(const Napi::CallbackInfo& info)
{
    tox_options_free(toxOptions);
}

/*
 * Creation and destruction
 */

Napi::Value ToxCore::toxNew(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    TOX_ERR_NEW error;
    tox = tox_new(toxOptions, &error);

    Napi::Object result = Napi::Object::New(env);
    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));

    return result;
}

void ToxCore::toxKill(const Napi::CallbackInfo& info)
{
    tox_kill(tox);
}

Napi::Value ToxCore::toxGetSavedataSize(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), tox_get_savedata_size(tox));
}

Napi::Value ToxCore::toxGetSavedata(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t length = info[0].As<Napi::Number>().Uint32Value();
    uint8_t* savedata = new uint8_t[length] { 0 };
    tox_get_savedata(tox, savedata);
    
    return Napi::ArrayBuffer::New(env, savedata, (size_t)length);
}

/*
 * Connection lifecycle and event loop
 */

Napi::Value ToxCore::toxBootstrap(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsString() || !info[1].IsNumber() || !info[2].IsString()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint16_t port = (uint16_t)info[1].As<Napi::Number>().Uint32Value();

    uint8_t* public_key = new uint8_t[TOX_PUBLIC_KEY_SIZE] { 0 };
    convertFromChar2Uint8t(info[2].As<Napi::String>().Utf8Value().c_str(), public_key, TOX_PUBLIC_KEY_SIZE);

    TOX_ERR_BOOTSTRAP error;
    bool returned = tox_bootstrap(tox, info[0].As<Napi::String>().Utf8Value().c_str(), port, public_key, &error);

    delete [] public_key;

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Boolean::New(env, returned));

    return result;    
}

Napi::Value ToxCore::toxAddTcpRelay(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsString() || !info[1].IsNumber() || !info[2].IsString()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint16_t port = (uint16_t)info[1].As<Napi::Number>().Uint32Value();
    uint8_t* public_key = new uint8_t[TOX_PUBLIC_KEY_SIZE] { 0 };
    convertFromChar2Uint8t(info[2].As<Napi::String>().Utf8Value().c_str(), public_key, TOX_PUBLIC_KEY_SIZE);

    TOX_ERR_BOOTSTRAP error;
    bool returned = tox_add_tcp_relay(tox, (const char*)info[0].As<Napi::String>().Utf8Value().c_str(), port, public_key, &error);

    delete [] public_key;

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Boolean::New(env, returned));

    return result;
}

void ToxCore::toxCallbackSelfConnectionStatus(const Napi::CallbackInfo& info)
{
    selfConnectionStatusCallback = Napi::Reference<Napi::Function>::New(info[0].As<Napi::Function>());
}

void ToxCore::_selfConnectionStatusChanged(Tox *tox, TOX_CONNECTION connection_status, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->selfConnectionStatusCallback.MakeCallback(toxCore->selfConnectionStatusCallback.Env().Global(), { Napi::Number::New(toxCore->selfConnectionStatusCallback.Env(), connection_status) });
}

Napi::Value ToxCore::toxSelfGetConnectionStatus(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), tox_self_get_connection_status(tox));
}

Napi::Value ToxCore::toxIterationInterval(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), tox_iteration_interval(tox));
}

void ToxCore::toxIterate(const Napi::CallbackInfo& info)
{
    tox_iterate(tox, this);
}

/*
 * Internal client information (Tox address/id)
 */

Napi::Value ToxCore::toxSelfGetAddress(const Napi::CallbackInfo& info)
{
    uint8_t* address = new uint8_t[TOX_ADDRESS_SIZE] { 0 };
    tox_self_get_address(tox, address);
    return Napi::ArrayBuffer::New(info.Env(), address, (size_t)TOX_ADDRESS_SIZE);
}

void ToxCore::toxSelfSetNospam(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return;
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return;
    }

    uint32_t nospam = info[0].As<Napi::Number>().Uint32Value();
    tox_self_set_nospam(tox, nospam);
}

Napi::Value ToxCore::toxSelfGetNospam(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), tox_self_get_nospam(tox));
}

Napi::Value ToxCore::toxSelfGetPublicKey(const Napi::CallbackInfo& info)
{
    uint8_t* public_key = new uint8_t[TOX_PUBLIC_KEY_SIZE] { 0 };
    tox_self_get_public_key(tox, public_key);
    return Napi::ArrayBuffer::New(info.Env(), public_key, (size_t)TOX_PUBLIC_KEY_SIZE);
}

Napi::Value ToxCore::toxSelfGetSecretKey(const Napi::CallbackInfo& info)
{
    uint8_t* secret_key = new uint8_t[TOX_SECRET_KEY_SIZE] { 0 };
    tox_self_get_public_key(tox, secret_key);
    return Napi::ArrayBuffer::New(info.Env(), secret_key, (size_t)TOX_SECRET_KEY_SIZE);   
}

/*
 * User-visible client information (nickname/status)
 */

Napi::Value ToxCore::toxSelfSetName(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsString()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    size_t length = info[0].As<Napi::String>().Utf8Value().length();

    TOX_ERR_SET_INFO error;
    bool returned = tox_self_set_name(tox, (const uint8_t*)info[0].As<Napi::String>().Utf8Value().c_str(), length, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Boolean::New(env, returned));

    return result;
}

Napi::Value ToxCore::toxSelfGetNameSize(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), tox_self_get_name_size(tox));
}

Napi::Value ToxCore::toxSelfGetName(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t length = info[0].As<Napi::Number>().Uint32Value();
    uint8_t* name = new uint8_t[length] { 0 };

    tox_self_get_name(tox, name);

    return Napi::String::New(env, (const char*)name, length);
}

Napi::Value ToxCore::toxSelfSetStatusMessage(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsString()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    size_t length = info[0].As<Napi::String>().Utf8Value().length();

    TOX_ERR_SET_INFO error;
    bool returned = tox_self_set_status_message(tox, (const uint8_t*)info[0].As<Napi::String>().Utf8Value().c_str(), length, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Boolean::New(env, returned));

    return result;
}

Napi::Value ToxCore::toxSelfGetStatusMessageSize(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), tox_self_get_status_message_size(tox));
}

Napi::Value ToxCore::toxSelfGetStatusMessage(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t length = info[0].As<Napi::Number>().Uint32Value();
    uint8_t* message = new uint8_t[length] { 0 };

    tox_self_get_status_message(tox, message);

    return Napi::String::New(env, (const char*)message, length);
}

void ToxCore::toxSelfSetStatus(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return;
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return;
    }

    TOX_USER_STATUS status = (TOX_USER_STATUS)info[0].As<Napi::Number>().Uint32Value();

    tox_self_set_status(tox, status);
}

Napi::Value ToxCore::toxSelfGetStatus(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), tox_self_get_status(tox));
}

/*
 * Friend list management
 */

Napi::Value ToxCore::toxFriendAdd(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsString() || !info[1].IsString()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint8_t* address = new uint8_t[TOX_ADDRESS_SIZE] { 0 };
    convertFromChar2Uint8t(info[0].As<Napi::String>().Utf8Value().c_str(), address, TOX_ADDRESS_SIZE);

    size_t length = info[1].As<Napi::String>().Utf8Value().length();

    uint8_t* message = new uint8_t[length] { 0 };
    convertFromChar2Uint8t(info[1].As<Napi::String>().Utf8Value().c_str(), message, length);

    TOX_ERR_FRIEND_ADD error;
    uint32_t returned = tox_friend_add(tox, address, message, length, &error);

    delete [] address;
    delete [] message;

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Number::New(env, returned));

    return result;
}

Napi::Value ToxCore::toxFriendAddNorequest(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsString()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint8_t* public_key = new uint8_t[TOX_PUBLIC_KEY_SIZE] { 0 };
    convertFromChar2Uint8t(info[0].As<Napi::String>().Utf8Value().c_str(), public_key, TOX_PUBLIC_KEY_SIZE);

    TOX_ERR_FRIEND_ADD error;
    uint32_t returned = tox_friend_add_norequest(tox, public_key, &error);
    
    delete [] public_key;

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Number::New(env, returned));

    return result;
}

Napi::Value ToxCore::toxFriendDelete(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t friend_number = info[0].As<Napi::Number>().Uint32Value();

    TOX_ERR_FRIEND_DELETE error;
    bool returned = tox_friend_delete(tox, friend_number, &error);
    
    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Boolean::New(env, returned));

    return result;
}

/*
 * Friend list queries
 */

Napi::Value ToxCore::toxFriendByPublicKey(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsString()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint8_t* public_key = new uint8_t[TOX_PUBLIC_KEY_SIZE] { 0 };
    convertFromChar2Uint8t(info[0].As<Napi::String>().Utf8Value().c_str(), public_key, TOX_PUBLIC_KEY_SIZE);

    TOX_ERR_FRIEND_BY_PUBLIC_KEY error;
    uint32_t returned = tox_friend_by_public_key(tox, public_key, &error);

    delete [] public_key;

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Number::New(env, returned));

    return result;
}

Napi::Value ToxCore::toxFriendExists(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t friend_number = info[0].As<Napi::Number>().Uint32Value();
    return Napi::Boolean::New(env, tox_friend_exists(tox, friend_number));
}

Napi::Value ToxCore::toxSelfGetFriendListSize(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), tox_self_get_friend_list_size(tox));
}

Napi::Value ToxCore::toxSelfGetFriendList(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    size_t length = info[0].As<Napi::Number>().Uint32Value();
    uint32_t* friend_list = new uint32_t[length] { 0 };

    tox_self_get_friend_list(tox, friend_list);
    return Napi::ArrayBuffer::New(info.Env(), friend_list, length * 4);
}

Napi::Value ToxCore::toxFriendGetPublicKey(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t friend_number = info[0].As<Napi::Number>().Uint32Value();
    uint8_t* public_key = new uint8_t[TOX_PUBLIC_KEY_SIZE] { 0 };

    TOX_ERR_FRIEND_GET_PUBLIC_KEY error;
    bool returned = tox_friend_get_public_key(tox, friend_number, public_key, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Boolean::New(env, returned));
    result.Set(Napi::String::New(env, "result"), Napi::ArrayBuffer::New(env, public_key, TOX_PUBLIC_KEY_SIZE));

    return result;
}

Napi::Value ToxCore::toxFriendGetLastOnline(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t friend_number = info[0].As<Napi::Number>().Uint32Value();

    TOX_ERR_FRIEND_GET_LAST_ONLINE error;
    uint64_t timestamp64_t = tox_friend_get_last_online(tox, friend_number, &error);

    uint32_t* timestamp32_t = new uint32_t[2] { 0 };
    convertFromUint64_t2Uint32_t(&timestamp64_t, timestamp32_t);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::ArrayBuffer::New(env, timestamp32_t, 2 * 4));

    return result;
}

/*
 * Friend-specific state queries (can also be received through callbacks)
 */

Napi::Value ToxCore::toxFriendGetNameSize(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t friend_number = info[0].As<Napi::Number>().Uint32Value();

    TOX_ERR_FRIEND_QUERY error;
    size_t returned = tox_friend_get_name_size(tox, friend_number, &error);
    
    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Number::New(env, returned));

    return result;
}

Napi::Value ToxCore::toxFriendGetName(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber() || !info[1].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    uint32_t friend_number = info[0].As<Napi::Number>().Uint32Value();

    size_t length = info[1].As<Napi::Number>().Uint32Value();
    uint8_t* name = new uint8_t[length] { 0 };

    TOX_ERR_FRIEND_QUERY error;
    bool returned = tox_friend_get_name(tox, friend_number, name, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Boolean::New(env, returned));
    result.Set(Napi::String::New(env, "result"), Napi::String::New(env, (const char*)name, length));

    return result;
}

void ToxCore::toxCallbackFriendName(const Napi::CallbackInfo& info)
{
    friendNameCallback = Napi::Reference<Napi::Function>::New(info[0].As<Napi::Function>());
}

void ToxCore::_friendNameChanged(Tox *tox, uint32_t friend_number, const uint8_t *name, size_t length, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;

    toxCore->friendNameCallback.MakeCallback(toxCore->friendNameCallback.Env().Global(), { 
        Napi::Number::New(toxCore->friendNameCallback.Env(), friend_number), 
        Napi::String::New(toxCore->friendNameCallback.Env(), (const char*)name, length)
    });
}

Napi::Value ToxCore::toxFriendGetStatusMessageSize(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t friend_number = info[0].As<Napi::Number>().Uint32Value();

    TOX_ERR_FRIEND_QUERY error;
    size_t returned = tox_friend_get_status_message_size(tox, friend_number, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Number::New(env, returned));

    return result;
}

Napi::Value ToxCore::toxFriendGetStatusMessage(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber() || !info[1].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t friend_number = info[0].As<Napi::Number>().Uint32Value();

    size_t length = info[1].As<Napi::Number>().Uint32Value();
    uint8_t* status_message = new uint8_t[length] { 0 };

    TOX_ERR_FRIEND_QUERY error;
    bool returned = tox_friend_get_status_message(tox, friend_number, status_message, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Boolean::New(env, returned));
    result.Set(Napi::String::New(env, "result"), Napi::String::New(env, (const char*)status_message, length));

    return result;
}

void ToxCore::toxCallbackFriendStatusMessage(const Napi::CallbackInfo& info)
{
    friendStatusMessageCallback = Napi::Reference<Napi::Function>::New(info[0].As<Napi::Function>());
}

void ToxCore::_friendStatusMessageChanged(Tox *tox, uint32_t friend_number, const uint8_t *message, size_t length, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    
    toxCore->friendStatusMessageCallback.MakeCallback(toxCore->friendStatusMessageCallback.Env().Global(), { 
        Napi::Number::New(toxCore->friendStatusMessageCallback.Env(), friend_number), 
        Napi::String::New(toxCore->friendStatusMessageCallback.Env(), (const char*)message, length)
    });
}

Napi::Value ToxCore::toxFriendGetStatus(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t friend_number = info[0].As<Napi::Number>().Uint32Value();

    TOX_ERR_FRIEND_QUERY error;
    TOX_USER_STATUS returned = tox_friend_get_status(tox, friend_number, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Number::New(env, returned));

    return result;    
}

void ToxCore::toxCallbackFriendStatus(const Napi::CallbackInfo& info)
{
    friendStatusCallback = Napi::Reference<Napi::Function>::New(info[0].As<Napi::Function>());
}

void ToxCore::_friendStatusChanged(Tox *tox, uint32_t friend_number, TOX_USER_STATUS status, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->friendStatusCallback.MakeCallback(toxCore->friendStatusCallback.Env().Global(), { 
        Napi::Number::New(toxCore->friendStatusCallback.Env(), friend_number), 
        Napi::Number::New(toxCore->friendStatusCallback.Env(), status) 
    });
}

Napi::Value ToxCore::toxFriendGetConnectionStatus(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t friend_number = info[0].As<Napi::Number>().Uint32Value();

    TOX_ERR_FRIEND_QUERY error;
    TOX_CONNECTION returned = tox_friend_get_connection_status(tox, friend_number, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Number::New(env, returned));

    return result;
}

void ToxCore::toxCallbackFriendConnectionStatus(const Napi::CallbackInfo& info)
{
    friendConnectionStatusCallback = Napi::Reference<Napi::Function>::New(info[0].As<Napi::Function>());
}

void ToxCore::_friendConnectionStatusChanged(Tox *tox, uint32_t friend_number, TOX_CONNECTION connection_status, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->friendConnectionStatusCallback.MakeCallback(toxCore->friendConnectionStatusCallback.Env().Global(), { 
        Napi::Number::New(toxCore->friendConnectionStatusCallback.Env(), friend_number), 
        Napi::Number::New(toxCore->friendConnectionStatusCallback.Env(), connection_status) 
    });
}

Napi::Value ToxCore::toxFriendGetTyping(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t friend_number = info[0].As<Napi::Number>().Uint32Value();

    TOX_ERR_FRIEND_QUERY error;
    bool returned = tox_friend_get_typing(tox, friend_number, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Boolean::New(env, returned));

    return result;
}

void ToxCore::toxCallbackFriendTyping(const Napi::CallbackInfo& info)
{
    friendTypingCallback = Napi::Reference<Napi::Function>::New(info[0].As<Napi::Function>());
}

void ToxCore::_friendTypingChanged(Tox *tox, uint32_t friend_number, bool is_typing, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->friendTypingCallback.MakeCallback(toxCore->friendTypingCallback.Env().Global(), { 
        Napi::Number::New(toxCore->friendTypingCallback.Env(), friend_number), 
        Napi::Boolean::New(toxCore->friendTypingCallback.Env(), is_typing) 
    });
}

/*
 * Sending private messages
 */

Napi::Value ToxCore::toxSelfSetTyping(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber() || !info[1].IsBoolean()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t friend_number = info[0].As<Napi::Number>().Uint32Value();
    bool typing = info[1].As<Napi::Boolean>().Value();

    TOX_ERR_SET_TYPING error;
    bool returned = tox_self_set_typing(tox, friend_number, typing, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Boolean::New(env, returned));

    return result;
}

Napi::Value ToxCore::toxFriendSendMessage(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber() || !info[1].IsNumber() || !info[2].IsString()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    uint32_t friend_number = info[0].As<Napi::Number>().Uint32Value();
    TOX_MESSAGE_TYPE type = (TOX_MESSAGE_TYPE)info[1].As<Napi::Number>().Uint32Value();
    size_t length = info[2].As<Napi::String>().Utf8Value().length();

    TOX_ERR_FRIEND_SEND_MESSAGE error;
    uint32_t returned = tox_friend_send_message(tox, friend_number, type, (const uint8_t*)info[2].As<Napi::String>().Utf8Value().c_str(), length, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Number::New(env, returned));

    return result;
}

void ToxCore::toxCallbackFriendReadReceipt(const Napi::CallbackInfo& info)
{
    friendReadReceiptCallback = Napi::Reference<Napi::Function>::New(info[0].As<Napi::Function>());
}

void ToxCore::_friendReadReceiptChanged(Tox *tox, uint32_t friend_number, uint32_t message_id, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->friendReadReceiptCallback.MakeCallback(toxCore->friendReadReceiptCallback.Env().Global(), { 
        Napi::Number::New(toxCore->friendReadReceiptCallback.Env(), friend_number), 
        Napi::Number::New(toxCore->friendReadReceiptCallback.Env(), message_id)
    });
}

void ToxCore::toxCallbackFriendRequest(const Napi::CallbackInfo& info)
{
    friendRequestCallback = Napi::Reference<Napi::Function>::New(info[0].As<Napi::Function>());
}

void ToxCore::_friendRequestChanged(Tox *tox, const uint8_t *public_key, const uint8_t *message, size_t length, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->friendRequestCallback.MakeCallback(toxCore->friendRequestCallback.Env().Global(), { 
        Napi::ArrayBuffer::New(toxCore->friendRequestCallback.Env(), (void*)public_key, TOX_PUBLIC_KEY_SIZE),
        Napi::String::New(toxCore->friendRequestCallback.Env(), (const char*)message, length) 
    });
}

void ToxCore::toxCallbackFriendMessage(const Napi::CallbackInfo& info)
{
    friendMessageCallback = Napi::Reference<Napi::Function>::New(info[0].As<Napi::Function>());
}

void ToxCore::_friendMessageChanged(Tox *tox, uint32_t friend_number, TOX_MESSAGE_TYPE type, const uint8_t *message, size_t length, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->friendMessageCallback.MakeCallback(toxCore->friendMessageCallback.Env().Global(), { 
        Napi::Number::New(toxCore->friendMessageCallback.Env(), friend_number), 
        Napi::Number::New(toxCore->friendMessageCallback.Env(), type), 
        Napi::String::New(toxCore->friendMessageCallback.Env(), (const char*)message, length)
    });
}

/*
 * File transmission: common between sending and receiving
 */

Napi::Value ToxCore::toxHash(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsTypedArray()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    Napi::TypedArray info0TypedArray = info[0].As<Napi::TypedArray>();
    if (info0TypedArray.TypedArrayType() != napi_uint8_array) {
        Napi::TypeError::New(env, "Wrong array type").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    uint8_t* hash = new uint8_t[TOX_HASH_LENGTH] { 0 };
    Napi::Uint8Array data = info0TypedArray.As<Napi::Uint8Array>();
    size_t length = (size_t)data.ByteLength();

    bool returned = tox_hash(hash, (const uint8_t*)data.Data(), length);
    
    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "return"), Napi::Number::New(env, returned));
    result.Set(Napi::String::New(env, "result"), Napi::ArrayBuffer::New(env, hash, TOX_HASH_LENGTH));

    return result;
}

Napi::Value ToxCore::toxFileControl(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber() || !info[1].IsNumber() || !info[2].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t friend_number = info[0].As<Napi::Number>().Uint32Value();
    uint32_t file_number = info[1].As<Napi::Number>().Uint32Value();
    TOX_FILE_CONTROL control = (TOX_FILE_CONTROL)info[2].As<Napi::Number>().Uint32Value();

    TOX_ERR_FILE_CONTROL error;
    bool returned = tox_file_control(tox, friend_number, file_number, control, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Boolean::New(env, returned));

    return result;
}

void ToxCore::toxCallbackFileRecvControl(const Napi::CallbackInfo& info)
{
    fileRecvControlCallback = Napi::Reference<Napi::Function>::New(info[0].As<Napi::Function>());
}

void ToxCore::_fileRecvControlChanged(Tox *tox, uint32_t friend_number, uint32_t file_number, TOX_FILE_CONTROL control, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->fileRecvControlCallback.MakeCallback(toxCore->fileRecvControlCallback.Env().Global(), { 
        Napi::Number::New(toxCore->fileRecvControlCallback.Env(), friend_number), 
        Napi::Number::New(toxCore->fileRecvControlCallback.Env(), file_number), 
        Napi::Number::New(toxCore->fileRecvControlCallback.Env(), control)
    });
}

Napi::Value ToxCore::toxFileSeek(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber() || !info[1].IsNumber() || !info[2].IsTypedArray()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    Napi::TypedArray info2TypedArray = info[2].As<Napi::TypedArray>();
    if (info2TypedArray.TypedArrayType() != napi_uint8_array) {
        Napi::TypeError::New(env, "Wrong array type").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t friend_number = info[0].As<Napi::Number>().Uint32Value();
    uint32_t file_number = info[1].As<Napi::Number>().Uint32Value();
    uint64_t position = 0;
    Napi::Uint8Array data = info2TypedArray.As<Napi::Uint8Array>();

    convertFromUint32_t2Uint64_t((uint32_t*)data.Data(), &position);

    TOX_ERR_FILE_SEEK error;
    bool returned = tox_file_seek(tox, friend_number, file_number, position, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Boolean::New(env, returned));

    return result;
}

Napi::Value ToxCore::toxFileGetFileId(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber() || !info[1].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t friend_number = info[0].As<Napi::Number>().Uint32Value();
    uint32_t file_number = info[1].As<Napi::Number>().Uint32Value();
    uint8_t *file_id = new uint8_t[TOX_FILE_ID_LENGTH] { 0 };

    TOX_ERR_FILE_GET error;
    bool returned = tox_file_get_file_id(tox, friend_number, file_number, file_id, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Boolean::New(env, returned));
    result.Set(Napi::String::New(env, "result"), Napi::ArrayBuffer::New(env, file_id, TOX_FILE_ID_LENGTH));

    return result;
}

/*
 * File transmission: sending
 */

Napi::Value ToxCore::toxFileSend(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    // arg[3] must be a string
    if (!info[0].IsNumber() || !info[1].IsNumber() || !info[2].IsTypedArray() || !info[3].IsTypedArray() || !info[4].IsString()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    Napi::TypedArray info2TypedArray = info[2].As<Napi::TypedArray>();
    Napi::TypedArray info3TypedArray = info[3].As<Napi::TypedArray>();
    if (info2TypedArray.TypedArrayType() != napi_uint8_array || info3TypedArray.TypedArrayType() != napi_uint8_array) {
        Napi::TypeError::New(env, "Wrong array type").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t friend_number = info[0].As<Napi::Number>().Uint32Value();
    uint32_t kind = info[1].As<Napi::Number>().Uint32Value();
    uint64_t file_size = 0;
    convertFromUint32_t2Uint64_t((uint32_t*)info2TypedArray.As<Napi::Uint8Array>().Data(), &file_size);
    size_t filename_length = info[4].As<Napi::String>().Utf8Value().length();
    Napi::Uint8Array file_id = info3TypedArray.As<Napi::Uint8Array>();

    TOX_ERR_FILE_SEND error;
    uint32_t returned = tox_file_send(tox, friend_number, kind, file_size, (const uint8_t*)file_id.Data(), (const uint8_t *)info[4].As<Napi::String>().Utf8Value().c_str(), filename_length, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Number::New(env, returned));

    return result;
}

Napi::Value ToxCore::toxFileSendChunk(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber() || !info[1].IsNumber() || !info[2].IsTypedArray() || !info[3].IsTypedArray()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    Napi::TypedArray info2TypedArray = info[2].As<Napi::TypedArray>();
    Napi::TypedArray info3TypedArray = info[3].As<Napi::TypedArray>();
    if (info2TypedArray.TypedArrayType() != napi_uint8_array || info3TypedArray.TypedArrayType() != napi_uint8_array) {
        Napi::TypeError::New(env, "Wrong array type").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t friend_number = info[0].As<Napi::Number>().Uint32Value();
    uint32_t file_number = info[1].As<Napi::Number>().Uint32Value();
    uint64_t position = 0;
    convertFromUint32_t2Uint64_t((uint32_t*)info[2].As<Napi::Uint8Array>().Data(), &position);
    Napi::Uint8Array data = info3TypedArray.As<Napi::Uint8Array>();
    size_t length = (size_t)data.ByteLength();

    TOX_ERR_FILE_SEND_CHUNK error;
    bool returned = tox_file_send_chunk(tox, friend_number, file_number, position, (const uint8_t*)data.Data(), length, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Number::New(env, returned));

    return result;
}

void ToxCore::toxCallbackFileChunkRequest(const Napi::CallbackInfo& info)
{
    fileChunkRequestCallback = Napi::Reference<Napi::Function>::New(info[0].As<Napi::Function>());
}

void ToxCore::_fileChunkRequestChanged(Tox *tox, uint32_t friend_number, uint32_t file_number, uint64_t position, size_t length, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    uint32_t* position32 = new uint32_t[2] { 0 };
    ToxCore::convertFromUint64_t2Uint32_t(&position, position32);
    toxCore->fileChunkRequestCallback.MakeCallback(toxCore->fileChunkRequestCallback.Env().Global(), { 
        Napi::Number::New(toxCore->fileChunkRequestCallback.Env(), friend_number), 
        Napi::Number::New(toxCore->fileChunkRequestCallback.Env(), file_number), 
        Napi::ArrayBuffer::New(toxCore->fileChunkRequestCallback.Env(), position32, 8), 
        Napi::Number::New(toxCore->fileChunkRequestCallback.Env(), length) 
    });
}

/*
 * File transmission: receiving
 */

void ToxCore::toxCallbackFileRecv(const Napi::CallbackInfo& info)
{
    fileRecvCallback = Napi::Reference<Napi::Function>::New(info[0].As<Napi::Function>());
}

void ToxCore::_fileRecvChanged(Tox *tox, uint32_t friend_number, uint32_t file_number, uint32_t kind, uint64_t file_size, const uint8_t *filename, size_t filename_length, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    uint32_t* file_size32 = new uint32_t[2] { 0 };
    ToxCore::convertFromUint64_t2Uint32_t(&file_size, file_size32);
    toxCore->fileRecvCallback.MakeCallback(toxCore->fileRecvCallback.Env().Global(), { 
        Napi::Number::New(toxCore->fileRecvCallback.Env(), friend_number), 
        Napi::Number::New(toxCore->fileRecvCallback.Env(), file_number),
        Napi::Number::New(toxCore->fileRecvCallback.Env(), kind), 
        Napi::ArrayBuffer::New(toxCore->fileRecvCallback.Env(), file_size32, 8),
        Napi::String::New(toxCore->fileRecvCallback.Env(), (const char*)filename, filename_length) 
    });
}

void ToxCore::toxCallbackFileRecvChunk(const Napi::CallbackInfo& info)
{
    fileRecvChunkCallback = Napi::Reference<Napi::Function>::New(info[0].As<Napi::Function>());
}

void ToxCore::_fileRecvChunkChanged(Tox *tox, uint32_t friend_number, uint32_t file_number, uint64_t position, const uint8_t *data, size_t length, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    uint32_t* position32 = new uint32_t[2] { 0 };
    ToxCore::convertFromUint64_t2Uint32_t(&position, position32);
    toxCore->fileRecvChunkCallback.MakeCallback(toxCore->fileRecvChunkCallback.Env().Global(), { 
        Napi::Number::New(toxCore->fileRecvChunkCallback.Env(), friend_number), 
        Napi::Number::New(toxCore->fileRecvChunkCallback.Env(), file_number),
        Napi::ArrayBuffer::New(toxCore->fileRecvChunkCallback.Env(), position32, 8),
        Napi::ArrayBuffer::New(toxCore->fileRecvChunkCallback.Env(), (void*)data, length)
    });
}

/*
 * Conference management
 */

void ToxCore::toxCallbackConferenceInvite(const Napi::CallbackInfo& info)
{
    conferenceInviteCallback = Napi::Reference<Napi::Function>::New(info[0].As<Napi::Function>());
}

void ToxCore::_conferenceInviteChanged(Tox *tox, uint32_t friend_number, TOX_CONFERENCE_TYPE type, const uint8_t *cookie, size_t length, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->conferenceInviteCallback.MakeCallback(toxCore->conferenceInviteCallback.Env().Global(), { 
        Napi::Number::New(toxCore->conferenceInviteCallback.Env(), friend_number), 
        Napi::Number::New(toxCore->conferenceInviteCallback.Env(), type),
        Napi::ArrayBuffer::New(toxCore->conferenceInviteCallback.Env(), (void*)cookie, length)
    });
}

void ToxCore::toxCallbackConferenceMessage(const Napi::CallbackInfo& info)
{
    conferenceMessageCallback = Napi::Reference<Napi::Function>::New(info[0].As<Napi::Function>());
}

void ToxCore::_conferenceMessageChanged(Tox *tox, uint32_t conference_number, uint32_t peer_number, TOX_MESSAGE_TYPE type, const uint8_t *message, size_t length, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->conferenceMessageCallback.MakeCallback(toxCore->conferenceMessageCallback.Env().Global(), { 
        Napi::Number::New(toxCore->conferenceMessageCallback.Env(), conference_number),
        Napi::Number::New(toxCore->conferenceMessageCallback.Env(), peer_number), 
        Napi::Number::New(toxCore->conferenceMessageCallback.Env(), type),
        Napi::String::New(toxCore->conferenceMessageCallback.Env(), (const char*)message, length)
    });
}

void ToxCore::toxCallbackConferenceTitle(const Napi::CallbackInfo& info)
{
    conferenceTitleCallback = Napi::Reference<Napi::Function>::New(info[0].As<Napi::Function>());
}

void ToxCore::_conferenceTitleChanged(Tox *tox, uint32_t conference_number, uint32_t peer_number, const uint8_t *title, size_t length, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;

    toxCore->conferenceTitleCallback.MakeCallback(toxCore->conferenceTitleCallback.Env().Global(), { 
        Napi::Number::New(toxCore->conferenceTitleCallback.Env(), conference_number),
        Napi::Number::New(toxCore->conferenceTitleCallback.Env(), peer_number), 
        Napi::String::New(toxCore->conferenceTitleCallback.Env(), (const char*)title, length)
    });
}

void ToxCore::toxCallbackConferencePeerName(const Napi::CallbackInfo& info)
{
    conferencePeerNameCallback = Napi::Reference<Napi::Function>::New(info[0].As<Napi::Function>());
}

void ToxCore::_conferencePeerNameChanged(Tox *tox, uint32_t conference_number, uint32_t peer_number, const uint8_t *name, size_t length, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;

    toxCore->conferencePeerNameCallback.MakeCallback(toxCore->conferencePeerNameCallback.Env().Global(), {
        Napi::Number::New(toxCore->conferencePeerNameCallback.Env(), conference_number),
        Napi::Number::New(toxCore->conferencePeerNameCallback.Env(), peer_number), 
        Napi::String::New(toxCore->conferencePeerNameCallback.Env(), (const char*)name, length)
    });
}

void ToxCore::toxCallbackConferencePeerListChanged(const Napi::CallbackInfo& info)
{
    conferencePeerListChangedCallback = Napi::Reference<Napi::Function>::New(info[0].As<Napi::Function>());
}

void ToxCore::_conferencePeerListChangedChanged(Tox *tox, uint32_t conference_number, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;

    toxCore->conferencePeerListChangedCallback.MakeCallback(toxCore->conferencePeerListChangedCallback.Env().Global(), {
        Napi::Number::New(toxCore->conferencePeerListChangedCallback.Env(), conference_number)
    });
}

Napi::Value ToxCore::toxConferenceNew(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    TOX_ERR_CONFERENCE_NEW error;
    uint32_t returned = tox_conference_new(tox, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Number::New(env, returned));

    return result;
}

Napi::Value ToxCore::toxConferenceDelete(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t conference_number = info[0].As<Napi::Number>().Uint32Value();

    TOX_ERR_CONFERENCE_DELETE error;
    bool returned = tox_conference_delete(tox, conference_number, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Boolean::New(env, returned));

    return result;
}

Napi::Value ToxCore::toxConferencePeerCount(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t conference_number = info[0].As<Napi::Number>().Uint32Value();

    TOX_ERR_CONFERENCE_PEER_QUERY error;
    uint32_t returned = tox_conference_peer_count(tox, conference_number, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Number::New(env, returned));

    return result;
}

Napi::Value ToxCore::toxConferencePeerGetNameSize(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber() || !info[1].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t conference_number = info[0].As<Napi::Number>().Uint32Value();
    uint32_t peer_number = info[1].As<Napi::Number>().Uint32Value();

    TOX_ERR_CONFERENCE_PEER_QUERY error;
    size_t returned = tox_conference_peer_get_name_size(tox, conference_number, peer_number, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Number::New(env, returned));

    return result;
}

Napi::Value ToxCore::toxConferencePeerGetName(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber() || !info[1].IsNumber() || !info[2].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t conference_number = info[0].As<Napi::Number>().Uint32Value();
    uint32_t peer_number = info[1].As<Napi::Number>().Uint32Value();
    uint32_t name_size = info[2].As<Napi::Number>().Uint32Value();
    uint8_t* name = new uint8_t[name_size] { 0 };

    TOX_ERR_CONFERENCE_PEER_QUERY error;
    bool returned = tox_conference_peer_get_name(tox, conference_number, peer_number, name, &error);
    
    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Boolean::New(env, returned));
    result.Set(Napi::String::New(env, "result"), Napi::String::New(env, (const char*)name, name_size));

    return result;
}

Napi::Value ToxCore::toxConferencePeerGetPublicKey(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber() || !info[1].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t conference_number = info[0].As<Napi::Number>().Uint32Value();
    uint32_t peer_number = info[1].As<Napi::Number>().Uint32Value();
    uint8_t* public_key = new uint8_t[TOX_PUBLIC_KEY_SIZE] { 0 };

    TOX_ERR_CONFERENCE_PEER_QUERY error;
    bool returned = tox_conference_peer_get_public_key(tox, conference_number, peer_number, public_key, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Boolean::New(env, returned));
    result.Set(Napi::String::New(env, "result"), Napi::ArrayBuffer::New(env, public_key, TOX_PUBLIC_KEY_SIZE));

    return result;
}

Napi::Value ToxCore::toxConferencePeerNumberIsOurs(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber() || !info[1].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t conference_number = info[0].As<Napi::Number>().Uint32Value();
    uint32_t peer_number = info[1].As<Napi::Number>().Uint32Value();

    TOX_ERR_CONFERENCE_PEER_QUERY error;
    bool returned = tox_conference_peer_number_is_ours(tox, conference_number, peer_number, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Boolean::New(env, returned));

    return result;
}

Napi::Value ToxCore::toxConferenceInvite(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber() || !info[1].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t friend_number = info[0].As<Napi::Number>().Uint32Value();
    uint32_t conference_number = info[1].As<Napi::Number>().Uint32Value();

    TOX_ERR_CONFERENCE_INVITE error;
    bool returned = tox_conference_invite(tox, friend_number, conference_number, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Boolean::New(env, returned));

    return result;
}

Napi::Value ToxCore::toxConferenceJoin(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber() || !info[1].IsTypedArray()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    Napi::TypedArray info1TypedArray = info[1].As<Napi::TypedArray>();
    if (info1TypedArray.TypedArrayType() != napi_uint8_array) {
        Napi::TypeError::New(env, "Wrong array type").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t friend_number = info[0].As<Napi::Number>().Uint32Value();
    Napi::Uint8Array cookie = info1TypedArray.As<Napi::Uint8Array>();
    size_t length = (size_t)cookie.ByteLength();

    TOX_ERR_CONFERENCE_JOIN error;
    uint32_t returned = tox_conference_join(tox, friend_number, cookie.Data(), length, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Number::New(env, returned));

    return result;
}

Napi::Value ToxCore::toxConferenceSendMessage(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber() || !info[1].IsNumber() || !info[2].IsString()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    uint32_t conference_number = info[0].As<Napi::Number>().Uint32Value();
    TOX_MESSAGE_TYPE type = (TOX_MESSAGE_TYPE)info[1].As<Napi::Number>().Uint32Value();
    size_t length = (size_t)info[2].As<Napi::String>().Utf8Value().length();

    TOX_ERR_CONFERENCE_SEND_MESSAGE error;
    bool returned = tox_conference_send_message(tox, conference_number, type, (const uint8_t*)info[2].As<Napi::String>().Utf8Value().c_str(), length, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Boolean::New(env, returned));

    return result;
}

Napi::Value ToxCore::toxConferenceGetTitleSize(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    uint32_t conference_number = info[0].As<Napi::Number>().Uint32Value();

    TOX_ERR_CONFERENCE_TITLE error;
    size_t returned = tox_conference_get_title_size(tox, conference_number, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Number::New(env, returned));

    return result;
}

Napi::Value ToxCore::toxConferenceGetTitle(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber() || !info[1].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    uint32_t conference_number = info[0].As<Napi::Number>().Uint32Value();
    size_t title_size = info[1].As<Napi::Number>().Uint32Value();
    uint8_t* title = new uint8_t[title_size] { 0 };

    TOX_ERR_CONFERENCE_TITLE error;
    bool returned = tox_conference_get_title(tox, conference_number, title, &error);
    
    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Boolean::New(env, returned));
    result.Set(Napi::String::New(env, "result"), Napi::String::New(env, (const char*)title, title_size));

    return result;
}

Napi::Value ToxCore::toxConferenceSetTitle(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber() || !info[1].IsString()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    uint32_t conference_number = info[0].As<Napi::Number>().Uint32Value();
    size_t length = (size_t)info[1].As<Napi::String>().Utf8Value().length();

    TOX_ERR_CONFERENCE_TITLE error;
    bool returned = tox_conference_set_title(tox, conference_number, (const uint8_t*)info[1].As<Napi::String>().Utf8Value().c_str(), length, &error);
    
    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Boolean::New(env, returned));

    return result;
}

Napi::Value ToxCore::toxConferenceGetChatlistSize(const Napi::CallbackInfo& info)
{
    return Napi::Number::New(info.Env(), tox_conference_get_chatlist_size(tox));
}

Napi::Value ToxCore::toxConferenceGetChatlist(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    size_t size = info[0].As<Napi::Number>().Uint32Value();
    uint32_t* chatlist = new uint32_t[size] { 0 };
    
    tox_conference_get_chatlist(tox, chatlist);
    return Napi::ArrayBuffer::New(env, chatlist, size * 4);
}

Napi::Value ToxCore::toxConferenceGetType(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    uint32_t conference_number = info[0].As<Napi::Number>().Uint32Value();

    TOX_ERR_CONFERENCE_GET_TYPE error;
    TOX_CONFERENCE_TYPE returned = tox_conference_get_type(tox, conference_number, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Number::New(env, returned));

    return result;
}

/*
 * Low-level custom packet sending and receiving
 */

Napi::Value ToxCore::toxFriendSendLossyPacket(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber() || !info[1].IsTypedArray()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    Napi::TypedArray info1TypedArray = info[1].As<Napi::TypedArray>();
    if (info1TypedArray.TypedArrayType() != napi_uint8_array) {
        Napi::TypeError::New(env, "Wrong array type").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    uint32_t friend_number = info[0].As<Napi::Number>().Uint32Value();
    Napi::Uint8Array data = info1TypedArray.As<Napi::Uint8Array>();
    size_t length = data.ByteLength();

    TOX_ERR_FRIEND_CUSTOM_PACKET error;
    bool returned = tox_friend_send_lossy_packet(tox, friend_number, (const uint8_t*)data.Data(), length, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Boolean::New(env, returned));

    return result;
}

Napi::Value ToxCore::toxFriendSendLosslessPacket(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber() || !info[1].IsTypedArray()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    Napi::TypedArray info1TypedArray = info[1].As<Napi::TypedArray>();
    if (info1TypedArray.TypedArrayType() != napi_uint8_array) {
        Napi::TypeError::New(env, "Wrong array type").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    uint32_t friend_number = info[0].As<Napi::Number>().Uint32Value();
    Napi::Uint8Array data = info1TypedArray.As<Napi::Uint8Array>();
    size_t length = data.ByteLength();

    TOX_ERR_FRIEND_CUSTOM_PACKET error;
    bool returned = tox_friend_send_lossless_packet(tox, friend_number, (const uint8_t*)data.Data(), length, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Boolean::New(env, returned));

    return result;
}

void ToxCore::toxCallbackFriendLossyPacket(const Napi::CallbackInfo& info)
{
    friendLossyPacketCallback = Napi::Reference<Napi::Function>::New(info[0].As<Napi::Function>());
}

void ToxCore::_friendLossyPacketChanged(Tox *tox, uint32_t friend_number, const uint8_t *data, size_t length, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->friendLossyPacketCallback.MakeCallback(toxCore->friendLossyPacketCallback.Env().Global(), { 
        Napi::Number::New(toxCore->friendLossyPacketCallback.Env(), friend_number),
        Napi::ArrayBuffer::New(toxCore->friendLossyPacketCallback.Env(), (void*)data, length)
    });
}

void ToxCore::toxCallbackFriendLosslessPacket(const Napi::CallbackInfo& info)
{
    friendLosslessPacketCallback = Napi::Reference<Napi::Function>::New(info[0].As<Napi::Function>());
}

void ToxCore::_friendLosslessPacketChanged(Tox *tox, uint32_t friend_number, const uint8_t *data, size_t length, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->friendLosslessPacketCallback.MakeCallback(toxCore->friendLosslessPacketCallback.Env().Global(), { 
        Napi::Number::New(toxCore->friendLosslessPacketCallback.Env(), friend_number),
        Napi::ArrayBuffer::New(toxCore->friendLosslessPacketCallback.Env(), (void*)data, length)
    });
}

/*
 * Low-level network information
 */

Napi::Value ToxCore::toxSelfGetDhtId(const Napi::CallbackInfo& info)
{
    uint8_t* dht_id = new uint8_t[TOX_PUBLIC_KEY_SIZE] { 0 };
    tox_self_get_dht_id(tox, dht_id);
    return Napi::ArrayBuffer::New(info.Env(), dht_id, TOX_PUBLIC_KEY_SIZE);
}

Napi::Value ToxCore::toxSelfGetUdpPort(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    TOX_ERR_GET_PORT error;
    uint16_t returned = tox_self_get_udp_port(tox, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Number::New(env, returned));

    return result;
}

Napi::Value ToxCore::toxSelfGetTcpPort(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    TOX_ERR_GET_PORT error;
    uint16_t returned = tox_self_get_tcp_port(tox, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Number::New(env, returned));

    return result;
}