/** @file Adc.h
 *
 * @brief Control Adcs
 *
 */

#ifndef __Adc_H
#define __Adc_H

/*     Includes     */
#include "registers.h"
#include "Adc_Cfg.h"

#define ADC_DATA_ALIGN_RIGHT    (0)
#define ADC_DATA_ALIGN_LEFT     (1)

/*******************  Bit definition for ADC_CR2 register  ********************/
#define ADC_CR2_ADON_Pos                    (0U)                               
#define ADC_CR2_ADON_Msk                    (0x1UL << ADC_CR2_ADON_Pos)         /*!< 0x00000001 */
#define ADC_CR2_ADON                        ADC_CR2_ADON_Msk                   /*!< ADC enable */
#define ADC_CR2_CONT_Pos                    (1U)                               
#define ADC_CR2_CONT_Msk                    (0x1UL << ADC_CR2_CONT_Pos)         /*!< 0x00000002 */
#define ADC_CR2_CONT                        ADC_CR2_CONT_Msk                   /*!< ADC group regular continuous conversion mode */
#define ADC_CR2_CAL_Pos                     (2U)                               
#define ADC_CR2_CAL_Msk                     (0x1UL << ADC_CR2_CAL_Pos)          /*!< 0x00000004 */
#define ADC_CR2_CAL                         ADC_CR2_CAL_Msk                    /*!< ADC calibration start */
#define ADC_CR2_RSTCAL_Pos                  (3U)                               
#define ADC_CR2_RSTCAL_Msk                  (0x1UL << ADC_CR2_RSTCAL_Pos)       /*!< 0x00000008 */
#define ADC_CR2_RSTCAL                      ADC_CR2_RSTCAL_Msk                 /*!< ADC calibration reset */
#define ADC_CR2_DMA_Pos                     (8U)                               
#define ADC_CR2_DMA_Msk                     (0x1UL << ADC_CR2_DMA_Pos)          /*!< 0x00000100 */
#define ADC_CR2_DMA                         ADC_CR2_DMA_Msk                    /*!< ADC DMA transfer enable */
#define ADC_CR2_ALIGN_Pos                   (11U)                              
#define ADC_CR2_ALIGN_Msk                   (0x1UL << ADC_CR2_ALIGN_Pos)        /*!< 0x00000800 */
#define ADC_CR2_ALIGN                       ADC_CR2_ALIGN_Msk                  /*!< ADC data alignment */

#define ADC_CR2_JEXTSEL_Pos                 (12U)                              
#define ADC_CR2_JEXTSEL_Msk                 (0x7UL << ADC_CR2_JEXTSEL_Pos)      /*!< 0x00007000 */
#define ADC_CR2_JEXTSEL                     ADC_CR2_JEXTSEL_Msk                /*!< ADC group injected external trigger source */
#define ADC_CR2_JEXTSEL_0                   (0x1UL << ADC_CR2_JEXTSEL_Pos)      /*!< 0x00001000 */
#define ADC_CR2_JEXTSEL_1                   (0x2UL << ADC_CR2_JEXTSEL_Pos)      /*!< 0x00002000 */
#define ADC_CR2_JEXTSEL_2                   (0x4UL << ADC_CR2_JEXTSEL_Pos)      /*!< 0x00004000 */

#define ADC_CR2_JEXTTRIG_Pos                (15U)                              
#define ADC_CR2_JEXTTRIG_Msk                (0x1UL << ADC_CR2_JEXTTRIG_Pos)     /*!< 0x00008000 */
#define ADC_CR2_JEXTTRIG                    ADC_CR2_JEXTTRIG_Msk               /*!< ADC group injected external trigger enable */

#define ADC_CR2_EXTSEL_Pos                  (17U)                              
#define ADC_CR2_EXTSEL_Msk                  (0x7UL << ADC_CR2_EXTSEL_Pos)       /*!< 0x000E0000 */
#define ADC_CR2_EXTSEL                      ADC_CR2_EXTSEL_Msk                 /*!< ADC group regular external trigger source */
#define ADC_CR2_EXTSEL_0                    (0x1UL << ADC_CR2_EXTSEL_Pos)       /*!< 0x00020000 */
#define ADC_CR2_EXTSEL_1                    (0x2UL << ADC_CR2_EXTSEL_Pos)       /*!< 0x00040000 */
#define ADC_CR2_EXTSEL_2                    (0x4UL << ADC_CR2_EXTSEL_Pos)       /*!< 0x00080000 */

#define ADC_CR2_EXTTRIG_Pos                 (20U)                              
#define ADC_CR2_EXTTRIG_Msk                 (0x1UL << ADC_CR2_EXTTRIG_Pos)      /*!< 0x00100000 */
#define ADC_CR2_EXTTRIG                     ADC_CR2_EXTTRIG_Msk                /*!< ADC group regular external trigger enable */
#define ADC_CR2_JSWSTART_Pos                (21U)                              
#define ADC_CR2_JSWSTART_Msk                (0x1UL << ADC_CR2_JSWSTART_Pos)     /*!< 0x00200000 */
#define ADC_CR2_JSWSTART                    ADC_CR2_JSWSTART_Msk               /*!< ADC group injected conversion start */
#define ADC_CR2_SWSTART_Pos                 (22U)                              
#define ADC_CR2_SWSTART_Msk                 (0x1UL << ADC_CR2_SWSTART_Pos)      /*!< 0x00400000 */
#define ADC_CR2_SWSTART                     ADC_CR2_SWSTART_Msk                /*!< ADC group regular conversion start */
#define ADC_CR2_TSVREFE_Pos                 (23U)                              
#define ADC_CR2_TSVREFE_Msk                 (0x1UL << ADC_CR2_TSVREFE_Pos)      /*!< 0x00800000 */
#define ADC_CR2_TSVREFE                     ADC_CR2_TSVREFE_Msk                /*!< ADC internal path to VrefInt and temperature sensor enable */


typedef struct
{
    unsigned char Sequence[ADC_SEQUENCE_LENGTH];
}Adc_Config_t;

/*     Global Variables     */
extern const Adc_Config_t Adc_Config;

/*    Function Prototypes     */
void Adc_Init(const Adc_Config_t *config);

#endif
