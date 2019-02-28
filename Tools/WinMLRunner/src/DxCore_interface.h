//! Copied from internal SDK. Remove once public.

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

/* verify that the <rpcsal.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCSAL_H_VERSION__
#define __REQUIRED_RPCSAL_H_VERSION__ 100
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __dxcore_interface_h__
#define __dxcore_interface_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDXCoreAdapter_FWD_DEFINED__
#define __IDXCoreAdapter_FWD_DEFINED__
typedef interface IDXCoreAdapter IDXCoreAdapter;

#endif 	/* __IDXCoreAdapter_FWD_DEFINED__ */


#ifndef __IDXCoreAdapterList_FWD_DEFINED__
#define __IDXCoreAdapterList_FWD_DEFINED__
typedef interface IDXCoreAdapterList IDXCoreAdapterList;

#endif 	/* __IDXCoreAdapterList_FWD_DEFINED__ */


#ifndef __IDXCoreAdapterFactory_FWD_DEFINED__
#define __IDXCoreAdapterFactory_FWD_DEFINED__
typedef interface IDXCoreAdapterFactory IDXCoreAdapterFactory;

#endif 	/* __IDXCoreAdapterFactory_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_dxcore_interface_0000_0000 */
/* [local] */ 

#ifdef __midl
typedef /* [string] */  __RPC_string WCHAR *PWSTR;

typedef unsigned __int32 uint32_t;

typedef unsigned __int64 uint64_t;

typedef __int32 int32_t;

typedef SIZE_T size_t;

typedef struct _LUID
    {
    uint32_t LowPart;
    int32_t HighPart;
    } 	LUID;

typedef struct _LUID *PLUID;

#endif
typedef struct DXCoreHardwareID
    {
    uint32_t vendorId;
    uint32_t deviceId;
    uint32_t subSysId;
    uint32_t revision;
    } 	DXCoreHardwareID;

typedef struct DXCoreQueryVideoMemoryInfo
    {
    uint64_t Budget;
    uint64_t CurrentUsage;
    uint64_t AvailableForReservation;
    uint64_t CurrentReservation;
    } 	DXCoreQueryVideoMemoryInfo;

#ifdef __cplusplus
enum class DXCoreProperty
{
    IsHardware = 0,
    DriverVersion = 1,
    DriverDescription = 2,
    KmdModelVersion = 3,
    IsDriverUpdateInProgress = 4,
    ComputePreemptionGranularity = 5,
    GraphicsPreemptionGranularity = 6,
    DedicatedVideoMemory = 7,
    ACGCompatible = 8
}; 
enum class DXCoreMemorySegmentGroup
{
    Local = 0,
    NonLocal = 1,
}; 
#else
typedef 
enum DXCoreProperty
    {
        DXCoreProperty_IsHardware	= 0,
        DXCoreProperty_DriverVersion	= 1,
        DXCoreProperty_DriverDescription	= 2,
        DXCoreProperty_KmdModelVersion	= 3,
        DXCoreProperty_IsDriverUpdateInProgress	= 4,
        DXCoreProperty_ComputePreemptionGranularity	= 5,
        DXCoreProperty_GraphicsPreemptionGranularity	= 6,
        DXCoreProperty_DedicatedVideoMemory	= 7,
        DXCoreProperty_ACGCompatible	= 8
    } 	DXCoreProperty;

typedef 
enum DXCoreMemorySegmentGroup
    {
        DXCoreMemorySegmentGroup_Local	= 0,
        DXCoreMemorySegmentGroup_NonLocal	= ( DXCoreMemorySegmentGroup_Local + 1 ) 
    } 	DXCoreMemorySegmentGroup;

#endif // __cplusplus
DEFINE_GUID(DXCORE_ADAPTER_ATTRIBUTE_D3D12_GRFX, 0x0c9ece4d, 0x2f6e, 0x4f01, 0x8c, 0x96, 0xe8, 0x9e, 0x33, 0x1b, 0x47, 0xb1);
DEFINE_GUID(DXCORE_ADAPTER_ATTRIBUTE_D3D12_CORE_COMPUTE, 0x248e2800, 0xa793, 0x4724, 0xab, 0xaa, 0x23, 0xa6, 0xde, 0x1b, 0xe0, 0x90);

extern RPC_IF_HANDLE __MIDL_itf_dxcore_interface_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_dxcore_interface_0000_0000_v0_0_s_ifspec;

#ifndef __IDXCoreAdapter_INTERFACE_DEFINED__
#define __IDXCoreAdapter_INTERFACE_DEFINED__

/* interface IDXCoreAdapter */
/* [unique][local][object][uuid] */ 


EXTERN_C const IID IID_IDXCoreAdapter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("23fdbe30-0292-491b-89f2-aeecfcfa11c6")
    IDXCoreAdapter : public IUnknown
    {
    public:
        virtual boolean STDMETHODCALLTYPE IsValid( void) = 0;
        
        virtual boolean STDMETHODCALLTYPE IsDXAttributeSupported( 
            /* [annotation][in] */ 
            _In_  GUID attributeGUID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHardwareID( 
            /* [annotation][out] */ 
            _Out_  DXCoreHardwareID *hardwareID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLUID( 
            /* [annotation][out] */ 
            _Out_  LUID *adapterLUID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryProperty( 
            /* [annotation][in] */ 
            _In_  DXCoreProperty property,
            /* [annotation][in] */ 
            _In_  size_t bufferSize,
            /* [annotation][size_is][out] */ 
            _Out_writes_(bufferSize)  void *propertyData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryPropertySize( 
            /* [annotation][in] */ 
            _In_  DXCoreProperty property,
            /* [annotation][out] */ 
            _Out_  size_t *bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryVideoMemoryInfo( 
            /* [annotation][in] */ 
            _In_  uint32_t NodeIndex,
            /* [annotation][in] */ 
            _In_  DXCoreMemorySegmentGroup MemorySegmentGroup,
            /* [annotation][out] */ 
            _Out_  DXCoreQueryVideoMemoryInfo *pVideoMemoryInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVideoMemoryReservation( 
            /* [annotation][in] */ 
            _In_  uint32_t NodeIndex,
            /* [annotation][in] */ 
            _In_  DXCoreMemorySegmentGroup MemorySegmentGroup,
            /* [annotation][in] */ 
            _In_  uint64_t Reservation) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDXCoreAdapterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXCoreAdapter * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXCoreAdapter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXCoreAdapter * This);
        
        boolean ( STDMETHODCALLTYPE *IsValid )( 
            IDXCoreAdapter * This);
        
        boolean ( STDMETHODCALLTYPE *IsDXAttributeSupported )( 
            IDXCoreAdapter * This,
            /* [annotation][in] */ 
            _In_  GUID attributeGUID);
        
        HRESULT ( STDMETHODCALLTYPE *GetHardwareID )( 
            IDXCoreAdapter * This,
            /* [annotation][out] */ 
            _Out_  DXCoreHardwareID *hardwareID);
        
        HRESULT ( STDMETHODCALLTYPE *GetLUID )( 
            IDXCoreAdapter * This,
            /* [annotation][out] */ 
            _Out_  LUID *adapterLUID);
        
        HRESULT ( STDMETHODCALLTYPE *QueryProperty )( 
            IDXCoreAdapter * This,
            /* [annotation][in] */ 
            _In_  DXCoreProperty property,
            /* [annotation][in] */ 
            _In_  size_t bufferSize,
            /* [annotation][size_is][out] */ 
            _Out_writes_(bufferSize)  void *propertyData);
        
        HRESULT ( STDMETHODCALLTYPE *QueryPropertySize )( 
            IDXCoreAdapter * This,
            /* [annotation][in] */ 
            _In_  DXCoreProperty property,
            /* [annotation][out] */ 
            _Out_  size_t *bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *QueryVideoMemoryInfo )( 
            IDXCoreAdapter * This,
            /* [annotation][in] */ 
            _In_  uint32_t NodeIndex,
            /* [annotation][in] */ 
            _In_  DXCoreMemorySegmentGroup MemorySegmentGroup,
            /* [annotation][out] */ 
            _Out_  DXCoreQueryVideoMemoryInfo *pVideoMemoryInfo);
        
        HRESULT ( STDMETHODCALLTYPE *SetVideoMemoryReservation )( 
            IDXCoreAdapter * This,
            /* [annotation][in] */ 
            _In_  uint32_t NodeIndex,
            /* [annotation][in] */ 
            _In_  DXCoreMemorySegmentGroup MemorySegmentGroup,
            /* [annotation][in] */ 
            _In_  uint64_t Reservation);
        
        END_INTERFACE
    } IDXCoreAdapterVtbl;

    interface IDXCoreAdapter
    {
        CONST_VTBL struct IDXCoreAdapterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXCoreAdapter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXCoreAdapter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXCoreAdapter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXCoreAdapter_IsValid(This)	\
    ( (This)->lpVtbl -> IsValid(This) ) 

#define IDXCoreAdapter_IsDXAttributeSupported(This,attributeGUID)	\
    ( (This)->lpVtbl -> IsDXAttributeSupported(This,attributeGUID) ) 

#define IDXCoreAdapter_GetHardwareID(This,hardwareID)	\
    ( (This)->lpVtbl -> GetHardwareID(This,hardwareID) ) 

#define IDXCoreAdapter_GetLUID(This,adapterLUID)	\
    ( (This)->lpVtbl -> GetLUID(This,adapterLUID) ) 

#define IDXCoreAdapter_QueryProperty(This,property,bufferSize,propertyData)	\
    ( (This)->lpVtbl -> QueryProperty(This,property,bufferSize,propertyData) ) 

#define IDXCoreAdapter_QueryPropertySize(This,property,bufferSize)	\
    ( (This)->lpVtbl -> QueryPropertySize(This,property,bufferSize) ) 

#define IDXCoreAdapter_QueryVideoMemoryInfo(This,NodeIndex,MemorySegmentGroup,pVideoMemoryInfo)	\
    ( (This)->lpVtbl -> QueryVideoMemoryInfo(This,NodeIndex,MemorySegmentGroup,pVideoMemoryInfo) ) 

#define IDXCoreAdapter_SetVideoMemoryReservation(This,NodeIndex,MemorySegmentGroup,Reservation)	\
    ( (This)->lpVtbl -> SetVideoMemoryReservation(This,NodeIndex,MemorySegmentGroup,Reservation) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXCoreAdapter_INTERFACE_DEFINED__ */


#ifndef __IDXCoreAdapterList_INTERFACE_DEFINED__
#define __IDXCoreAdapterList_INTERFACE_DEFINED__

/* interface IDXCoreAdapterList */
/* [unique][local][object][uuid] */ 


EXTERN_C const IID IID_IDXCoreAdapterList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("345426f8-db80-4ee1-a976-f5b6ead6255c")
    IDXCoreAdapterList : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetItem( 
            /* [annotation][in] */ 
            _In_  uint32_t index,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXCoreAdapter **adapter) = 0;
        
        virtual uint32_t STDMETHODCALLTYPE GetAdapterCount( void) = 0;
        
        virtual boolean STDMETHODCALLTYPE IsStale( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDXCoreAdapterListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXCoreAdapterList * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXCoreAdapterList * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXCoreAdapterList * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetItem )( 
            IDXCoreAdapterList * This,
            /* [annotation][in] */ 
            _In_  uint32_t index,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXCoreAdapter **adapter);
        
        uint32_t ( STDMETHODCALLTYPE *GetAdapterCount )( 
            IDXCoreAdapterList * This);
        
        boolean ( STDMETHODCALLTYPE *IsStale )( 
            IDXCoreAdapterList * This);
        
        END_INTERFACE
    } IDXCoreAdapterListVtbl;

    interface IDXCoreAdapterList
    {
        CONST_VTBL struct IDXCoreAdapterListVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXCoreAdapterList_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXCoreAdapterList_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXCoreAdapterList_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXCoreAdapterList_GetItem(This,index,adapter)	\
    ( (This)->lpVtbl -> GetItem(This,index,adapter) ) 

#define IDXCoreAdapterList_GetAdapterCount(This)	\
    ( (This)->lpVtbl -> GetAdapterCount(This) ) 

#define IDXCoreAdapterList_IsStale(This)	\
    ( (This)->lpVtbl -> IsStale(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXCoreAdapterList_INTERFACE_DEFINED__ */


#ifndef __IDXCoreAdapterFactory_INTERFACE_DEFINED__
#define __IDXCoreAdapterFactory_INTERFACE_DEFINED__

/* interface IDXCoreAdapterFactory */
/* [unique][local][object][uuid] */ 


EXTERN_C const IID IID_IDXCoreAdapterFactory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0b0a7ab8-1515-4da4-9fba-4f784044085d")
    IDXCoreAdapterFactory : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetAdapterList( 
            /* [annotation][in] */ 
            _In_  const GUID *filterDXAttributes,
            /* [annotation][in] */ 
            _In_  uint32_t numDXAttributes,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXCoreAdapterList **adapterList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAdapterByLuid( 
            /* [annotation][in] */ 
            _In_  LUID adapterLUID,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXCoreAdapter **adapter) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDXCoreAdapterFactoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXCoreAdapterFactory * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXCoreAdapterFactory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXCoreAdapterFactory * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetAdapterList )( 
            IDXCoreAdapterFactory * This,
            /* [annotation][in] */ 
            _In_  const GUID *filterDXAttributes,
            /* [annotation][in] */ 
            _In_  uint32_t numDXAttributes,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXCoreAdapterList **adapterList);
        
        HRESULT ( STDMETHODCALLTYPE *GetAdapterByLuid )( 
            IDXCoreAdapterFactory * This,
            /* [annotation][in] */ 
            _In_  LUID adapterLUID,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXCoreAdapter **adapter);
        
        END_INTERFACE
    } IDXCoreAdapterFactoryVtbl;

    interface IDXCoreAdapterFactory
    {
        CONST_VTBL struct IDXCoreAdapterFactoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXCoreAdapterFactory_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXCoreAdapterFactory_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXCoreAdapterFactory_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXCoreAdapterFactory_GetAdapterList(This,filterDXAttributes,numDXAttributes,adapterList)	\
    ( (This)->lpVtbl -> GetAdapterList(This,filterDXAttributes,numDXAttributes,adapterList) ) 

#define IDXCoreAdapterFactory_GetAdapterByLuid(This,adapterLUID,adapter)	\
    ( (This)->lpVtbl -> GetAdapterByLuid(This,adapterLUID,adapter) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXCoreAdapterFactory_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


