#ifndef _DATA_H
#define _DATA_H
#pragma once

//#include "dependencies.h"

#include "common.h"
#include "helper.h"

namespace Data
{
	namespace Gui
	{
		struct GUI
		{
			// General:
			wchar_t user_name[64];
			wchar_t domain_name[64];
			wchar_t ldap_pass[64];

			// LogonUnlock:
			wchar_t otp_pass[64];

			// ChangePassword:
			wchar_t ldap_pass_new_1[64];
			wchar_t ldap_pass_new_2[64];

			// Resync
			wchar_t otp_pass_2[64];
		};

		GUI*& Get();
		void Init();
		void Deinit();
		void Default();
	}

	namespace Provider
	{
		struct PROVIDER
		{
			ICredentialProviderEvents* _pcpe;
			UINT_PTR _upAdviseContext;

			CREDENTIAL_PROVIDER_USAGE_SCENARIO usage_scenario;
			DWORD credPackFlags;
		};

		PROVIDER*& Get();
		void Init();
		void Deinit();
	}

	namespace Credential
	{
		struct CREDENTIAL
		{
			PWSTR user_name;
			PWSTR domain_name;
			PWSTR password;

			IQueryContinueWithStatus* pqcws = NULL;
			bool userCanceled = false;
			HRESULT endpointStatus = E_FAIL;			
		};

		CREDENTIAL*& Get();
		void Init();
		void Deinit();
		void Default();
	}

	namespace General
	{
		struct GENERAL
		{
			bool startEndpointObserver = false;
			bool bypassEndpoint = false;
			bool bypassDataInitialization = false;
			bool bypassDataDeinitialization = false;
			bool bypassKerberos = false;
			bool clearFields = true;
		};

		GENERAL*& Get();
		void Init();
		void Deinit();
		void Default();
	}
}

#endif