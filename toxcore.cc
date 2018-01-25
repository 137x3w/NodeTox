
/*
 * https://github.com/w3x731/ToxNode
 */

#include "toxcore.h"

#include <tox/tox.h>

Napi::FunctionReference ToxCore::constructor;

Napi::Object ToxCore::Init(Napi::Env env, Napi::Object exports) {
    Napi::HandleScope scope(env);

    Napi::Function func = DefineClass(env, "ToxCore", {
        InstanceMethod("bindCallbacks", &ToxCore::bindCallbacks),

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
        InstanceMethod("toxCallbackConferenceNamelistChange", &ToxCore::toxCallbackConferenceNamelistChange),
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
    selfConnectionStatusAsyncWorker = 0;
    friendNameAsyncWorker = 0;
    friendStatusMessageAsyncWorker = 0;
    friendStatusAsyncWorker = 0;
    friendConnectionStatusAsyncWorker = 0;
    friendTypingAsyncWorker = 0;
    friendReadReceiptAsyncWorker = 0;
    friendRequestAsyncWorker = 0;
    friendMessageAsyncWorker = 0;
    fileRecvControlAsyncWorker = 0;
    fileChunkRequestAsyncWorker = 0;
    fileRecvAsyncWorker = 0;
    fileRecvChunkAsyncWorker = 0;
    conferenceInviteAsyncWorker = 0;
    conferenceMessageAsyncWorker = 0;
    conferenceTitleAsyncWorker = 0;
    conferenceNamelistChangeAsyncWorker = 0;
    friendLossyPacketAsyncWorker = 0;
    friendLosslessPacketAsyncWorker = 0;
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

void ToxCore::bindCallbacks(const Napi::CallbackInfo& info)
{
    // tox_callback_self_connection_status(tox, _selfConnectionStatusChanged);
    // tox_callback_friend_name(tox, _friendNameChanged);
    // tox_callback_friend_status_message(tox, _friendStatusMessageChanged);
    // tox_callback_friend_status(tox, _friendStatusChanged);
    // tox_callback_friend_connection_status(tox, _friendConnectionStatusChanged);
    // tox_callback_friend_typing(tox, _friendTypingChanged);
    // tox_callback_friend_read_receipt(tox, _friendReadReceiptChanged);
    // tox_callback_friend_request(tox, _friendRequestChanged);
    // tox_callback_friend_message(tox, _friendMessageChanged);
    // tox_callback_file_recv_control(tox, _fileRecvControlChanged);
    // tox_callback_file_chunk_request(tox, _fileChunkRequestChanged);
    // tox_callback_file_recv(tox, _fileRecvChanged);
    // tox_callback_file_recv_chunk(tox, _fileRecvChunkChanged);
    // tox_callback_conference_invite(tox, _conferenceInviteChanged);
    // tox_callback_conference_message(tox, _conferenceMessageChanged);
    // tox_callback_conference_title(tox, _conferenceTitleChanged);
    // tox_callback_conference_namelist_change(tox, _conferenceNamelistChangeChanged);
    // tox_callback_friend_lossy_packet(tox, _friendLossyPacketChanged);
    // tox_callback_friend_lossless_packet(tox, _friendLosslessPacketChanged);
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

    if (!info[0].IsArrayBuffer()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return;
    }

    size_t length = (size_t)info[0].As<Napi::ArrayBuffer>().ByteLength();
    tox_options_set_savedata_data(toxOptions, (uint8_t*)info[0].As<Napi::ArrayBuffer>().Data(), length);
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
    if(selfConnectionStatusAsyncWorker != 0) {
        delete selfConnectionStatusAsyncWorker;
    }
    selfConnectionStatusAsyncWorker = new SelfConnectionStatusAsyncWorker(info[0].As<Napi::Function>());
}

void ToxCore::_selfConnectionStatusChanged(Tox *tox, TOX_CONNECTION connection_status, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->selfConnectionStatusAsyncWorker->setModel(connection_status);
    toxCore->selfConnectionStatusAsyncWorker->Queue();
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
    return Napi::ArrayBuffer::New(info.Env(), friend_list, length);
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
    result.Set(Napi::String::New(env, "return"), Napi::ArrayBuffer::New(env, timestamp32_t, 2));

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
    if(friendNameAsyncWorker != 0) {
        delete friendNameAsyncWorker;
    }
    friendNameAsyncWorker = new FriendNameAsyncWorker(info[0].As<Napi::Function>());
}

void ToxCore::_friendNameChanged(Tox *tox, uint32_t friend_number, const uint8_t *name, size_t length, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->friendNameAsyncWorker->setModel(friend_number, name, length);
    toxCore->friendNameAsyncWorker->Queue();
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
    if(friendStatusMessageAsyncWorker != 0) {
        delete friendStatusMessageAsyncWorker;
    }
    friendStatusMessageAsyncWorker = new FriendStatusMessageAsyncWorker(info[0].As<Napi::Function>());
}

void ToxCore::_friendStatusMessageChanged(Tox *tox, uint32_t friend_number, const uint8_t *message, size_t length, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->friendStatusMessageAsyncWorker->setModel(friend_number, message, length);
    toxCore->friendStatusMessageAsyncWorker->Queue();
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
    if(friendStatusAsyncWorker != 0) {
        delete friendStatusAsyncWorker;
    }
    friendStatusAsyncWorker = new FriendStatusAsyncWorker(info[0].As<Napi::Function>());
}

void ToxCore::_friendStatusChanged(Tox *tox, uint32_t friend_number, TOX_USER_STATUS status, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->friendStatusAsyncWorker->setModel(friend_number, status);
    toxCore->friendStatusAsyncWorker->Queue();
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
    if(friendConnectionStatusAsyncWorker != 0) {
        delete friendConnectionStatusAsyncWorker;
    }
    friendConnectionStatusAsyncWorker = new FriendConnectionStatusAsyncWorker(info[0].As<Napi::Function>());
}

void ToxCore::_friendConnectionStatusChanged(Tox *tox, uint32_t friend_number, TOX_CONNECTION connection_status, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->friendConnectionStatusAsyncWorker->setModel(friend_number, connection_status);
    toxCore->friendConnectionStatusAsyncWorker->Queue();
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
    if(friendTypingAsyncWorker != 0) {
        delete friendTypingAsyncWorker;
    }
    friendTypingAsyncWorker = new FriendTypingAsyncWorker(info[0].As<Napi::Function>());
}

void ToxCore::_friendTypingChanged(Tox *tox, uint32_t friend_number, bool is_typing, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->friendTypingAsyncWorker->setModel(friend_number, is_typing);
    toxCore->friendTypingAsyncWorker->Queue();
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
    if(friendReadReceiptAsyncWorker != 0) {
        delete friendReadReceiptAsyncWorker;
    }
    friendReadReceiptAsyncWorker = new FriendReadReceiptAsyncWorker(info[0].As<Napi::Function>());
}

void ToxCore::_friendReadReceiptChanged(Tox *tox, uint32_t friend_number, uint32_t message_id, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->friendReadReceiptAsyncWorker->setModel(friend_number, message_id);
    toxCore->friendReadReceiptAsyncWorker->Queue();
}

void ToxCore::toxCallbackFriendRequest(const Napi::CallbackInfo& info)
{
    if(friendRequestAsyncWorker != 0) {
        delete friendRequestAsyncWorker;
    }
    friendRequestAsyncWorker = new FriendRequestAsyncWorker(info[0].As<Napi::Function>());
}

void ToxCore::_friendRequestChanged(Tox *tox, const uint8_t *public_key, const uint8_t *message, size_t length, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->friendRequestAsyncWorker->setModel(public_key, message, length);
    toxCore->friendRequestAsyncWorker->Queue();
}

void ToxCore::toxCallbackFriendMessage(const Napi::CallbackInfo& info)
{
    if(friendMessageAsyncWorker != 0) {
        delete friendMessageAsyncWorker;
    }
    friendMessageAsyncWorker = new FriendMessageAsyncWorker(info[0].As<Napi::Function>());
}

void ToxCore::_friendMessageChanged(Tox *tox, uint32_t friend_number, TOX_MESSAGE_TYPE type, const uint8_t *message, size_t length, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->friendMessageAsyncWorker->setModel(friend_number, type, message, length);
    toxCore->friendMessageAsyncWorker->Queue();
}

Napi::Value ToxCore::toxHash(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsArrayBuffer()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    uint8_t* hash = new uint8_t[TOX_HASH_LENGTH] { 0 };
    
    bool returned = tox_hash(hash, (const uint8_t*)info[0].As<Napi::ArrayBuffer>().Data(), (size_t)info[0].As<Napi::ArrayBuffer>().ByteLength());
    
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
    if(fileRecvControlAsyncWorker != 0) {
        delete fileRecvControlAsyncWorker;
    }
    fileRecvControlAsyncWorker = new FileRecvControlAsyncWorker(info[0].As<Napi::Function>());
}

void ToxCore::_fileRecvControlChanged(Tox *tox, uint32_t friend_number, uint32_t file_number, TOX_FILE_CONTROL control, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->fileRecvControlAsyncWorker->setModel(friend_number, file_number, control);
    toxCore->fileRecvControlAsyncWorker->Queue();
}

Napi::Value ToxCore::toxFileSeek(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber() || !info[1].IsNumber() || !info[2].IsArrayBuffer()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t friend_number = info[0].As<Napi::Number>().Uint32Value();
    uint32_t file_number = info[1].As<Napi::Number>().Uint32Value();
    uint64_t position = 0;
    convertFromUint32_t2Uint64_t((uint32_t*)info[2].As<Napi::ArrayBuffer>().Data(), &position);

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

    if (!info[0].IsNumber() || !info[1].IsNumber() || !info[2].IsArrayBuffer() || !info[3].IsArrayBuffer() || !info[4].IsString()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t friend_number = info[0].As<Napi::Number>().Uint32Value();
    uint32_t kind = info[1].As<Napi::Number>().Uint32Value();
    uint64_t file_size = 0;
    convertFromUint32_t2Uint64_t((uint32_t*)info[2].As<Napi::ArrayBuffer>().Data(), &file_size);
    size_t filename_length = info[4].As<Napi::String>().Utf8Value().length();

    TOX_ERR_FILE_SEND error;
    uint32_t returned = tox_file_send(tox, friend_number, kind, file_size, (const uint8_t*)info[3].As<Napi::ArrayBuffer>().Data(), (const uint8_t *)info[4].As<Napi::String>().Utf8Value().c_str(), filename_length, &error);

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

    if (!info[0].IsNumber() || !info[1].IsNumber() || !info[2].IsArrayBuffer() || !info[3].IsArrayBuffer()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t friend_number = info[0].As<Napi::Number>().Uint32Value();
    uint32_t file_number = info[1].As<Napi::Number>().Uint32Value();
    uint64_t position = 0;
    convertFromUint32_t2Uint64_t((uint32_t*)info[2].As<Napi::ArrayBuffer>().Data(), &position);
    size_t length = (size_t)info[3].As<Napi::ArrayBuffer>().ByteLength();

    TOX_ERR_FILE_SEND_CHUNK error;
    bool returned = tox_file_send_chunk(tox, friend_number, file_number, position, (const uint8_t*)info[3].As<Napi::ArrayBuffer>().Data(), length, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Number::New(env, returned));

    return result;
}

void ToxCore::toxCallbackFileChunkRequest(const Napi::CallbackInfo& info)
{
    if(fileChunkRequestAsyncWorker != 0) {
        delete fileChunkRequestAsyncWorker;
    }
    fileChunkRequestAsyncWorker = new FileChunkRequestAsyncWorker(info[0].As<Napi::Function>());
}

void ToxCore::_fileChunkRequestChanged(Tox *tox, uint32_t friend_number, uint32_t file_number, uint64_t position, size_t length, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->fileChunkRequestAsyncWorker->setModel(friend_number, file_number, position, length);
    toxCore->fileChunkRequestAsyncWorker->Queue();
}

/*
 * File transmission: receiving
 */

void ToxCore::toxCallbackFileRecv(const Napi::CallbackInfo& info)
{
    if(fileRecvAsyncWorker != 0) {
        delete fileRecvAsyncWorker;
    }
    fileRecvAsyncWorker = new FileRecvAsyncWorker(info[0].As<Napi::Function>());
}

void ToxCore::_fileRecvChanged(Tox *tox, uint32_t friend_number, uint32_t file_number, uint32_t kind, uint64_t file_size, const uint8_t *filename, size_t filename_length, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->fileRecvAsyncWorker->setModel(friend_number, file_number, kind, file_size, filename, filename_length);
    toxCore->fileRecvAsyncWorker->Queue();
}

void ToxCore::toxCallbackFileRecvChunk(const Napi::CallbackInfo& info)
{
    if(fileRecvChunkAsyncWorker != 0) {
        delete fileRecvChunkAsyncWorker;
    }
    fileRecvChunkAsyncWorker = new FileRecvChunkAsyncWorker(info[0].As<Napi::Function>());
}

void ToxCore::_fileRecvChunkChanged(Tox *tox, uint32_t friend_number, uint32_t file_number, uint64_t position, const uint8_t *data, size_t length, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->fileRecvChunkAsyncWorker->setModel(friend_number, file_number, position, data, length);
    toxCore->fileRecvChunkAsyncWorker->Queue();
}

/*
 * Conference management
 */

void ToxCore::toxCallbackConferenceInvite(const Napi::CallbackInfo& info)
{
    if(conferenceInviteAsyncWorker != 0) {
        delete conferenceInviteAsyncWorker;
    }
    conferenceInviteAsyncWorker = new ConferenceInviteAsyncWorker(info[0].As<Napi::Function>());
}

void ToxCore::_conferenceInviteChanged(Tox *tox, uint32_t friend_number, TOX_CONFERENCE_TYPE type, const uint8_t *cookie, size_t length, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->conferenceInviteAsyncWorker->setModel(friend_number, type, cookie, length);
    toxCore->conferenceInviteAsyncWorker->Queue();
}

void ToxCore::toxCallbackConferenceMessage(const Napi::CallbackInfo& info)
{
    if(conferenceMessageAsyncWorker != 0) {
        delete conferenceMessageAsyncWorker;
    }
    conferenceMessageAsyncWorker = new ConferenceMessageAsyncWorker(info[0].As<Napi::Function>());
}

void ToxCore::_conferenceMessageChanged(Tox *tox, uint32_t conference_number, uint32_t peer_number, TOX_MESSAGE_TYPE type, const uint8_t *message, size_t length, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->conferenceMessageAsyncWorker->setModel(conference_number, peer_number, type, message, length);
    toxCore->conferenceMessageAsyncWorker->Queue();
}

void ToxCore::toxCallbackConferenceTitle(const Napi::CallbackInfo& info)
{
    if(conferenceTitleAsyncWorker != 0) {
        delete conferenceTitleAsyncWorker;
    }
    conferenceTitleAsyncWorker = new ConferenceTitleAsyncWorker(info[0].As<Napi::Function>());
}

void ToxCore::_conferenceTitleChanged(Tox *tox, uint32_t conference_number, uint32_t peer_number, const uint8_t *title, size_t length, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->conferenceTitleAsyncWorker->setModel(conference_number, peer_number, title, length);
    toxCore->conferenceTitleAsyncWorker->Queue();
}

void ToxCore::toxCallbackConferenceNamelistChange(const Napi::CallbackInfo& info)
{
    if(conferenceNamelistChangeAsyncWorker != 0) {
        delete conferenceNamelistChangeAsyncWorker;
    }
    conferenceNamelistChangeAsyncWorker = new ConferenceNamelistChangeAsyncWorker(info[0].As<Napi::Function>());
}

void ToxCore::_conferenceNamelistChangeChanged(Tox *tox, uint32_t conference_number, uint32_t peer_number, TOX_CONFERENCE_STATE_CHANGE change, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->conferenceNamelistChangeAsyncWorker->setModel(conference_number, peer_number, change);
    toxCore->conferenceNamelistChangeAsyncWorker->Queue();
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
    uint8_t* name = new uint8_t[TOX_MAX_NAME_LENGTH] { 0 };

    TOX_ERR_CONFERENCE_PEER_QUERY error;
    bool returned = tox_conference_peer_get_name(tox, conference_number, peer_number, name, &error);
    
    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Boolean::New(env, returned));
    result.Set(Napi::String::New(env, "result"), Napi::String::New(env, (const char*)name, TOX_MAX_NAME_LENGTH));

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

    if (!info[0].IsNumber() || !info[1].IsArrayBuffer()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint32_t friend_number = info[0].As<Napi::Number>().Uint32Value();
    size_t length = (size_t)info[1].As<Napi::ArrayBuffer>().ByteLength();

    TOX_ERR_CONFERENCE_JOIN error;
    uint32_t returned = tox_conference_join(tox, friend_number, (uint8_t*)info[1].As<Napi::ArrayBuffer>().Data(), length, &error);

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
    size_t size = info[1].As<Napi::Number>().Uint32Value();
    uint8_t* title = new uint8_t[size] { 0 };

    TOX_ERR_CONFERENCE_TITLE error;
    bool returned = tox_conference_get_title(tox, conference_number, title, &error);
    
    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Boolean::New(env, returned));
    result.Set(Napi::String::New(env, "result"), Napi::ArrayBuffer::New(env, title, size));

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
    return Napi::ArrayBuffer::New(env, chatlist, size);
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

    if (!info[0].IsNumber() || !info[1].IsArrayBuffer()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    uint32_t friend_number = info[0].As<Napi::Number>().Uint32Value();
    size_t length = info[1].As<Napi::ArrayBuffer>().ByteLength();

    TOX_ERR_FRIEND_CUSTOM_PACKET error;
    bool returned = tox_friend_send_lossy_packet(tox, friend_number, (const uint8_t*)info[1].As<Napi::ArrayBuffer>().Data(), length, &error);

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

    if (!info[0].IsNumber() || !info[1].IsArrayBuffer()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    uint32_t friend_number = info[0].As<Napi::Number>().Uint32Value();
    size_t length = info[1].As<Napi::ArrayBuffer>().ByteLength();

    TOX_ERR_FRIEND_CUSTOM_PACKET error;
    bool returned = tox_friend_send_lossless_packet(tox, friend_number, (const uint8_t*)info[1].As<Napi::ArrayBuffer>().Data(), length, &error);

    Napi::Object result = Napi::Object::New(env);

    result.Set(Napi::String::New(env, "error"), Napi::Number::New(env, error));
    result.Set(Napi::String::New(env, "return"), Napi::Boolean::New(env, returned));

    return result;
}

void ToxCore::toxCallbackFriendLossyPacket(const Napi::CallbackInfo& info)
{
    if(friendLossyPacketAsyncWorker != 0) {
        delete friendLossyPacketAsyncWorker;
    }
    friendLossyPacketAsyncWorker = new FriendLossyPacketAsyncWorker(info[0].As<Napi::Function>());
}

void ToxCore::_friendLossyPacketChanged(Tox *tox, uint32_t friend_number, const uint8_t *data, size_t length, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->friendLossyPacketAsyncWorker->setModel(friend_number, data, length);
    toxCore->friendLossyPacketAsyncWorker->Queue();
}

void ToxCore::toxCallbackFriendLosslessPacket(const Napi::CallbackInfo& info)
{
    if(friendLosslessPacketAsyncWorker != 0) {
        delete friendLosslessPacketAsyncWorker;
    }
    friendLosslessPacketAsyncWorker = new FriendLosslessPacketAsyncWorker(info[0].As<Napi::Function>());
}

void ToxCore::_friendLosslessPacketChanged(Tox *tox, uint32_t friend_number, const uint8_t *data, size_t length, void *user_data)
{
    ToxCore* toxCore = (ToxCore*)user_data;
    toxCore->friendLosslessPacketAsyncWorker->setModel(friend_number, data, length);
    toxCore->friendLosslessPacketAsyncWorker->Queue();
}

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

/*
 * Additional callback services
 */

SelfConnectionStatusAsyncWorker::SelfConnectionStatusAsyncWorker(const Napi::Function& callback) : Napi::AsyncWorker(callback) {}

void SelfConnectionStatusAsyncWorker::Execute() {}

void SelfConnectionStatusAsyncWorker::OnOK()
{
    Napi::Env env = Env();
    Callback().MakeCallback(Receiver().Value(), {
        Napi::Number::New(env, connection_status)
    });
}

void SelfConnectionStatusAsyncWorker::OnError(const Napi::Error& e) {}

void SelfConnectionStatusAsyncWorker::setModel(TOX_CONNECTION connection_status)
{
    this->connection_status = connection_status;
}

FriendNameAsyncWorker::FriendNameAsyncWorker(const Napi::Function& callback) : Napi::AsyncWorker(callback) {}

void FriendNameAsyncWorker::Execute() {}

void FriendNameAsyncWorker::OnOK()
{
    Napi::Env env = Env();
    Callback().MakeCallback(Receiver().Value(), { 
        Napi::Number::New(env, friend_number), 
        Napi::String::New(env, (const char*)name, length)
    });
}

void FriendNameAsyncWorker::OnError(const Napi::Error& e) {}

void FriendNameAsyncWorker::setModel(uint32_t friend_number, const uint8_t *name, size_t length)
{
    this->friend_number = friend_number;
    this->name = name;
    this->length = length;
}

FriendStatusMessageAsyncWorker::FriendStatusMessageAsyncWorker(const Napi::Function& callback) : Napi::AsyncWorker(callback) {}

void FriendStatusMessageAsyncWorker::Execute() {}

void FriendStatusMessageAsyncWorker::OnOK()
{
    Napi::Env env = Env();
    Callback().MakeCallback(Receiver().Value(), { 
        Napi::Number::New(env, friend_number), 
        Napi::String::New(env, (const char*)message, length)
    });
}

void FriendStatusMessageAsyncWorker::OnError(const Napi::Error& e) {}

void FriendStatusMessageAsyncWorker::setModel(uint32_t friend_number, const uint8_t *name, size_t length)
{
    this->friend_number = friend_number;
    this->message = message;
    this->length = length;
}

FriendStatusAsyncWorker::FriendStatusAsyncWorker(const Napi::Function& callback) : Napi::AsyncWorker(callback) {}

void FriendStatusAsyncWorker::Execute() {}

void FriendStatusAsyncWorker::OnOK()
{
    Napi::Env env = Env();
    Callback().MakeCallback(Receiver().Value(), { 
        Napi::Number::New(env, friend_number), 
        Napi::Number::New(env, status) 
    });
}

void FriendStatusAsyncWorker::OnError(const Napi::Error& e) {}

void FriendStatusAsyncWorker::setModel(uint32_t friend_number, TOX_USER_STATUS status)
{
    this->friend_number = friend_number;
    this->status = status;
}

FriendConnectionStatusAsyncWorker::FriendConnectionStatusAsyncWorker(const Napi::Function& callback) : Napi::AsyncWorker(callback) {}

void FriendConnectionStatusAsyncWorker::Execute() {}

void FriendConnectionStatusAsyncWorker::OnOK()
{
    Napi::Env env = Env();
    Callback().MakeCallback(Receiver().Value(), { 
        Napi::Number::New(env, friend_number), 
        Napi::Number::New(env, connection_status) 
    });
}

void FriendConnectionStatusAsyncWorker::OnError(const Napi::Error& e) {}

void FriendConnectionStatusAsyncWorker::setModel(uint32_t friend_number, TOX_CONNECTION connection_status)
{
    this->friend_number = friend_number;
    this->connection_status = connection_status;
}

FriendTypingAsyncWorker::FriendTypingAsyncWorker(const Napi::Function& callback) : Napi::AsyncWorker(callback) {}

void FriendTypingAsyncWorker::Execute() {}

void FriendTypingAsyncWorker::OnOK()
{
    Napi::Env env = Env();
    Callback().MakeCallback(Receiver().Value(), { 
        Napi::Number::New(env, friend_number), 
        Napi::Boolean::New(env, is_typing) 
    });
}

void FriendTypingAsyncWorker::OnError(const Napi::Error& e) {}

void FriendTypingAsyncWorker::setModel(uint32_t friend_number, bool is_typing)
{
    this->friend_number = friend_number;
    this->is_typing = is_typing;
}

FriendReadReceiptAsyncWorker::FriendReadReceiptAsyncWorker(const Napi::Function& callback) : Napi::AsyncWorker(callback) {}

void FriendReadReceiptAsyncWorker::Execute() {}

void FriendReadReceiptAsyncWorker::OnOK()
{
    Napi::Env env = Env();
    Callback().MakeCallback(Receiver().Value(), { Napi::Number::New(env, friend_number), Napi::Number::New(env, message_id) });
}

void FriendReadReceiptAsyncWorker::OnError(const Napi::Error& e) {}

void FriendReadReceiptAsyncWorker::setModel(uint32_t friend_number, uint32_t message_id)
{
    this->friend_number = friend_number;
    this->message_id = message_id;
}

FriendRequestAsyncWorker::FriendRequestAsyncWorker(const Napi::Function& callback) : Napi::AsyncWorker(callback) {}

void FriendRequestAsyncWorker::Execute() {}

void FriendRequestAsyncWorker::OnOK()
{
    Napi::Env env = Env();
    Callback().MakeCallback(Receiver().Value(), { 
        Napi::ArrayBuffer::New(env, (void*)public_key, TOX_PUBLIC_KEY_SIZE),
        Napi::String::New(env, (const char*)message, length) 
    });
}

void FriendRequestAsyncWorker::OnError(const Napi::Error& e) {}

void FriendRequestAsyncWorker::setModel(const uint8_t *public_key, const uint8_t *message, size_t length)
{
    this->public_key = public_key;
    this->message = message;
    this->length = length;
}

FriendMessageAsyncWorker::FriendMessageAsyncWorker(const Napi::Function& callback) : Napi::AsyncWorker(callback) {}

void FriendMessageAsyncWorker::Execute() {}

void FriendMessageAsyncWorker::OnOK()
{
    Napi::Env env = Env();
    Callback().MakeCallback(Receiver().Value(), { 
        Napi::Number::New(env, friend_number), 
        Napi::Number::New(env, type), 
        Napi::String::New(env, (const char*)message, length) 
    });
}

void FriendMessageAsyncWorker::OnError(const Napi::Error& e) {}

void FriendMessageAsyncWorker::setModel(uint32_t friend_number, TOX_MESSAGE_TYPE type, const uint8_t *message, size_t length)
{
    this->friend_number = friend_number;
    this->type = type;
    this->message = message;
    this->length = length;
}

FileRecvControlAsyncWorker::FileRecvControlAsyncWorker(const Napi::Function& callback) : Napi::AsyncWorker(callback) {}

void FileRecvControlAsyncWorker::Execute() {}

void FileRecvControlAsyncWorker::OnOK()
{
    Napi::Env env = Env();
    Callback().MakeCallback(Receiver().Value(), { 
        Napi::Number::New(env, friend_number), 
        Napi::Number::New(env, file_number), 
        Napi::Number::New(env, control) 
    });
}

void FileRecvControlAsyncWorker::OnError(const Napi::Error& e) {}

void FileRecvControlAsyncWorker::setModel(uint32_t friend_number, uint32_t file_number, TOX_FILE_CONTROL control)
{
    this->friend_number = friend_number;
    this->file_number = file_number;
    this->control = control;
}

FileChunkRequestAsyncWorker::FileChunkRequestAsyncWorker(const Napi::Function& callback) : Napi::AsyncWorker(callback) {}

void FileChunkRequestAsyncWorker::Execute() {}

void FileChunkRequestAsyncWorker::OnOK()
{
    Napi::Env env = Env();
    uint32_t* position32 = new uint32_t[2] { 0 };
    ToxCore::convertFromUint64_t2Uint32_t(&position64, position32);
    Callback().MakeCallback(Receiver().Value(), { 
        Napi::Number::New(env, friend_number), 
        Napi::Number::New(env, file_number), 
        Napi::ArrayBuffer::New(env, position32, 8), 
        Napi::Number::New(env, length) 
    });
}

void FileChunkRequestAsyncWorker::OnError(const Napi::Error& e) {}

void FileChunkRequestAsyncWorker::setModel(uint32_t friend_number, uint32_t file_number, uint64_t position, size_t length)
{
    this->friend_number = friend_number;
    this->file_number = file_number;
    this->position64 = position;
    this->length = length;
}

FileRecvAsyncWorker::FileRecvAsyncWorker(const Napi::Function& callback) : Napi::AsyncWorker(callback) {}

void FileRecvAsyncWorker::Execute() {}

void FileRecvAsyncWorker::OnOK()
{
    Napi::Env env = Env();
    uint32_t* file_size32 = new uint32_t[2] { 0 };
    ToxCore::convertFromUint64_t2Uint32_t(&file_size64, file_size32);
    Callback().MakeCallback(Receiver().Value(), { 
        Napi::Number::New(env, friend_number), 
        Napi::Number::New(env, file_number),
        Napi::Number::New(env, kind), 
        Napi::ArrayBuffer::New(env, file_size32, 8),
        Napi::String::New(env, (const char*)filename, filename_length) 
    });
}

void FileRecvAsyncWorker::OnError(const Napi::Error& e) {}

void FileRecvAsyncWorker::setModel(uint32_t friend_number, uint32_t file_number, uint32_t kind, uint64_t file_size, const uint8_t *filename, size_t filename_length)
{
    this->friend_number = friend_number;
    this->file_number = file_number;
    this->kind = kind;
    this->file_size64 = file_size;
    this->filename = filename;
    this->filename_length = filename_length;
}

FileRecvChunkAsyncWorker::FileRecvChunkAsyncWorker(const Napi::Function& callback) : Napi::AsyncWorker(callback) {}

void FileRecvChunkAsyncWorker::Execute() {}

void FileRecvChunkAsyncWorker::OnOK()
{
    Napi::Env env = Env();
    uint32_t* position32 = new uint32_t[2] { 0 };
    ToxCore::convertFromUint64_t2Uint32_t(&position64, position32);
    Callback().MakeCallback(Receiver().Value(), { 
        Napi::Number::New(env, friend_number), 
        Napi::Number::New(env, file_number),
        Napi::ArrayBuffer::New(env, position32, 8),
        Napi::ArrayBuffer::New(env, (void*)data, length)
    });
}

void FileRecvChunkAsyncWorker::OnError(const Napi::Error& e) {}

void FileRecvChunkAsyncWorker::setModel(uint32_t friend_number, uint32_t file_number, uint64_t position, const uint8_t *data, size_t length)
{
    this->friend_number = friend_number;
    this->file_number = file_number;
    this->position64 = position;
    this->data = data;
    this->length = length;
}

ConferenceInviteAsyncWorker::ConferenceInviteAsyncWorker(const Napi::Function& callback) : Napi::AsyncWorker(callback) {}

void ConferenceInviteAsyncWorker::Execute() {}

void ConferenceInviteAsyncWorker::OnOK()
{
    Napi::Env env = Env();
    Callback().MakeCallback(Receiver().Value(), { 
        Napi::Number::New(env, friend_number), 
        Napi::Number::New(env, type),
        Napi::ArrayBuffer::New(env, (void*)cookie, length)
    });
}

void ConferenceInviteAsyncWorker::OnError(const Napi::Error& e) {}

void ConferenceInviteAsyncWorker::setModel(uint32_t friend_number, TOX_CONFERENCE_TYPE type, const uint8_t *cookie, size_t length)
{
    this->friend_number = friend_number;
    this->type = type;
    this->cookie = cookie;
    this->length = length;
}

ConferenceMessageAsyncWorker::ConferenceMessageAsyncWorker(const Napi::Function& callback) : Napi::AsyncWorker(callback) {}

void ConferenceMessageAsyncWorker::Execute() {}

void ConferenceMessageAsyncWorker::OnOK()
{
    Napi::Env env = Env();
    Callback().MakeCallback(Receiver().Value(), { 
        Napi::Number::New(env, conference_number),
        Napi::Number::New(env, peer_number), 
        Napi::Number::New(env, type),
        Napi::String::New(env, (const char*)message, length)
    });
}

void ConferenceMessageAsyncWorker::OnError(const Napi::Error& e) {}

void ConferenceMessageAsyncWorker::setModel(uint32_t conference_number, uint32_t peer_number, TOX_MESSAGE_TYPE type, const uint8_t *message, size_t length)
{
    this->conference_number = conference_number;
    this->peer_number = peer_number;
    this->type = type;
    this->message = message;
    this->length = length;
}

ConferenceTitleAsyncWorker::ConferenceTitleAsyncWorker(const Napi::Function& callback) : Napi::AsyncWorker(callback) {}

void ConferenceTitleAsyncWorker::Execute() {}

void ConferenceTitleAsyncWorker::OnOK()
{
    Napi::Env env = Env();
    Callback().MakeCallback(Receiver().Value(), { 
        Napi::Number::New(env, conference_number),
        Napi::Number::New(env, peer_number), 
        Napi::String::New(env, (const char*)title, length)
    });
}

void ConferenceTitleAsyncWorker::OnError(const Napi::Error& e) {}

void ConferenceTitleAsyncWorker::setModel(uint32_t conference_number, uint32_t peer_number, const uint8_t *title, size_t length)
{
    this->conference_number = conference_number;
    this->peer_number = peer_number;
    this->title = title;
    this->length = length;
}

ConferenceNamelistChangeAsyncWorker::ConferenceNamelistChangeAsyncWorker(const Napi::Function& callback) : Napi::AsyncWorker(callback) {}

void ConferenceNamelistChangeAsyncWorker::Execute() {}

void ConferenceNamelistChangeAsyncWorker::OnOK()
{
    Napi::Env env = Env();
    Callback().MakeCallback(Receiver().Value(), { 
        Napi::Number::New(env, conference_number),
        Napi::Number::New(env, peer_number), 
        Napi::Number::New(env, change)
    });
}

void ConferenceNamelistChangeAsyncWorker::OnError(const Napi::Error& e) {}

void ConferenceNamelistChangeAsyncWorker::setModel(uint32_t conference_number, uint32_t peer_number, TOX_CONFERENCE_STATE_CHANGE change)
{
    this->conference_number = conference_number;
    this->peer_number = peer_number;
    this->change = change;
}

FriendLossyPacketAsyncWorker::FriendLossyPacketAsyncWorker(const Napi::Function& callback) : Napi::AsyncWorker(callback) {}

void FriendLossyPacketAsyncWorker::Execute() {}

void FriendLossyPacketAsyncWorker::OnOK()
{
    Napi::Env env = Env();
    Callback().MakeCallback(Receiver().Value(), { 
        Napi::Number::New(env, friend_number),
        Napi::ArrayBuffer::New(env, (void*)data, length)
    });
}

void FriendLossyPacketAsyncWorker::OnError(const Napi::Error& e) {}

void FriendLossyPacketAsyncWorker::setModel(uint32_t friend_number, const uint8_t *data, size_t length)
{
    this->friend_number = friend_number;
    this->data = data;
    this->length = length;
}

FriendLosslessPacketAsyncWorker::FriendLosslessPacketAsyncWorker(const Napi::Function& callback) : Napi::AsyncWorker(callback) {}

void FriendLosslessPacketAsyncWorker::Execute() {}

void FriendLosslessPacketAsyncWorker::OnOK()
{
    Napi::Env env = Env();
    Callback().MakeCallback(Receiver().Value(), { 
        Napi::Number::New(env, friend_number),
        Napi::ArrayBuffer::New(env, (void*)data, length)
    });
}

void FriendLosslessPacketAsyncWorker::OnError(const Napi::Error& e) {}

void FriendLosslessPacketAsyncWorker::setModel(uint32_t friend_number, const uint8_t *data, size_t length)
{
    this->friend_number = friend_number;
    this->data = data;
    this->length = length;
}