/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * applib_asn_common.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is header file for ASN common function.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 *
 * COMPONENT:   ASN
 * MODULE:      ASN_COMMON
 * DESCRIPTION: Auto generated by MTK ASN.1 Compiler
 *
 ****************************************************************************/
 /**
  * @file asn_common.h
  *
  * ASN.1 Common header file
  *
  * @ingroup asn_common
  */


#ifndef ASN_COMMON_H
#define ASN_COMMON_H




#ifdef __cplusplus
 extern "C" {
#endif

#ifdef __VXWORKS__
   #include "vxWorks.h"
#endif

//#include <setjmp.h>
//#include "applib_asn_memory.h"
#include "applib_mtkasn_global.h"

///changshun add for RHR
#include "kal_general_types.h"
///

typedef enum
{
   ASN_OK    =  0,
   ASN_ERROR = -1
}
applib_AsnStatus;

#define AsnNull S8

typedef struct
{
   int length;
   unsigned char value[100];
}
applib_AsnAny;

#define  AsnObjId S8

#define  AsnOpen S8

#define  AsnBool S8

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL (void *)0
#endif

#ifndef NOT_USED
#define NOT_USED(x) (void)(x)
#endif

#define UA1_ERROR( x ) applib_AsnError( pContext, x )

typedef struct
{
   void *pMemBlock[200];
   void **ppNext;
   void **ppEnd;
} applib_AllocRecord;

typedef  void  (*applib_PAsnMemAllocCallBack)(void **memPtr, unsigned long size, const char *file, unsigned long line);
typedef  void  (*applib_PAsnMemFreeCallBack)(void ** ppBuffer);

typedef struct
{
   applib_PAsnMemAllocCallBack pMemAllocFunc;
   applib_PAsnMemFreeCallBack pMemFreeFunc;
}applib_AsnCustomMemFunctions;

//added for replace jmpbuf
#ifdef MCD_DLL_EXPORT 
  #include <setjmp.h>
  #define asn_jmpbuf jmp_buf  
#else 
  #if defined(__MTK_TARGET__) && defined(__RVCT__)
    typedef long long asn_jmpbuf[32];
#elif defined(__MTK_TARGET__)
      typedef int asn_jmpbuf[32];
  #else  
    	///add for vc9.0 
	    //vc 9.0 have un-standard code , cgen could not pass the parse
	    // GEN_FOR_PC: just defined when codegen_modis
      #ifndef GEN_FOR_PC 
        #include <setjmp.h>
      #else
        #define _JBLEN 32
        #define _JBTYPE int
	      typedef _JBTYPE jmp_buf[_JBLEN];
      #endif  
	    ///
      #define asn_jmpbuf jmp_buf
  #endif 
#endif
//added for replace jmpbuf

typedef struct
{
   U32 shiftRegister;
   U32 shiftRegisterLength;
   U8 *pEncoded;
   U8 *pEncodedEnd;
   //jmp_buf env;
   asn_jmpbuf env;
   void *encodeAlloc;
   applib_AllocRecord *decodeAlloc;
   void *pAppContext;
   U32 result;
   applib_PAsnMemAllocCallBack pMemAllocFunc;
   applib_PAsnMemFreeCallBack  pMemFreeFunc;
}  applib_AsnContext;

#define		ASN_MAX		0xFFFFFFFF
#define		ASN_MIN		-2147483648

typedef struct Tag_OID
{
	U32		valueLen;
	U32		*value;
}applib_OID;


typedef struct Tag_OCTETSTR {
	U32    valueLen;
	U8     *value;
}applib_OCTETSTR;

/************************************************************************/
/*  String  Definition                                                  */
/************************************************************************/
typedef struct Tag__OneByteString
{
	U32		valueLen;
	char  	*value;
}applib_OneByteString;

typedef struct Tag__TwoByteString
{
	U32		valueLen;
	U16  	*value;
}applib_TwoByteString;

typedef struct Tag__FourByteString
{
	U32		valueLen;
	U32  	*value;
}applib_FourByteString;


typedef struct Tag_ASN_OneByteAlphabet
{
	U32		valueLen;
	char	*value;
}applib_ASN_OneByteAlphabet;

typedef struct Tag_ASN_TwoByteAlphabet
{
	U32		valueLen;
	U16		*value;
}applib_ASN_TwoByteAlphabet;

//////////////////////////////////////////////////////////////////////////
// Extension Item
typedef struct Tag_UnKnowExtensionItem
{
	U32		valueLen;
	U8  	*value;
}applib_UnKnowExtensionItem;

typedef struct Tag_UnKnowExtensionItemArray
{
	U32						valueLen;		// Extension Number
	applib_UnKnowExtensionItem		*value;		// Point to the first 
}applib_UnKnowExtensionItemArray;


typedef struct Tag_ChoiceUnKnow
{
	U32		uIndex;
	U32		valueLen;
	U8		*value;
}applib_ChoiceUnKnow;

#define 		applib_asn_ESCString	applib_OneByteString

#define		applib_asn_IA5String		 applib_OneByteString
#define		applib_asn_NumericString	 applib_OneByteString
#define		applib_asn_VisibleString	 applib_OneByteString
#define		applib_asn_PrintableString applib_OneByteString


#define		applib_asn_BMPString		 applib_TwoByteString
#define		applib_asn_UniversalString applib_FourByteString
#define		applib_asn_GeneralString	 applib_asn_ESCString

#define		applib_asn_UTCTime applib_asn_VisibleString
#define		applib_asn_GeneralizedTime applib_asn_VisibleString

#define		EncodeBeginPoint	U32

#define		GET_U16_LOW(x)		((x) & 0x00FF)
#define		GET_U16_HIGH(x)		(((x) >> 8) & 0x00FF)
#define		MAKE_U16(low,high)  ((U16)((U8)(low)) | (((U16)(U8)(high))<<8))  

#define		asn_min(a,b)		(((a) < (b)) ? (a) : (b))
#define		asn_max(a,b)		(((a) > (b)) ? (a) : (b))

#define		PER_ALIGN		do{		\
if (0 != (pContext->shiftRegisterLength)%8) {			\
applib_putShortBits( pContext, 8 - (pContext->shiftRegisterLength)%8 , 0);	\
}	\
}while(0);


#define		PER_CLEAR_ALIGN_BITS	applib_getShortBits( pContext, pContext->shiftRegisterLength);


#define		BEGIN_PRE_ENCODE			do{	 						\
   EncodeBeginPoint	begin;					\
	 applib_AsnContext TempContext = *pContext;			\
   pContext->shiftRegisterLength = 0;\
   if (NULL != pContext->pEncoded)\
   {\
      pContext->shiftRegister = 0;\
   }\
	 begin = applib_BeginTestEncodeLen(pContext);	


#define	END_PRE_ENCODE	ulen = applib_EndTestEncodeLen(pContext, begin);	\
	if(0 == ulen){applib_putShortBits(pContext, 8, 0); ulen = 1;}\
   *pContext = TempContext;			\
  if (NULL != pContext->pEncoded)\
  {\
	   applib_asnMemAlloc(pContext, (void **)&pTemp, ulen);		\
	   applib_asnMemCopy(pTemp, pContext->pEncoded, ulen);	\
  }\
}while(0); 


#define		BEGIN_PRE_DECODE_EXT			do{	 		\
		U8 *pTemp;	\
		applib_AsnContext TempContext;	\
		int len = applib_UperGetLengthValue(pContext, 0, ASN_MAX);		\
		applib_asnMemAlloc(pContext, (void **)&pTemp, len);		\
		TempContext = *pContext;


#define	END_PRE_DECODE_EXT	*pContext = TempContext;	\
		applib_getLongBits(pContext, len*8, pTemp);			\
   if (pContext->pMemFreeFunc != NULL)\
   {\
      pContext->pMemFreeFunc((void **)&pTemp);\
   }\
   else\
   {\
		applib_asnMemFree((void **)&pTemp);	\
   }\
}while(0);


#define	COPY_STATIC_ARRAY_TO_BUFFER(pBuffer, Array, begin, len)		do{\
	int i;\
	for(i=0; i<len; i++)\
		{*(pBuffer+i) = Array[begin+i];}\
}while(0);	

U16  applib_GetUperLengthDeterminant( applib_AsnContext *pContext );
void applib_PutUperLengthDeterminant( applib_AsnContext *pContext, U16 length );
void applib_AsnFreeDecoded( void *pType, applib_PAsnMemFreeCallBack pFreeFunc);
void applib_AsnFreeEncoded( U8 *pEncoded, applib_PAsnMemFreeCallBack pFreeFunc);
void applib_AsnRootDecodeAlloc( applib_AsnContext *pContext, void **ppType, int size );
void applib_AsnRootDecodeAlloc2( applib_AsnContext *pContext, void **ppType, int size, const char *file, unsigned long line);
void applib_AsnDecodeAlloc( applib_AsnContext *pContext, void **ppMem, int size );
void applib_AsnDecodeAlloc2( applib_AsnContext *pContext, void **ppMem, int size, const char *file, int line);
void applib_AsnDecodeFree( applib_AllocRecord *decodeAlloc, applib_PAsnMemFreeCallBack pFreeFunc );
void applib_AsnEncodeAlloc( applib_AsnContext *pContext, U8 **ppMem, U32 *pEncodedLength );
void applib_AsnEncodeAlloc2( applib_AsnContext *pContext, U8 **ppEncoded, U32 *pEncodedLength, const char *file, int line);
void applib_AsnEncodeFree( void *pFree, applib_PAsnMemFreeCallBack pFreeFunc);
void applib_AsnError( applib_AsnContext *pContext, U32 errorCode );
extern void applib_initFifo( applib_AsnContext *pContext, U8 *buffer, U32 bufferLength );
extern void applib_flushFifo( applib_AsnContext *pContext );
extern U32  applib_getShortBits( applib_AsnContext *pContext, U32 numBits );
extern U32  applib_getBits( applib_AsnContext *pContext, U32 numBits );
extern void applib_getLongBits( applib_AsnContext *pContext, U32 numBits, U8 *outputBuffer );
extern U64 applib_getInt64( applib_AsnContext *pContext, U32 numBits );
extern void applib_putShortBits( applib_AsnContext *pContext, U32 numBits, U32 data );
extern void applib_putBits( applib_AsnContext *pContext, U32 numBits, U32 data );
extern void applib_putInt64( applib_AsnContext *pContext, U32 numBits, U64 data );
extern void applib_putLongBits( applib_AsnContext *pContext, U32 numBits, U8 *data );
extern S32  applib_GetAlphabetIndex(applib_ASN_OneByteAlphabet *pAlphabet, char *pChar);
extern U32  applib_GetNumberOctetLength(U32  Data);
extern Bool applib_OIDCompare(applib_OID  oidA, U32 lenght, U32 *pValue);
extern void  applib_SkipEncodeByte(applib_AsnContext *pContext);
extern EncodeBeginPoint applib_BeginTestEncodeLen(applib_AsnContext *pContext);
extern U32	applib_EndTestEncodeLen(applib_AsnContext *pContext, EncodeBeginPoint	BeginPoint);
extern void	applib_PutShortSkipedEncodeByte(applib_AsnContext *pContext,  U32 uByte, U32 Data, U32 uAfterSize);
extern U32	applib_testGetShortBits(applib_AsnContext *pContext, U32 numBits);

#ifdef __cplusplus
}
#endif
#endif /* ASN_COMMON_H */
