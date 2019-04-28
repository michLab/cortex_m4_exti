/*
 * bb.h
 *
 *  Created on: 7 mar 2017
 *      Author: doktorant
 *      Comment: makro do wyznaczania adresu aliasu w metodzie bit banding. Dołącz st32f4xx.h przed tym plikiem!
 */

#ifndef BB_H_
#define BB_H_

#define PERIPH_END           ((uint32_t)0x400FFFFF) /*!< Peripheral end address in the alias region */

#define PERIPH_ADR_COND(adres)	( (uint32_t)&adres >= PERIPH_BASE && (uint32_t)&adres <= PERIPH_END )
#define BB_PERIPH(adres, bit)	( PERIPH_BB_BASE + ((uint32_t)&adres - PERIPH_BASE)*32u \
		+ (uint32_t)(__builtin_ctz(bit))*4u )
#define BB(adres, bit) *(__IO uint32_t *)( PERIPH_ADR_COND(adres) ? BB_PERIPH(adres, bit) : 0 )


#endif /* BB_H_ */
