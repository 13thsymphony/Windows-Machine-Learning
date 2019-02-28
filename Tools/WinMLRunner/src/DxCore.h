//! Copied from internal SDK. Remove once public.

/************************************************************
*                                                           *
* Copyright (c) Microsoft Corporation. All rights reserved. *
*                                                           *
************************************************************/

#ifndef _DXCOREEXTMODULE_H_
#define _DXCOREEXTMODULE_H_

#include <winapifamily.h>
#include <stdint.h>
#include "dxcore_interface.h"

#pragma region Desktop Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

#ifdef __cplusplus
extern "C" {
#endif

#if (_WIN32_WINNT >= _WIN32_WINNT_WIN10)

HRESULT
WINAPI
DXCoreCreateAdapterFactory(
    _In_ REFIID riid,
    _COM_Outptr_ void** factory
    );


#endif // (_WIN32_WINNT >= _WIN32_WINNT_WIN10)

#ifdef __cplusplus
}
#endif

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */
#pragma endregion

#endif // _DXCOREEXTMODULE_H_


