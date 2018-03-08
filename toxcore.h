
/*
 * https://github.com/w3x731/NodeTox
 */

#ifndef TOXCORE_H
#define TOXCORE_H

#include <napi.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <tox/tox.h>

#ifdef __cplusplus
}
#endif

class ToxCore;

class ToxCore : public Napi::ObjectWrap<ToxCore>
{
public:
    ToxCore(const Napi::CallbackInfo& info);
    static Napi::Object Init(Napi::Env env, Napi::Object exports);

    static void convertFromChar2Uint8t(const char* source, uint8_t* result, size_t length);
    static void convertFromUint64_t2Uint32_t(const uint64_t* source, uint32_t* result);
    static void convertFromUint32_t2Uint64_t(const uint32_t* source, uint64_t* result);
private:
    static Napi::FunctionReference constructor;

    /*  
     * Additional functions
     */
    void updateToxCallbackSelfConnectionStatus(const Napi::CallbackInfo& info);
    void updateToxCallbackFriendName(const Napi::CallbackInfo& info);
    void updateToxCallbackFriendStatusMessage(const Napi::CallbackInfo& info);
    void updateToxCallbackFriendStatus(const Napi::CallbackInfo& info);
    void updateToxCallbackFriendConnectionStatus(const Napi::CallbackInfo& info);
    void updateToxCallbackFriendTyping(const Napi::CallbackInfo& info);
    void updateToxCallbackFriendReadReceipt(const Napi::CallbackInfo& info);
    void updateToxCallbackFriendRequest(const Napi::CallbackInfo& info);
    void updateToxCallbackFriendMessage(const Napi::CallbackInfo& info);
    void updateToxCallbackFileRecvControl(const Napi::CallbackInfo& info);
    void updateToxCallbackFileChunkRequest(const Napi::CallbackInfo& info);
    void updateToxCallbackFileRecv(const Napi::CallbackInfo& info);
    void updateToxCallbackFileRecvChunk(const Napi::CallbackInfo& info);
    void updateToxCallbackConferenceInvite(const Napi::CallbackInfo& info);
    void updateToxCallbackConferenceMessage(const Napi::CallbackInfo& info);
    void updateToxCallbackConferenceTitle(const Napi::CallbackInfo& info);    
    void updateToxCallbackConferencePeerName(const Napi::CallbackInfo& info);
    void updateToxCallbackConferencePeerListChanged(const Napi::CallbackInfo& info);
    void updateToxCallbackFriendLossyPacket(const Napi::CallbackInfo& info);
    void updateToxCallbackFriendLosslessPacket(const Napi::CallbackInfo& info);
    /* 
     * API version
     */
    Napi::Value toxVersionMajor(const Napi::CallbackInfo& info);
    Napi::Value toxVersionMinor(const Napi::CallbackInfo& info);
    Napi::Value toxVersionPatch(const Napi::CallbackInfo& info);
    Napi::Value toxVersionIsCompatible(const Napi::CallbackInfo& info);
    /*
     * Numeric constants
     */
    Napi::Value toxPublicKeySize(const Napi::CallbackInfo& info);
    Napi::Value toxSecretKeySize(const Napi::CallbackInfo& info);
    Napi::Value toxNospamSize(const Napi::CallbackInfo& info);
    Napi::Value toxAddressSize(const Napi::CallbackInfo& info);
    Napi::Value toxMaxNameLength(const Napi::CallbackInfo& info);
    Napi::Value toxMaxStatusMessageLength(const Napi::CallbackInfo& info);
    Napi::Value toxMaxFriendRequestLength(const Napi::CallbackInfo& info);
    Napi::Value toxMaxMessageLength(const Napi::CallbackInfo& info);
    Napi::Value toxMaxCustomPacketSize(const Napi::CallbackInfo& info);
    Napi::Value toxHashLength(const Napi::CallbackInfo& info);
    Napi::Value toxFileIdLength(const Napi::CallbackInfo& info);
    Napi::Value toxMaxFilenameLength(const Napi::CallbackInfo& info);
    /*
     * Startup options
     */
    Napi::Value toxOptionsGetIpv6Enabled(const Napi::CallbackInfo& info);
    void toxOptionsSetIpv6Enabled(const Napi::CallbackInfo& info);
    Napi::Value toxOptionsGetUdpEnabled(const Napi::CallbackInfo& info);
    void toxOptionsSetUdpEnabled(const Napi::CallbackInfo& info);
    Napi::Value toxOptionsGetLocalDiscoveryEnabled(const Napi::CallbackInfo& info);
    void toxOptionsSetLocalDiscoveryEnabled(const Napi::CallbackInfo& info);
    Napi::Value toxOptionsGetProxyType(const Napi::CallbackInfo& info);
    void toxOptionsSetProxyType(const Napi::CallbackInfo& info);
    Napi::Value toxOptionsGetProxyHost(const Napi::CallbackInfo& info);
    void toxOptionsSetProxyHost(const Napi::CallbackInfo& info);
    Napi::Value toxOptionsGetProxyPort(const Napi::CallbackInfo& info);
    void toxOptionsSetProxyPort(const Napi::CallbackInfo& info);
    Napi::Value toxOptionsGetStartPort(const Napi::CallbackInfo& info);
    void toxOptionsSetStartPort(const Napi::CallbackInfo& info);
    Napi::Value toxOptionsGetEndPort(const Napi::CallbackInfo& info);
    void toxOptionsSetEndPort(const Napi::CallbackInfo& info);
    Napi::Value toxOptionsGetTcpPort(const Napi::CallbackInfo& info);
    void toxOptionsSetTcpPort(const Napi::CallbackInfo& info);
    Napi::Value toxOptionsGetHolePunchingEnabled(const Napi::CallbackInfo& info);
    void toxOptionsSetHolePunchingEnabled(const Napi::CallbackInfo& info);
    Napi::Value toxOptionsGetSavedataType(const Napi::CallbackInfo& info);
    void toxOptionsSetSavedataType(const Napi::CallbackInfo& info);
    Napi::Value toxOptionsGetSavedataData(const Napi::CallbackInfo& info);
    void toxOptionsSetSavedataData(const Napi::CallbackInfo& info);
    Napi::Value toxOptionsGetSavedataLength(const Napi::CallbackInfo& info);
    void toxOptionsSetSavedataLength(const Napi::CallbackInfo& info);
    // toxOptionsGetLogCallback(const Napi::CallbackInfo& info);
    // toxOptionsSetLogCallback(const Napi::CallbackInfo& info);
    // toxOptionsGetLogUserData(const Napi::CallbackInfo& info);
    // toxOptionsSetLogUserData(const Napi::CallbackInfo& info);
    void toxOptionsDefault(const Napi::CallbackInfo& info);
    Napi::Value toxOptionsNew(const Napi::CallbackInfo& info);
    void toxOptionsFree(const Napi::CallbackInfo& info);
    /*
     * Creation and destruction
     */
    Napi::Value toxNew(const Napi::CallbackInfo& info);
    void toxKill(const Napi::CallbackInfo& info);
    Napi::Value toxGetSavedataSize(const Napi::CallbackInfo& info);
    Napi::Value toxGetSavedata(const Napi::CallbackInfo& info);
    /*
     * Connection lifecycle and event loop
     */
    Napi::Value toxBootstrap(const Napi::CallbackInfo& info);
    Napi::Value toxAddTcpRelay(const Napi::CallbackInfo& info);
    void toxCallbackSelfConnectionStatus(const Napi::CallbackInfo& info);
    static void _selfConnectionStatusChanged(Tox *tox, TOX_CONNECTION connection_status, void *user_data);
    Napi::Value toxSelfGetConnectionStatus(const Napi::CallbackInfo& info);
    Napi::Value toxIterationInterval(const Napi::CallbackInfo& info);
    void toxIterate(const Napi::CallbackInfo& info);
    /*
     * Internal client information (Tox address/id)
     */
    Napi::Value toxSelfGetAddress(const Napi::CallbackInfo& info);
    void toxSelfSetNospam(const Napi::CallbackInfo& info);
    Napi::Value toxSelfGetNospam(const Napi::CallbackInfo& info);
    Napi::Value toxSelfGetPublicKey(const Napi::CallbackInfo& info);
    Napi::Value toxSelfGetSecretKey(const Napi::CallbackInfo& info);
    /*
     * User-visible client information (nickname/status)
     */
    Napi::Value toxSelfSetName(const Napi::CallbackInfo& info);
    Napi::Value toxSelfGetNameSize(const Napi::CallbackInfo& info);
    Napi::Value toxSelfGetName(const Napi::CallbackInfo& info);
    Napi::Value toxSelfSetStatusMessage(const Napi::CallbackInfo& info);
    Napi::Value toxSelfGetStatusMessageSize(const Napi::CallbackInfo& info);
    Napi::Value toxSelfGetStatusMessage(const Napi::CallbackInfo& info);
    void toxSelfSetStatus(const Napi::CallbackInfo& info);
    Napi::Value toxSelfGetStatus(const Napi::CallbackInfo& info);
    /*
     * Friend list management
     */
    Napi::Value toxFriendAdd(const Napi::CallbackInfo& info);
    Napi::Value toxFriendAddNorequest(const Napi::CallbackInfo& info);
    Napi::Value toxFriendDelete(const Napi::CallbackInfo& info);
    /*
     * Friend list queries
     */
    Napi::Value toxFriendByPublicKey(const Napi::CallbackInfo& info);
    Napi::Value toxFriendExists(const Napi::CallbackInfo& info);
    Napi::Value toxSelfGetFriendListSize(const Napi::CallbackInfo& info);
    Napi::Value toxSelfGetFriendList(const Napi::CallbackInfo& info);
    Napi::Value toxFriendGetPublicKey(const Napi::CallbackInfo& info);
    Napi::Value toxFriendGetLastOnline(const Napi::CallbackInfo& info);
    /*
     * Friend-specific state queries (can also be received through callbacks)
     */
    Napi::Value toxFriendGetNameSize(const Napi::CallbackInfo& info);
    Napi::Value toxFriendGetName(const Napi::CallbackInfo& info);
    void toxCallbackFriendName(const Napi::CallbackInfo& info);
    static void _friendNameChanged(Tox *tox, uint32_t friend_number, const uint8_t *name, size_t length, void *user_data);
    Napi::Value toxFriendGetStatusMessageSize(const Napi::CallbackInfo& info);
    Napi::Value toxFriendGetStatusMessage(const Napi::CallbackInfo& info);
    void toxCallbackFriendStatusMessage(const Napi::CallbackInfo& info);
    static void _friendStatusMessageChanged(Tox *tox, uint32_t friend_number, const uint8_t *message, size_t length, void *user_data);
    Napi::Value toxFriendGetStatus(const Napi::CallbackInfo& info);
    void toxCallbackFriendStatus(const Napi::CallbackInfo& info);
    static void _friendStatusChanged(Tox *tox, uint32_t friend_number, TOX_USER_STATUS status, void *user_data);
    Napi::Value toxFriendGetConnectionStatus(const Napi::CallbackInfo& info);
    void toxCallbackFriendConnectionStatus(const Napi::CallbackInfo& info);
    static void _friendConnectionStatusChanged(Tox *tox, uint32_t friend_number, TOX_CONNECTION connection_status, void *user_data);
    Napi::Value toxFriendGetTyping(const Napi::CallbackInfo& info);
    void toxCallbackFriendTyping(const Napi::CallbackInfo& info);
    static void _friendTypingChanged(Tox *tox, uint32_t friend_number, bool is_typing, void *user_data);
    /*
     * Sending private messages
     */
    Napi::Value toxSelfSetTyping(const Napi::CallbackInfo& info);
    Napi::Value toxFriendSendMessage(const Napi::CallbackInfo& info);
    void toxCallbackFriendReadReceipt(const Napi::CallbackInfo& info);
    static void _friendReadReceiptChanged(Tox *tox, uint32_t friend_number, uint32_t message_id, void *user_data);
    void toxCallbackFriendRequest(const Napi::CallbackInfo& info);
    static void _friendRequestChanged(Tox *tox, const uint8_t *public_key, const uint8_t *message, size_t length, void *user_data);
    void toxCallbackFriendMessage(const Napi::CallbackInfo& info);
    static void _friendMessageChanged(Tox *tox, uint32_t friend_number, TOX_MESSAGE_TYPE type, const uint8_t *message, size_t length, void *user_data);
    /*
     * File transmission: common between sending and receiving
     */
    Napi::Value toxHash(const Napi::CallbackInfo& info);
    Napi::Value toxFileControl(const Napi::CallbackInfo& info);
    void toxCallbackFileRecvControl(const Napi::CallbackInfo& info);
    static void _fileRecvControlChanged(Tox *tox, uint32_t friend_number, uint32_t file_number, TOX_FILE_CONTROL control, void *user_data);
    Napi::Value toxFileSeek(const Napi::CallbackInfo& info);
    Napi::Value toxFileGetFileId(const Napi::CallbackInfo& info);
    /*
     * File transmission: sending
     */
    Napi::Value toxFileSend(const Napi::CallbackInfo& info);
    Napi::Value toxFileSendChunk(const Napi::CallbackInfo& info);
    void toxCallbackFileChunkRequest(const Napi::CallbackInfo& info);
    static void _fileChunkRequestChanged(Tox *tox, uint32_t friend_number, uint32_t file_number, uint64_t position, size_t length, void *user_data);
    /*
     * File transmission: receiving
     */
    void toxCallbackFileRecv(const Napi::CallbackInfo& info);
    static void _fileRecvChanged(Tox *tox, uint32_t friend_number, uint32_t file_number, uint32_t kind, uint64_t file_size, const uint8_t *filename, size_t filename_length, void *user_data);
    void toxCallbackFileRecvChunk(const Napi::CallbackInfo& info);
    static void _fileRecvChunkChanged(Tox *tox, uint32_t friend_number, uint32_t file_number, uint64_t position, const uint8_t *data, size_t length, void *user_data);
    /*
     * Conference management
     */
    void toxCallbackConferenceInvite(const Napi::CallbackInfo& info);
    static void _conferenceInviteChanged(Tox *tox, uint32_t friend_number, TOX_CONFERENCE_TYPE type, const uint8_t *cookie, size_t length, void *user_data);
    void toxCallbackConferenceMessage(const Napi::CallbackInfo& info);
    static void _conferenceMessageChanged(Tox *tox, uint32_t conference_number, uint32_t peer_number, TOX_MESSAGE_TYPE type, const uint8_t *message, size_t length, void *user_data);
    void toxCallbackConferenceTitle(const Napi::CallbackInfo& info);
    static void _conferenceTitleChanged(Tox *tox, uint32_t conference_number, uint32_t peer_number, const uint8_t *title, size_t length, void *user_data);
    void toxCallbackConferencePeerName(const Napi::CallbackInfo& info);
    static void _conferencePeerNameChanged(Tox *tox, uint32_t conference_number, uint32_t peer_number, const uint8_t *name, size_t length, void *user_data);
    void toxCallbackConferencePeerListChanged(const Napi::CallbackInfo& info);
    static void _conferencePeerListChangedChanged(Tox *tox, uint32_t conference_number, void *user_data);

    Napi::Value toxConferenceNew(const Napi::CallbackInfo& info);
    Napi::Value toxConferenceDelete(const Napi::CallbackInfo& info);
    Napi::Value toxConferencePeerCount(const Napi::CallbackInfo& info);
    Napi::Value toxConferencePeerGetNameSize(const Napi::CallbackInfo& info);
    Napi::Value toxConferencePeerGetName(const Napi::CallbackInfo& info);
    Napi::Value toxConferencePeerGetPublicKey(const Napi::CallbackInfo& info);
    Napi::Value toxConferencePeerNumberIsOurs(const Napi::CallbackInfo& info);
    Napi::Value toxConferenceInvite(const Napi::CallbackInfo& info);
    Napi::Value toxConferenceJoin(const Napi::CallbackInfo& info);
    Napi::Value toxConferenceSendMessage(const Napi::CallbackInfo& info);
    Napi::Value toxConferenceGetTitleSize(const Napi::CallbackInfo& info);
    Napi::Value toxConferenceGetTitle(const Napi::CallbackInfo& info);
    Napi::Value toxConferenceSetTitle(const Napi::CallbackInfo& info);
    Napi::Value toxConferenceGetChatlistSize(const Napi::CallbackInfo& info);
    Napi::Value toxConferenceGetChatlist(const Napi::CallbackInfo& info);
    Napi::Value toxConferenceGetType(const Napi::CallbackInfo& info);
    /*
     * Low-level custom packet sending and receiving
     */
    Napi::Value toxFriendSendLossyPacket(const Napi::CallbackInfo& info);
    Napi::Value toxFriendSendLosslessPacket(const Napi::CallbackInfo& info);
    void toxCallbackFriendLossyPacket(const Napi::CallbackInfo& info);
    static void _friendLossyPacketChanged(Tox *tox, uint32_t friend_number, const uint8_t *data, size_t length, void *user_data);
    void toxCallbackFriendLosslessPacket(const Napi::CallbackInfo& info);
    static void _friendLosslessPacketChanged(Tox *tox, uint32_t friend_number, const uint8_t *data, size_t length, void *user_data);
    /*
     * Low-level network information
     */
    Napi::Value toxSelfGetDhtId(const Napi::CallbackInfo& info);
    Napi::Value toxSelfGetUdpPort(const Napi::CallbackInfo& info);
    Napi::Value toxSelfGetTcpPort(const Napi::CallbackInfo& info);

    Tox_Options* toxOptions;
    Tox* tox;

    Napi::FunctionReference selfConnectionStatusCallback;
    Napi::FunctionReference friendNameCallback;
    Napi::FunctionReference friendStatusMessageCallback;
    Napi::FunctionReference friendStatusCallback;
    Napi::FunctionReference friendConnectionStatusCallback;
    Napi::FunctionReference friendTypingCallback;
    Napi::FunctionReference friendReadReceiptCallback;
    Napi::FunctionReference friendRequestCallback;
    Napi::FunctionReference friendMessageCallback;
    Napi::FunctionReference fileRecvControlCallback;
    Napi::FunctionReference fileChunkRequestCallback;
    Napi::FunctionReference fileRecvCallback;
    Napi::FunctionReference fileRecvChunkCallback;
    Napi::FunctionReference conferenceInviteCallback;
    Napi::FunctionReference conferenceMessageCallback;
    Napi::FunctionReference conferenceTitleCallback;
    Napi::FunctionReference conferencePeerNameCallback;
    Napi::FunctionReference conferencePeerListChangedCallback;
    Napi::FunctionReference friendLossyPacketCallback;
    Napi::FunctionReference friendLosslessPacketCallback;
};

#endif // TOXCORE_H