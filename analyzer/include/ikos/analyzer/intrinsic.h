/**************************************************************************/ /**
 *
 * \file
 * \brief ikos intrinsics definitions
 *
 * Include this header in an analyzed code to define ikos intrinsics, such as
 * __ikos_assert(), __ikos_assume(), etc.
 *
 * Author: Maxime Arthaud
 *
 * Contact: ikos@lists.nasa.gov
 *
 * Notices:
 *
 * Copyright (c) 2018 United States Government as represented by the
 * Administrator of the National Aeronautics and Space Administration.
 * All Rights Reserved.
 *
 * Disclaimers:
 *
 * No Warranty: THE SUBJECT SOFTWARE IS PROVIDED "AS IS" WITHOUT ANY WARRANTY OF
 * ANY KIND, EITHER EXPRESSED, IMPLIED, OR STATUTORY, INCLUDING, BUT NOT LIMITED
 * TO, ANY WARRANTY THAT THE SUBJECT SOFTWARE WILL CONFORM TO SPECIFICATIONS,
 * ANY IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE,
 * OR FREEDOM FROM INFRINGEMENT, ANY WARRANTY THAT THE SUBJECT SOFTWARE WILL BE
 * ERROR FREE, OR ANY WARRANTY THAT DOCUMENTATION, IF PROVIDED, WILL CONFORM TO
 * THE SUBJECT SOFTWARE. THIS AGREEMENT DOES NOT, IN ANY MANNER, CONSTITUTE AN
 * ENDORSEMENT BY GOVERNMENT AGENCY OR ANY PRIOR RECIPIENT OF ANY RESULTS,
 * RESULTING DESIGNS, HARDWARE, SOFTWARE PRODUCTS OR ANY OTHER APPLICATIONS
 * RESULTING FROM USE OF THE SUBJECT SOFTWARE.  FURTHER, GOVERNMENT AGENCY
 * DISCLAIMS ALL WARRANTIES AND LIABILITIES REGARDING THIRD-PARTY SOFTWARE,
 * IF PRESENT IN THE ORIGINAL SOFTWARE, AND DISTRIBUTES IT "AS IS."
 *
 * Waiver and Indemnity:  RECIPIENT AGREES TO WAIVE ANY AND ALL CLAIMS AGAINST
 * THE UNITED STATES GOVERNMENT, ITS CONTRACTORS AND SUBCONTRACTORS, AS WELL
 * AS ANY PRIOR RECIPIENT.  IF RECIPIENT'S USE OF THE SUBJECT SOFTWARE RESULTS
 * IN ANY LIABILITIES, DEMANDS, DAMAGES, EXPENSES OR LOSSES ARISING FROM SUCH
 * USE, INCLUDING ANY DAMAGES FROM PRODUCTS BASED ON, OR RESULTING FROM,
 * RECIPIENT'S USE OF THE SUBJECT SOFTWARE, RECIPIENT SHALL INDEMNIFY AND HOLD
 * HARMLESS THE UNITED STATES GOVERNMENT, ITS CONTRACTORS AND SUBCONTRACTORS,
 * AS WELL AS ANY PRIOR RECIPIENT, TO THE EXTENT PERMITTED BY LAW.
 * RECIPIENT'S SOLE REMEDY FOR ANY SUCH MATTER SHALL BE THE IMMEDIATE,
 * UNILATERAL TERMINATION OF THIS AGREEMENT.
 *
 ******************************************************************************/

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
#define IKOS_NOEXCEPT noexcept
#else
#define IKOS_NOEXCEPT
#endif

/// \brief Test the given condition
///
/// The assertion prover (ikos -a prover) will try to prove that the condition
/// always holds.
extern void __ikos_assert(int condition) IKOS_NOEXCEPT;

/// \macro __ikos_assume
///
/// Assume that the given condition always holds.
#define __ikos_assume(c) if (!(c)) { __builtin_unreachable(); }

/// \brief Return a non-deterministic signed integer
extern int __ikos_nondet_int(void) IKOS_NOEXCEPT;

/// \brief Return a non-deterministic unsigned integer
extern unsigned __ikos_nondet_uint(void) IKOS_NOEXCEPT;

/// \brief Print the invariant at the function call
///
/// The assertion prover (ikos -a prover) will print the current invariant.
extern void __ikos_print_invariant(void) IKOS_NOEXCEPT;

/// \brief Print the information on the given values at the function call
///
/// The assertion prover (ikos -a prover) will print the information on the
/// given values at the function call location.
///
/// \param desc Description, for debugging purpose
///
/// \code{.c}
/// __ikos_print_values("x", x);
/// \endcode
extern void __ikos_print_values(const char* desc, ...) IKOS_NOEXCEPT;

#undef IKOS_NOEXCEPT

#ifdef __cplusplus
}
#endif