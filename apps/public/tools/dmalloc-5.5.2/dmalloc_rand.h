/*
 * Defines for the internal random number generator
 *
 * Copyright 2000 by Gray Watson
 *
 * This file is part of the dmalloc package.
 *
 * Permission to use, copy, modify, and distribute this software for
 * any purpose and without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies, and that the name of Gray Watson not be used in advertising
 * or publicity pertaining to distribution of the document or software
 * without specific, written prior permission.
 *
 * Gray Watson makes no representations about the suitability of the
 * software described herein for any purpose.  It is provided "as is"
 * without express or implied warranty.
 *
 * The author may be contacted via http://dmalloc.com/
 *
 * $Id: //BBN_Linux/Branch/Branch_for_Rel_SDK_CUCTC_General_20151029/tclinux_phoenix/apps/public/tools/dmalloc-5.5.2/dmalloc_rand.h#1 $
 */

#ifndef __DMALLOC_RAND_H__
#define __DMALLOC_RAND_H__

/*<<<<<<<<<<  The below prototypes are auto-generated by fillproto */

/*
 * static void _dmalloc_srand
 *
 * DESCRIPTION:
 *
 * Seed the random number generator with the user argument.
 *
 * RETURNS:
 *
 * None.
 *
 * ARGUMENTS:
 *
 * seed -> Value to seed the algorithm with.
 */
extern
void	_dmalloc_srand(const long seed);

/*
 * static long _dmalloc_rand
 *
 * DESCRIPTION:
 *
 * Get a pseudo-random number from the random algorithm.
 *
 * RETURNS:
 *
 * Random number.
 *
 * ARGUMENTS:
 *
 * None.
 */
extern
long	_dmalloc_rand(void);

/*<<<<<<<<<<   This is end of the auto-generated output from fillproto. */

#endif /* ! __DMALLOC_RAND_H__ */
