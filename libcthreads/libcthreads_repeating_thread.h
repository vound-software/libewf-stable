/*
 * Repeating thread functions
 *
 * Copyright (C) 2012-2020, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#if !defined( _LIBCTHREADS_INTERNAL_REPEATING_THREAD_H )
#define _LIBCTHREADS_INTERNAL_REPEATING_THREAD_H

#include <common.h>
#include <types.h>

#if defined( HAVE_PTHREAD_H ) && !defined( WINAPI )
#include <pthread.h>
#endif

#include "libcthreads_extern.h"
#include "libcthreads_libcerror.h"
#include "libcthreads_types.h"

#if defined( __cplusplus )
extern "C" {
#endif

#if !defined( HAVE_LOCAL_LIBCTHREADS ) || defined( HAVE_MULTI_THREAD_SUPPORT )

typedef struct libcthreads_internal_repeating_thread libcthreads_internal_repeating_thread_t;

struct libcthreads_internal_repeating_thread
{
#if defined( WINAPI )
	/* The thread handle
	 */
	HANDLE thread_handle;

	/* The thread identifier
	 */
	DWORD thread_identifier;

#elif defined( HAVE_PTHREAD_H )
	/* The thread
	 */
	pthread_t thread;
#else
#error Missing thread type
#endif

	/* The start function
	 */
	int (*start_function)(
	       void *arguments );

	/* The start function arguments
	 */
	void *start_function_arguments;

	/* The start functions return value
	 */
	int start_function_result;

	/* The condition mutex
	 */
	libcthreads_mutex_t *condition_mutex;

	/* The status condition
	 */
	libcthreads_condition_t *status_condition;

	/* The status
	 */
	uint8_t status;
};

LIBCTHREADS_EXTERN \
int libcthreads_repeating_thread_create(
     libcthreads_repeating_thread_t **repeating_thread,
     const libcthreads_thread_attributes_t *thread_attributes,
     int (*start_function)(
            void *arguments ),
     void *start_function_arguments,
     libcerror_error_t **error );

LIBCTHREADS_EXTERN \
int libcthreads_repeating_thread_push(
     libcthreads_repeating_thread_t *repeating_thread,
     libcerror_error_t **error );

LIBCTHREADS_EXTERN \
int libcthreads_repeating_thread_join(
     libcthreads_repeating_thread_t **repeating_thread,
     libcerror_error_t **error );

#endif /* !defined( HAVE_LOCAL_LIBCTHREADS ) || defined( HAVE_MULTI_THREAD_SUPPORT ) */

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBCTHREADS_INTERNAL_REPEATING_THREAD_H ) */

