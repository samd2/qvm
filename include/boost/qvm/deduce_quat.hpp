//Copyright (c) 2008-2016 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_QVM_435FA7E8196311E0A176DE6BDFD72085
#define BOOST_QVM_435FA7E8196311E0A176DE6BDFD72085

#include <boost/qvm/deduce_scalar.hpp>
#include <boost/qvm/quat_traits.hpp>
#include <boost/qvm/static_assert.hpp>

namespace
boost
    {
    namespace
    qvm
        {
        template <class T>
        struct quat;

        template <class Q>
        struct
        deduce_quat
            {
            BOOST_QVM_STATIC_ASSERT(is_quat<Q>::value);
            typedef Q type;
            };

        namespace
        qvm_detail
            {
            template <class A,class B,
                bool QA=is_quat<A>::value,
                bool QB=is_quat<B>::value,
                class SA=typename scalar<A>::type,
                class SB=typename scalar<B>::type,
                class SR=typename deduce_scalar<typename scalar<A>::type,typename scalar<B>::type>::type>
            struct
            deduce_q2_default
                {
                typedef quat<SR> type;
                };

            template <class Q,class S>
            struct
            deduce_q2_default<Q,Q,true,true,S,S,S>
                {
                typedef Q type;
                };

            template <class Q,class S,class SV>
            struct
            deduce_q2_default<Q,S,true,false,SV,S,SV>
                {
                typedef Q type;
                };

            template <class S,class Q,class SV>
            struct
            deduce_q2_default<S,Q,false,true,S,SV,SV>
                {
                typedef Q type;
                };
            }

        template <class A,class B>
        struct
        deduce_quat2
            {
            BOOST_QVM_STATIC_ASSERT(is_quat<A>::value || is_quat<B>::value);
            typedef typename qvm_detail::deduce_q2_default<A,B>::type type;
            };
        }
    }

#endif
