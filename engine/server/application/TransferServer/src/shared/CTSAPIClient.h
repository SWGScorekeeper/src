// CTSAPIClient.h
// Copyright 2000-01, Sony Online Entertainment Inc., all rights reserved.
// Author: Justin Randall

#ifndef _INCLUDED_CTSAPIClient_H
#define _INCLUDED_CTSAPIClient_H

//-----------------------------------------------------------------------

#include "CTServiceAPI.h"
#include <string>

//-----------------------------------------------------------------------

class CTSAPIClient : public CTService::CTServiceAPI
{
public:
	CTSAPIClient(const std::string & hostName, const std::string & game);
	virtual ~CTSAPIClient();

	virtual void onConnect(const char *host, const short port, const short current, const short max);
	virtual void onDisconnect(const char *host, const short port, const short current, const short max);
	
	// ----- Normal Callbacks as a response to requests sent -----

	virtual void onTest(const unsigned track, const int resultCode, const unsigned value, void *user);
	virtual void onReplyTest(const unsigned track, const int resultCode, void *user);
	virtual void onReplyMoveStatus(const unsigned track, const int resultCode, void *user);
	virtual void onReplyValidateMove(const unsigned track, const int resultCode, void *user);
	virtual void onReplyMove(const unsigned track, const int resultCode, void *user);
	virtual void onReplyTransferAccount(const unsigned track, const int resultCode, void *user);
	virtual void onReplyCharacterList(const unsigned track, const int resultCode, void *user);
	virtual void onReplyServerList(const unsigned track, const int resultCode, void *user);
	virtual void onReplyDestinationServerList(const unsigned track, const int resultCode, void *user);

	// ----- Callbacks generated by the server directly -----

	virtual void onServerTest(const unsigned server_track, const char *game, const char *param);
	virtual void onRequestMoveStatus(const unsigned server_track, const char *language, const unsigned transactionID);
	virtual void onRequestValidateMove(const unsigned server_track, const char *language, const CTService::CTUnicodeChar *sourceServer, const CTService::CTUnicodeChar *destServer, const CTService::CTUnicodeChar *sourceCharacter,const CTService::CTUnicodeChar *destCharacter, const unsigned uid, const unsigned destuid, bool withItems, bool);
	virtual void onRequestMove(const unsigned server_track, const char *language, const CTService::CTUnicodeChar *sourceServer, const CTService::CTUnicodeChar *destServer, const CTService::CTUnicodeChar *sourceCharacter, const CTService::CTUnicodeChar *destCharacter, const unsigned uid, const unsigned destuid, const unsigned transactionID, bool withItems, bool allowOverride);
	virtual void onRequestTransferAccount(const unsigned server_track, const unsigned uid, const unsigned destuid, const unsigned transactionID);
	virtual void onRequestCharacterList(const unsigned server_track, const char *language, const CTService::CTUnicodeChar *server, const unsigned uid);
	virtual void onRequestServerList(const unsigned server_track, const char *language);
	virtual void onRequestDestinationServerList(const unsigned server_track, const char *language, const CTService::CTUnicodeChar *character, const CTService::CTUnicodeChar *server);
	void  moveComplete(unsigned int id, unsigned int track, int result) const;
	void  moveStart(unsigned int id, unsigned int track, const CentralServerConnection * sourceCentralServerConnection, const CentralServerConnection * destinationCentralServerConnection);
	void lostCentralServerConnection(const CentralServerConnection * centralServerConnection);

private:
	/* NOT IMPLEMENTED IN SWG TRANSFER SERVICE */
	void onReplyDelete(const unsigned int, const int, void *);
	void onReplyRestore(const unsigned int, const int, void *);
	void onRequestDelete(const unsigned int, const char *, const CTService::CTUnicodeChar *, const CTService::CTUnicodeChar *, const CTService::CTUnicodeChar *, const CTService::CTUnicodeChar *, const unsigned int, const unsigned int, const unsigned int, bool, bool);
	void onRequestRestore(const unsigned int, const char *, const CTService::CTUnicodeChar *, const CTService::CTUnicodeChar *, const CTService::CTUnicodeChar *, const CTService::CTUnicodeChar *, const unsigned int, const unsigned int, const unsigned int, bool, bool);
	
private:
	CTSAPIClient();
	CTSAPIClient(const CTSAPIClient &);
	CTSAPIClient &  operator=  (const CTSAPIClient &);
};

//-----------------------------------------------------------------------

#endif//_INCLUDED_CTSAPIClient_H
