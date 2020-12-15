//Copyright (c) 2008-2016 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifdef BOOST_QVM_TEST_SINGLE_HEADER
#   include <boost/qvm.hpp>
#else
#   include <boost/qvm/vec_traits.hpp>
#   include <boost/qvm/swizzle4.hpp>
#endif

#include <boost/core/lightweight_test.hpp>

template <int D> struct my_vec { };
int called=0;

namespace
boost
    {
    namespace
    qvm
        {
        void
        XXXX(...)
            {
            BOOST_TEST(0);
            }
        void
        XXXY(...)
            {
            ++called;
            }
        template <int D>
        struct
        vec_traits< my_vec<D> >
            {
            typedef int scalar_type;
            static int const dim=D;
            template <int I> static int read_element( my_vec<D> const & );
            template <int I> static int & write_element( my_vec<D> & );
            };
        }
    }

int
main()
    {
    using namespace boost::qvm;
    XXXX(my_vec<1>());
    XXXY(my_vec<1>());
    BOOST_TEST(called==1);
    return boost::report_errors();
    }
