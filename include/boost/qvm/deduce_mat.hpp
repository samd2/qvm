//Copyright (c) 2008-2016 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_QVM_C5DC682E196211E0A4C1686BDFD72085
#define BOOST_QVM_C5DC682E196211E0A4C1686BDFD72085

#include <boost/qvm/deduce_scalar.hpp>
#include <boost/qvm/mat_traits.hpp>
#include <boost/qvm/static_assert.hpp>

namespace
boost
    {
    namespace
    qvm
        {
        template <class T,int Rows,int Cols>
        struct mat;

        namespace
        qvm_detail
            {
            template <class M,int R,int C,
                int MR=mat_traits<M>::rows,
                int MC=mat_traits<M>::cols>
            struct
            deduce_mat_default
                {
                BOOST_QVM_STATIC_ASSERT(is_mat<M>::value);
                typedef mat<typename mat_traits<M>::scalar_type,R,C> type;
                };

            template <class M,int R,int C>
            struct
            deduce_mat_default<M,R,C,R,C>
                {
                BOOST_QVM_STATIC_ASSERT(is_mat<M>::value);
                typedef M type;
                };
            }

        template <class Type,int Rows=mat_traits<Type>::rows,int Cols=mat_traits<Type>::cols>
        struct
        deduce_mat
            {
            BOOST_QVM_STATIC_ASSERT(is_mat<Type>::value);
            typedef typename qvm_detail::deduce_mat_default<Type,Rows,Cols>::type type;
            };

        namespace
        qvm_detail
            {
            template <class A,class B,int R,int C,
                bool VA=is_mat<A>::value,
                bool VB=is_mat<B>::value,
                class SA=typename scalar<A>::type,
                class SB=typename scalar<B>::type,
                class SR=typename deduce_scalar<typename scalar<A>::type,typename scalar<B>::type>::type>
            struct
            deduce_m2_default
                {
                typedef mat<SR,R,C> type;
                };

            template <class M,int R,int C,class S>
            struct
            deduce_m2_default<M,M,R,C,true,true,S,S,S>
                {
                typedef M type;
                };

            template <class M,class S,int R,int C,class SV>
            struct
            deduce_m2_default<M,S,R,C,true,false,SV,S,SV>
                {
                typedef M type;
                };

            template <class S,class M,int R,int C,class SV>
            struct
            deduce_m2_default<S,M,R,C,false,true,S,SV,SV>
                {
                typedef M type;
                };
            }

        template <class A,class B,int R,int C>
        struct
        deduce_mat2
            {
            BOOST_QVM_STATIC_ASSERT(is_mat<A>::value || is_mat<B>::value);
            typedef typename qvm_detail::deduce_m2_default<A,B,R,C>::type type;
            };
        }
    }

#endif
