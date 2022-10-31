/*
 * Thread attributes functions
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

#if !defined( _LIBCTHREADS_THREAD_ATTRIBUTES_H )
#define _LIBCTHREADS_THREAD_ATTRIBUTES_H

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

typedef struct libcthreads_internal_thread_attributes libcthreads_internal_thread_attributes_t;

struct libcthreads_internal_thread_attributes
{
#if defined( WINAPI )
	/* The security attributes
	 */
	SECURITY_ATTRIBUTES security_attributes;

#elif defined( HAVE_PTHREAD_H )
	/* The attributes
	 */
	pthread_attr_t attributes;

#else
#error Missing thread attributes type
#endif
};

LIBCTHREADS_EXTERN \
int libcthreads_thread_attributes_initialize(
     libcthreads_thread_attributes_t **thread_attributes,
     libcerror_error_t **error );

LIBCTHREADS_EXTERN \
int libcthreads_thread_attributes_free(
     libcthreads_thread_attributes_t **thread_attributes,
     libcerror_error_t **error );

#endif /* !defined( HAVE_LOCAL_LIBCTHREADS ) || defined( HAVE_MULTI_THREAD_SUPPORT ) */

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBCTHREADS_THREAD_ATTRIBUTES_H ) */

