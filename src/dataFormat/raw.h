#ifndef _TOF_DATAFORMAT_H_
#define _TOF_DATAFORMAT_H_

#include <stdint.h>

namespace tof {
  namespace data {
    namespace raw {

      /** flags **/

      enum EFlag_t {
	Flag_Header = 0x1,
	Flag_Trailer = 0x2,
	Flag_EventCounter = 0x4,
      };
      
      /** generic word **/

      struct Word_t
      {
	uint32_t SlotID     :  4;
	uint32_t UNDEFINED  : 24;
	uint32_t WordType   :  4;
      };
      
      /** DRM data **/
      
      struct DRMGlobalHeader_t
      {
	uint32_t SlotID     :  4;
	uint32_t EventWords : 17;
	uint32_t DRMID      :  7;
	uint32_t WordType   :  4;
      };

      struct DRMStatusHeader1_t
      {
	uint32_t SlotID              :  4;
	uint32_t ParticipatingSlotID : 11;
	uint32_t CBit                :  1;
	uint32_t VersID              :  5;
	uint32_t DRMhSize            :  4;
	uint32_t UNDEFINED           :  3;
	uint32_t WordType            :  4;
      };

      struct DRMStatusHeader2_t
      {
	uint32_t SlotID         :  4;
	uint32_t SlotEnableMask : 11;
	uint32_t MBZ            :  1;
	uint32_t FaultID        : 11;
	uint32_t RTOBit         :  1;
	uint32_t WordType       :  4;
      };

      struct DRMStatusHeader3_t
      {
	uint32_t SlotID      : 4;
	uint32_t L0BCID      : 12;
	uint32_t RunTimeInfo : 12; // check
	uint32_t WordType    : 4;
      };

      struct DRMStatusHeader4_t
      {
	uint32_t SlotID      :  4;
	uint32_t Temperature : 10;
	uint32_t MBZ1        :  1;
	uint32_t ACKBit      :  1;
	uint32_t SensAD      :  3;
	uint32_t MBZ2        :  1;
	uint32_t UNDEFINED   :  8;
	uint32_t WordType    :  4;
      };
     
      struct DRMGlobalTrailer_t
      {
	uint32_t SlotID            :  4;
	uint32_t LocalEventCounter : 12;
	uint32_t UNDEFINED         : 12;
	uint32_t WordType          :  4;
      };

      /** TRM data **/
      
      struct TRMGlobalHeader_t
      {
	uint32_t SlotID     :  4;
	uint32_t EventWords : 13;
	uint32_t ACQBits    :  2;
	uint32_t LBit       :  1;
	uint32_t EBit       :  1;
	uint32_t MBZ        :  7;
	uint32_t WordType   :  4;
      };

      struct TRMGlobalTrailer_t
      {
	uint32_t SlotID       :  4;
	uint32_t EventCRC     : 12;
	uint32_t EventCounter : 12;
	uint32_t WordType     :  4;
      };

      /** TRM-chain data **/
      
      struct TRMChainHeader_t
      {
	uint32_t SlotID   :  4;
	uint32_t BunchID  : 12;
	uint32_t PB24Temp :  8;
	uint32_t PB24ID   :  3;
	uint32_t TSBit    :  1;
	uint32_t WordType :  4;
      };

      struct TRMChainTrailer_t
      {
	uint32_t Status       :  4;
	uint32_t MBZ          : 12;
	uint32_t EventCounter : 12;
	uint32_t WordType     :  4;
      };

      /** TDC hit **/

      struct TDCPackedHit_t
      {
	uint32_t HitTime  : 13;
	uint32_t TOTWidth :  8;
	uint32_t Chan     :  3;
	uint32_t TDCID    :  4;
	uint32_t EBit     :  1;
	uint32_t PSBits   :  2;
	uint32_t MBO      :  1;
      };

      struct TDCUnpackedHit_t
      {
	uint32_t HitTime:  21; // leading or trailing edge measurement
	uint32_t Chan:      3; // TDC channel number
	uint32_t TDCID:     4; // TDC ID
	uint32_t EBit:      1; // E bit
	uint32_t PSBits:    2; // PS bits
	uint32_t MBO:       1; // must-be-zero bits
      };

      /** union **/

      static union
      {
	uint32_t           *Data;
	Word_t             *Word;
	DRMGlobalHeader_t  *DRMGlobalHeader;
	DRMStatusHeader1_t *DRMStatusHeader1;
	DRMStatusHeader2_t *DRMStatusHeader2;
	DRMStatusHeader3_t *DRMStatusHeader3;
	DRMStatusHeader4_t *DRMStatusHeader4;
	DRMGlobalTrailer_t *DRMGlobalTrailer;
	TRMGlobalHeader_t  *TRMGlobalHeader;
	TRMGlobalTrailer_t *TRMGlobalTrailer;
	TRMChainHeader_t   *TRMChainHeader;
	TRMChainTrailer_t  *TRMChainTrailer;
	TDCPackedHit_t     *TDCPackedHit;
	TDCUnpackedHit_t   *TDCUnpackedHit;
      };

      /** summary data **/

      struct TRMChainSummaryData_t
      {
	uint8_t           Status;
	uint32_t          FirstWord;
	uint32_t          LastWord;
	TRMChainHeader_t  TRMChainHeader;
	TRMChainTrailer_t TRMChainTrailer;
      } TRMChainSummaryData[10][2];
      
      struct TRMSummaryData_t
      {
	uint8_t            Status;
	uint32_t           FirstWord;
	uint32_t           LastWord;
	TRMGlobalHeader_t  TRMGlobalHeader;
	TRMGlobalTrailer_t TRMGlobalTrailer;
      } TRMSummaryData[10];
      
      struct DRMSummaryData_t
      {
	uint8_t            Status;
	uint32_t           FirstWord;
	uint32_t           LastWord;
	DRMGlobalHeader_t  DRMGlobalHeader;
	DRMStatusHeader1_t DRMStatusHeader1;
	DRMStatusHeader2_t DRMStatusHeader2;
	DRMStatusHeader3_t DRMStatusHeader3;
	DRMStatusHeader4_t DRMStatusHeader4;
	DRMGlobalTrailer_t DRMGlobalTrailer;
      } DRMSummaryData;

      /** counter data **/

      struct TRMChainCounterData_t
      { 
	uint32_t ExpectedData;
	uint32_t DetectedData;
	uint32_t EventCounterMismatch;
	uint32_t BadStatus;
      } TRMChainCounterData[10][2];
      
      struct TRMCounterData_t
      {
	uint32_t ExpectedData;
	uint32_t DetectedData;
	uint32_t EventWordsMismatch;
	uint32_t EventCounterMismatch;
      } TRMCounterData[10];
      
      struct DRMCounterData_t
      {
	uint32_t ExpectedData;
	uint32_t DetectedData;
	uint32_t EventWordsMismatch;
      } DRMCounterData;      
      
    }
  }
}

#endif /** _TOF_DATAFORMAT_H_ **/
